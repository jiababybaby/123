#include <QCoreApplication>
#include "websocketservermanager.h"
#include <QDebug>
#include "mysql.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"INIT OK.";
    mysql *my_sql= new mysql;
    WebSocketServerManager *ws= new WebSocketServerManager("ws");
    QObject::connect(ws,&WebSocketServerManager::signal_add,my_sql,&mysql::mysql_add);
    //QObject::connect(ws,WebSocketServerManager::signal_textMessageReceived());
    qDebug()<<"WS INIT OK.";
    ws->slot_start(QHostAddress(QHostAddress::Any),8888);
    return a.exec();
}
