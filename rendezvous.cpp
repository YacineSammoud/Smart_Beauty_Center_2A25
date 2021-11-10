#include "rendezvous.h"

Rendezvous::Rendezvous(int id , QString service , QString date , QString heure_d)
{
 this->id=id;
 this->service=service;
 this->date=date;
 this->heure_d=heure_d;

}


bool Rendezvous::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO GERERENDEZVOUS (id,service,date,heure_d) VALUES (:id,:service,:date,:heure_d)");
    QString res= QString::number(id);
    query.bindValue(":id",res);
    query.bindValue(":service",service);
    query.bindValue(":date",date);
    query.bindValue(":heure_d",heure_d);

    return query.exec();


}


QSqlQueryModel * Rendezvous::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from GERERENDEZVOUS ");
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(2,Qt::Horizontal,"SERVICE");
    model->setHeaderData(3,Qt::Horizontal,"DATE");
    model->setHeaderData(1,Qt::Horizontal,"HEURE_D");

    return model ;


}


bool Rendezvous::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM GERERENDEZVOUS where id=:id");
    QString res= QString::number(id);
    query.bindValue(":id",res);
    return query.exec();
}


 bool modifier()
 {
     QSqlQuery query;
     query.prepare("UPDATE GERERENDEZVOUS SET id=:id,service=:service,date=:date,heure_d=:heure_d WHERE id=:id");
     QString res= QString::number(id);
     query.bindValue(":id", id )
     query.bindValue(":service",service);
     query.bindValue(":date",date);
     query.bindValue(":heure_d",heure_d);
     return query.exec();


 }

