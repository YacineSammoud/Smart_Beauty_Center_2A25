#include "rendezvous.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Rendezvous::Rendezvous()
{

}


Rendezvous::Rendezvous(int id , QString service , QString dates , QString heure_d)
{
 this->id=id;
 this->service=service;
 this->dates=dates;
 this->heure_d=heure_d;

}

QString Rendezvous::getservice(){return service;}
QString Rendezvous::getdate(){return dates;}
QString Rendezvous::getheure_d(){return heure_d;}
    int Rendezvous::getid(){return id;}

void Rendezvous::setservice(QString service){this->service=service;}
void Rendezvous::setdate(QString dates){this->dates=dates;}
void Rendezvous::setheure_d(QString heure_d){this->heure_d=heure_d;}
void Rendezvous::setid(int id){this->id=id;}


bool Rendezvous::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO RENDEZVOUS (id,service,dates,heure_d) VALUES (:id,:service,:dates,:heure_d)");
    QString res= QString::number(id);
    query.bindValue(":id",res);
    query.bindValue(":service",service);
    query.bindValue(":date",dates);
    query.bindValue(":heure_d",heure_d);

    return query.exec();


}


QSqlQueryModel * Rendezvous::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from RENDEZVOUS ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("dates"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("service"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("heure_d"));

    return model ;


}


bool Rendezvous::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM RENDEZVOUS where id=:id");
    QString res= QString::number(id);
    query.bindValue(":id",res);
    return query.exec();
}


 bool Rendezvous::modifier()
 {
     QSqlQuery query;
     query.prepare("UPDATE RENDEZVOUS SET id=:id,service=:service,dates=:dates,heure_d=:heure_d WHERE id=:id");
     QString res= QString::number(id);
     query.bindValue(":id", id );
     query.bindValue(":service",service);
     query.bindValue(":dates",dates);
     query.bindValue(":heure_d",heure_d);
     return query.exec();


 }

/*
 QSqlQueryModel * Rendezvous::chercherid(const QString &type)
 {
   QSqlQueryModel * model = new QSqlQueryModel();
 model->setQuery("select * from Rendezvous where id like '"+type+"%'");
 model->setHeaderData(0,Qt::Horizontal,"id");
 model->setHeaderData(1,Qt::Horizontal,"service");
 model->setHeaderData(2,Qt::Horizontal,"dates");

 return model;

 }
 QSqlQueryModel * Rendezvous::chercherservice(const QString &type)
 {
   QSqlQueryModel * model = new QSqlQueryModel();
 model->setQuery("select * from Rendezvous where service like '"+type+"%'");
 model->setHeaderData(0,Qt::Horizontal,"id");
 model->setHeaderData(1,Qt::Horizontal,"service");
 model->setHeaderData(2,Qt::Horizontal,"dates");

 return model;

 }
 QSqlQueryModel * Rendezvous::chercherdate(const QString &type)
 {
   QSqlQueryModel * model = new QSqlQueryModel();
 model->setQuery("select * from Rendezvous where dates like '"+type+"%'");
 model->setHeaderData(0,Qt::Horizontal,"id");
 model->setHeaderData(1,Qt::Horizontal,"service");
 model->setHeaderData(2,Qt::Horizontal,"dates");

 return model;

 }

*/
 QSqlQueryModel * Rendezvous::trier_id()
 {
     QSqlQueryModel *model = new QSqlQueryModel();
         model->setQuery("SELECT * from Rendezvous ORDER BY id");
         model->setHeaderData(0,Qt::Horizontal,"id");
         model->setHeaderData(1,Qt::Horizontal,"service");
         model->setHeaderData(2,Qt::Horizontal,"dates");
         model->setHeaderData(3,Qt::Horizontal,"heure_d");

         return model ;
 }
 QSqlQueryModel * Rendezvous::trier_service()
 {
     QSqlQueryModel *model = new QSqlQueryModel();
         model->setQuery("SELECT * from Rendezvous ORDER BY service");
         model->setHeaderData(0,Qt::Horizontal,"id");
         model->setHeaderData(1,Qt::Horizontal,"dates");
         model->setHeaderData(2,Qt::Horizontal,"service");
         model->setHeaderData(3,Qt::Horizontal,"heure_d");
         return model ;
 }
 QSqlQueryModel * Rendezvous::trier_heure_d()
 {
     QSqlQueryModel *model = new QSqlQueryModel();
         model->setQuery("SELECT * from Rendezvous ORDER BY heure_d");
         model->setHeaderData(0,Qt::Horizontal,"id");
         model->setHeaderData(1,Qt::Horizontal,"service");
         model->setHeaderData(2,Qt::Horizontal,"dates");
         model->setHeaderData(3,Qt::Horizontal,"heure_d");

         return model ;
 }


 QSqlQueryModel* Rendezvous::Recherche(QString recherche)
  {
      QSqlQueryModel * model= new QSqlQueryModel();
      model->setQuery("SELECT * FROM rendezvous WHERE id LIKE '"+recherche+"%' OR service LIKE '"+recherche+"%' OR heure_d LIKE '"+recherche+"%'");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("dates"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("service"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("heure_d"));


 return model;
 }
