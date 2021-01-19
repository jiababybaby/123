#ifndef WEBSOCKETSERVERMANAGER_H
#define WEBSOCKETSERVERMANAGER_H
#include <QObject>
#include <QWebSocketServer>
#include <QThread>
#include <QNetworkAccessManager>

#include <QObject>

class WebSocketServerManager : public QObject
{
    Q_OBJECT

public:
    explicit WebSocketServerManager(QString serverName,
                                    QWebSocketServer::SslMode secureMode = QWebSocketServer::NonSecureMode,
                                    QObject *parent = 0);
    ~WebSocketServerManager();

public:
    bool running() const;

signals:
    void signal_conncted(QString ip, qint32 port);
    void signal_disconncted(QString ip, qint32 port);
    void signal_sendTextMessageResult(QString ip, quint32 port, bool result);
    void signal_sendBinaryMessageResult(QString ip, quint32 port, bool result);
    void signal_error(QString ip, quint32 port, QString errorString);
    void signal_textFrameReceived(QString ip, quint32 port, QString frame, bool isLastFrame);
    void signal_textMessageReceived(QString ip, quint32 port,QString message);
    void signal_close();

public slots:
    void slot_start(QHostAddress hostAddress = QHostAddress(QHostAddress::Any), qint32 port = 10080);
    void slot_stop();
    void slot_sendData(QString ip, qint32 port, QString message);

protected slots:
    void slot_newConnection();
    void slot_serverError(QWebSocketProtocol::CloseCode closeCode);
    void slot_closed();

protected slots:
    void slot_disconnected();
    void slot_error(QAbstractSocket::SocketError error);
    void slot_textFrameReceived(const QString &frame, bool isLastFrame);
    void slot_textMessageReceived(const QString &message);
    void replyFinished(QNetworkReply *reply);
private:
    QString _serverName;
    QWebSocketServer::SslMode _sslMode;
    bool _running;
    QWebSocketServer *_pWebSocketServer;
    QHash<QString, QWebSocket*> _hashIpPort2PWebSocket;
    QHostAddress _listenHostAddress;
    qint32 _listenPort;
};

#endif // WEBSOCKETSERVERMANAGER_H
