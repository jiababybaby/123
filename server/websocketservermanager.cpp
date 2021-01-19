#include "websocketservermanager.h"
#include <QDebug>
#include <QWebSocket>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QNetworkReply>
WebSocketServerManager::WebSocketServerManager(QString serverName,
                                               QWebSocketServer::SslMode secureMode,
                                               QObject *parent)
    : QObject(parent),
      _serverName(serverName),
      _sslMode(secureMode),
      _running(false),
      _pWebSocketServer(0)
{
}

WebSocketServerManager::~WebSocketServerManager()
{
    if(_pWebSocketServer != 0)
    {
        qDebug()<<"delete ws";
        _pWebSocketServer->deleteLater();
        _pWebSocketServer = 0;
    }
}

bool WebSocketServerManager::running() const
{
    return _running;
}

void WebSocketServerManager::slot_start(QHostAddress hostAddress, qint32 port)
{
    if(_running)
    {
        qDebug() << __FILE__ << __LINE__
                 << "Failed to" << __FUNCTION__ << "it's already running...";
        return;
    }
    if(!_pWebSocketServer)
    {
        _pWebSocketServer = new QWebSocketServer(_serverName, _sslMode, 0);
        connect(_pWebSocketServer, SIGNAL(newConnection()), this, SLOT(slot_newConnection()));
        connect(_pWebSocketServer, SIGNAL(closed()), this, SLOT(slot_closed()));
        connect(_pWebSocketServer, SIGNAL(serverError(QWebSocketProtocol::CloseCode)),
                this             , SLOT(slot_serverError(QWebSocketProtocol::CloseCode)));
    }
    _listenHostAddress = hostAddress;
    _listenPort = port;
    _pWebSocketServer->listen(_listenHostAddress, _listenPort);
    _running = true;
    qDebug()<<_listenHostAddress<<_listenPort;

}

void WebSocketServerManager::slot_stop()
{
    if(!_running)
    {
        qDebug() << __FILE__ << __LINE__
                 << "Failed to" << __FUNCTION__
                 << ", it's not running...";
        return;
    }
    _running = false;
    _pWebSocketServer->close();
}

void WebSocketServerManager::slot_sendData(QString ip, qint32 port, QString message)
{
    QString key = QString("%1-%2").arg(ip).arg(port);
    if(_hashIpPort2PWebSocket.contains(key))
    {
        _hashIpPort2PWebSocket.value(key)->sendTextMessage(message);
    }
}

void WebSocketServerManager::slot_newConnection()
{
    QWebSocket *pWebSocket = _pWebSocketServer->nextPendingConnection();
    connect(pWebSocket, SIGNAL(disconnected()), this, SLOT(slot_disconnected()));
    connect(pWebSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this      , SLOT(slot_error(QAbstractSocket::SocketError)));
    // 既会触发frame接收也会触发message接收
//    connect(pWebSocket, SIGNAL(textFrameReceived(QString,bool)),
//            this      , SLOT(slot_textFrameReceived(QString,bool)));
    connect(pWebSocket, SIGNAL(textMessageReceived(QString)),
            this      , SLOT(slot_textMessageReceived(QString)));
    _hashIpPort2PWebSocket.insert(QString("%1-%2").arg(pWebSocket->peerAddress().toString())
                                  .arg(pWebSocket->peerPort()),
                                  pWebSocket);
    qDebug() << __FILE__ << __LINE__ << pWebSocket->peerAddress().toString() << pWebSocket->peerPort();
    emit signal_conncted(pWebSocket->peerAddress().toString(), pWebSocket->peerPort());


}

void WebSocketServerManager::slot_serverError(QWebSocketProtocol::CloseCode closeCode)
{
    QWebSocket *pWebSocket = dynamic_cast<QWebSocket *>(sender());
    if(!pWebSocket)
    {
        return;
    }
    emit signal_error(pWebSocket->peerAddress().toString(), pWebSocket->peerPort(), _pWebSocketServer->errorString());
}

