 #include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{
    db= QSqlDatabase::addDatabase("QODBC");
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A25");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("12345");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

void Connection::closeConnection(){db.close();}
