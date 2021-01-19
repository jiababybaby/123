#include "mysql.h"
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
mysql::mysql(QObject *parent) : QObject(parent)
{



    hostName = "localhost";   // 主机名
    dbName = "new_schema";   // 数据库名称
    userName = "root";   // 用户名
    password = "XXXxxxx521.";   // 密码

    dbconn = QSqlDatabase::addDatabase("QMYSQL");
    dbconn.setHostName(hostName);
    dbconn.setDatabaseName(dbName);
    dbconn.setUserName(userName);
    dbconn.setPassword(password);

    qDebug("database open status: %d\n", dbconn.open());

    QSqlError error = dbconn.lastError();
    qDebug() << error.text();

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(QString("SELECT * FROM %1").arg("userinfo.userinfo"));
    int column = model->columnCount(); //获得列数
    int row = model->rowCount();    // 获得行数
    QSqlRecord record ;
    while (row>0) {
      row--;
        record = model->record(row);
       // QSqlRecord record = model->record(1); //获得一条记录
        QModelIndex index = model->index(1,1);   //获得一条记录的一个属性的值
        qDebug() << "column num is:" << column << endl
              << "row num is:" << row << endl
              <<"the second record is:" << record.value("id").toString() << record.value("name").toString() << record.value("address").toString()<< endl
              << "the data of index(1,1) is:"<< index.data().toString();
      }
    QSqlQuery query(dbconn);
//    query.exec("create table course (id int primary key, "
//    "name varchar(20), teacher varchar(20))");
    query.exec("use userinfo");
    query.exec("select table userinfo");
    query.exec("insert into userinfo values('101101010101010', 'name', 'Young','123')");
    query.exec("select * from userinfo");
    while (query.next())
    {
         qDebug() << query.value("id").toString() << query.value("name").toString() << query.value("net_sn").toString();
    }
}

mysql::~mysql(){
    dbconn.close();
}
void mysql::mysql_add(QString id,QString name,QString net_sn,QString device_sn){
    QSqlQuery query(dbconn);
//    query.exec("create table course (id int primary key, "
//    "name varchar(20), teacher varchar(20))");
    query.exec("use userinfo");
    query.exec("select table userinfo");
    query.exec(QString("insert into userinfo values('%1', '%2', '%3','%4')").arg(id).arg(name).arg(net_sn).arg(device_sn));
    query.exec("select * from userinfo");
    while (query.next())
    {
         qDebug() << query.value("id").toString() << query.value("name").toString() << query.value("net_sn").toString();
    }
}