void WebSocketServerManager::slot_closed()
{
    QList<QWebSocket *> _listWebSocket = _hashIpPort2PWebSocket.values();
    for(int index = 0; index < _listWebSocket.size(); index++)
    {
        _listWebSocket.at(index)->close();
    }
    _hashIpPort2PWebSocket.clear();
    emit signal_close();
}

void WebSocketServerManager::slot_disconnected()
{
    qDebug() << __FILE__ << __LINE__ << __FUNCTION__;
    QWebSocket *pWebSocket = dynamic_cast<QWebSocket *>(sender());
    if(!pWebSocket)
    {
        return;
    }
    qDebug() << __FILE__ << __LINE__ << __FUNCTION__;
    emit signal_disconncted(pWebSocket->peerAddress().toString(), pWebSocket->peerPort());
    _hashIpPort2PWebSocket.remove(QString("%1-%2").arg(pWebSocket->peerAddress().toString())
                                                  .arg(pWebSocket->peerPort()));
}

void WebSocketServerManager::slot_error(QAbstractSocket::SocketError error)
{
    QWebSocket *pWebSocket = dynamic_cast<QWebSocket *>(sender());
    if(!pWebSocket)
    {
        return;
    }
    emit signal_error(pWebSocket->peerAddress().toString(), pWebSocket->peerPort(), pWebSocket->errorString());
}

void WebSocketServerManager::slot_textFrameReceived(const QString &frame, bool isLastFrame)
{
    QWebSocket *pWebSocket = dynamic_cast<QWebSocket *>(sender());
    if(!pWebSocket)
    {
        return;
    }
    qDebug() << __FILE__ << __LINE__ << frame << isLastFrame;
    emit signal_textFrameReceived(pWebSocket->peerAddress().toString(), pWebSocket->peerPort(), frame, isLastFrame);
}

void WebSocketServerManager::slot_textMessageReceived(const QString &message)
{
    QWebSocket *pWebSocket = dynamic_cast<QWebSocket *>(sender());
    if(!pWebSocket)
    {
        return;
    }
    emit signal_textMessageReceived(pWebSocket->peerAddress().toString(), pWebSocket->peerPort(), message);
    qDebug()<<pWebSocket->peerAddress().toString()<<pWebSocket->peerPort()<<message;
    slot_sendData(pWebSocket->peerAddress().toString(),pWebSocket->peerPort(),"connect");
    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(message.toUtf8(),&parseJsonErr);
    if(!(parseJsonErr.error == QJsonParseError::NoError))
    {
       qDebug()<<tr("解析json文件错误！");
       return;
    }
    QJsonObject jsonObject = document.object();
    qDebug()<<"user[name]=="<<jsonObject["name"].toString();
    qDebug()<<"user[id]=="<<jsonObject["id"].toString();
    QString appid="wx630ac37037d318b2";
    QString secret="6d635412dd1343435a6e0997fe6b241e";
    QString id=jsonObject["id"].toString();
    QNetworkAccessManager *accessManager = new QNetworkAccessManager(this);
    connect(accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    QString url=QString("https://api.weixin.qq.com/sns/jscode2session?appid=%1&secret=%2&js_code=%3&grant_type=authorization_code").arg(appid).arg(secret).arg(id);
    accessManager->get(QNetworkRequest(QUrl(url)));
    qDebug()<<url;
}
void WebSocketServerManager::replyFinished(QNetworkReply *reply)
{
    if (reply->error()== QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        qDebug() << bytes;
        QJsonParseError parseJsonErr;
        QJsonDocument document = QJsonDocument::fromJson(bytes,&parseJsonErr);
        if(!(parseJsonErr.error == QJsonParseError::NoError))
        {
           qDebug()<<tr("解析json文件错误！");
           return;
        }
        QJsonObject jsonObject = document.object();
        qDebug()<<"user[session_key]=="<<jsonObject["session_key"].toString();
        qDebug()<<"user[openid]=="<<jsonObject["openid"].toString();
    }
    else
    {
        qDebug() << "finishedSlot errors here";
        qDebug( "found error .... code: %d\n", (int)reply->error());
        qDebug(qPrintable(reply->errorString()));
    }
}
