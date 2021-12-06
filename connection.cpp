#include "connection.h"
#include <QDebug>
Connection::Connection(){}


bool Connection::createconnect()
{

    db = QSqlDatabase::addDatabase("QODBC");
   bool test=false;
   db.setDatabaseName("test");
   db.setUserName("amine");//inserer nom de l'utilisateur
   db.setPassword("amine");//inserer mot de passe de cet utilisateur

   if (db.open())
   test=true;
   qDebug() << db.lastError();





    return  test;
}
//void Connection::closeConnection(){db.close();}
