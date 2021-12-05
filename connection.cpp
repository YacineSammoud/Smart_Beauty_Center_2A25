#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("Chiheb");// inserer nom d'utilisateur
db.setPassword("chiheb23322984");//inserer mot de passe de cet utilisateur


if (db.open())
test=true;





    return  test;
}
