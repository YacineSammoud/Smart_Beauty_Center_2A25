#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QMessageBox>
#include<QApplication>

class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void closeConnection();
};

#endif // CONNECTION_H
