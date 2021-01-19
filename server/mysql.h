#ifndef MYSQL_H
#define MYSQL_H

#include <QObject>
#include "QSqlDatabase"
class mysql : public QObject
{
    Q_OBJECT
public:
    explicit mysql(QObject *parent = nullptr);
    ~mysql();
    QSqlDatabase dbconn;
    QString hostName;
    QString dbName;
    QString userName;
    QString password;
signals:

public slots:
    void mysql_add(QString id,QString name,QString net_sn,QString device_sn);
};

#endif // MYSQL_H
