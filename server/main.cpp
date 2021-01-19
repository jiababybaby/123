#include <QCoreApplication>
#include "websocketservermanager.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"INIT OK.";
    WebSocketServerManager *ws= new WebSocketServerManager("ws");
    qDebug()<<"WS INIT OK.";
    ws->slot_start(QHostAddress(QHostAddress::Any),8888);
    return a.exec();
}
