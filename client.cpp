#include "client.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QObject>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QPieSlice>

client::client()
{

ID_C=0;
NOM="";
PRENOM="";
SERVICE="";
ADRESSE_MAIL="";
}


client::client(int ID_C,QString NOM,QString PRENOM ,QString SERVICE ,QString ADRESSE_MAIL)
{
   this->ID_C=ID_C;
    this->NOM=NOM ;
    this->PRENOM=PRENOM;
    this->SERVICE =SERVICE;
    this->ADRESSE_MAIL=ADRESSE_MAIL;


}
//getters
int client::getID_C(){return  ID_C;}
QString client::getNOM(){return NOM;}
QString client::getPRENOM(){return PRENOM;}
QString client ::getSERVICE(){return SERVICE;}
QString client ::getADRESSE_MAIL(){return ADRESSE_MAIL;}
//setters
void client::setID_C(int ID_C)
{this->ID_C=ID_C;}

void client::setNOM(QString NOM)
{this->NOM=NOM;}

void client::setPRENOM(QString PRENOM)
{this->PRENOM=PRENOM;}

void client::setSERVICE(QString SERVICE)
{this->SERVICE=SERVICE;}

void client::setADRESSE_MAIL(QString ADRESSE_MAIL)
{this->ADRESSE_MAIL=ADRESSE_MAIL;}

bool client ::ajouter()
{
    QSqlQuery query;
    QString ID_C_string=QString::number(ID_C);
          query.prepare("INSERT INTO clients (ID_C,NOM,PRENOM,SERVICE,ADRESSE_MAIL) "
                        "VALUES (:ID_C, :NOM, :PRENOM, :SERVICE, :ADRESSE_MAIL)");
          query.bindValue(":ID_C", ID_C_string);
          query.bindValue(":NOM", NOM);
          query.bindValue(":PRENOM", PRENOM );
          query.bindValue(":SERVICE", SERVICE);
          query.bindValue(":ADRESSE_MAIL",ADRESSE_MAIL);


          return query.exec();
}

QSqlQueryModel* client::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("SELECT* FROM clients");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_C"));
         model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("SERVICE"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("ADRESSE_MAIL"));

    return  model ;
}

bool client::supprimer(int ID_C)     //
{
   QSqlQuery query;
   //QString ID_C=QString::number(ID_C);// conversion

  query.prepare("Delete from clients where ID_C = :ID_C ");
   query.bindValue(":ID_C",ID_C);
   return query.exec();
}

bool client::modifier(int ID_C)
{   QSqlQuery query;
    query.prepare( "UPDATE clients set NOM=:NOM,PRENOM=:PRENOM,SERVICE=:SERVICE,ADRESSE_MAIL=:ADRESSE_MAIL where ID_C=:ID_C");
    query.bindValue(":ID_C", ID_C);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":SERVICE", SERVICE);
    query.bindValue("ADRESSE_MAIL",ADRESSE_MAIL);

 return query.exec();
}

QSqlQueryModel* client::trier()
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM clients order by ID_C"); //ASC pour ascendant, DESC pour descendant
           q->exec();
           model->setQuery(*q);
           return model;
}

QSqlQueryModel* client::rechercherID_C(int ID_C)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from clients where ID_C like :ID_C");
    query.bindValue(":ID_C",ID_C);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_C"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SERVICE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE_MAIL"));

    return model;
}

QSqlQueryModel* client::rechercher(QString R)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    //QString ID=QString::number(ID_C);//conversion
    //query.prepare("select * from clients where ID_C like '"+ID+"' ||'%'");//like :ID_C
    query.prepare("SELECT* FROM clients WHERE ID_C like '"+R+"' ||'%' OR NOM like '"+R+"' ||'%' OR PRENOM like '"+R+"' ||'%' OR SERVICE like '"+R+"' ||'%' OR ADRESSE_MAIL like '"+R+"' ||'%'  ");
    query.bindValue(":ID_C",R);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_C"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SERVICE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE_MAIL"));


return model;

}
