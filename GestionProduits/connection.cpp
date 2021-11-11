#include "connection.h"

connection::connection()
{

}
bool connection::createconnect()
{
    bool test=false;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Chiheb");// inserer nom d'utilisateur
    db.setPassword("chiheb23322984");//inserer mot de passe de cet utilisateur

    if(db.open())
    test=true;

    return test;

}
void connection::closeconnect(){db.close();}
