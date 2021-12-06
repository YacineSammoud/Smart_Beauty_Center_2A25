#include "fournisseur.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"fournisseur.h"
#include <QMessageBox>
#include<QString>
#include <QSqlError>
#include<QtWidgets>
#include <QFileDialog>
#include <QtDebug>
#include <QPrinter>
#include<QPdfWriter>
#include <QFile>
#include<QMessageBox>
#include<QDesktopServices>
#include "statj.h"
#include "historique.h"
fournisseur::fournisseur()
{
ID_f="";nom="";H_TRAVAIL="";PRIX_A="";PRIX_V="";QP="";

}

fournisseur::fournisseur(QString ID_f,QString nom,QString H_TRAVAIL,QString PRIX_A,QString PRIX_V,QString QP)
{
this->ID_f=ID_f;
    this->nom=nom;
    this->H_TRAVAIL=H_TRAVAIL;
    this->PRIX_A=PRIX_A;
    this->PRIX_V=PRIX_V;
    this->QP=QP;
}
bool fournisseur::ajouter()
{
    QSqlDatabase db = QSqlDatabase::database("test");
 QSqlQuery query(db);
 query.prepare("INSERT INTO FOURNISSEUR(ID_f,NOM,PRIX_A,PRIX_V,H_TRAVAIL,QP)" "VALUES(:ID_f,:nom,:PRIX_A,:PRIX_V,:H_TRAVAIL,:QP)");
query.bindValue(":ID_f",ID_f);
 query.bindValue(":nom",nom);
 query.bindValue(":PRIX_A",PRIX_A);
 query.bindValue(":PRIX_V",PRIX_V);
 query.bindValue(":H_TRAVAIL",H_TRAVAIL);
 query.bindValue(":QP",QP);

 return query.exec();
}
QSqlQueryModel * fournisseur::afficher()


{
  QSqlQueryModel * model=new QSqlQueryModel();
  model->setQuery("select * from FOURNISSEUR");
 /* model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_f")) ;
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom")) ;
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRIX_A")) ;
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX_V")) ;
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("QP")) ;
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("H_TRAVAIL")) ;*/
  return model;
}
bool fournisseur::supprimer(QString ID)

{

    QSqlQuery query;

    query.prepare("Delete from FOURNISSEUR where ID_f=:ID_f");

    query.bindValue(":ID_f",ID);//inserer la valeur de ID_f a supp
    return query.exec();
}
bool fournisseur::modifier(QString ID_f)
{
     QSqlQuery query;


    query.prepare("UPDATE FOURNISSEUR SET ID_f=ID_f ,nom=:nom,PRIX_A=:PRIX_A,PRIX_V=:PRIX_V,H_TRAVAIL=:H_TRAVAIL,QP=:QP where ID_f=:ID_f  ");
    query.bindValue(":ID_f",ID_f);
    query.bindValue(":nom",nom);
    query.bindValue(":PRIX_A",PRIX_A);
    query.bindValue(":PRIX_V",PRIX_V);
    query.bindValue(":H_TRAVAIL",H_TRAVAIL);
    query.bindValue(":QP",QP);
    return query.exec();

}

QSqlQueryModel *fournisseur:: trier(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from fournisseur order by ID_f");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_f"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRIX_A"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("PRIX_V"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("QP"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("H_TRAVAIL"));

return  model ;
}


QSqlQueryModel *fournisseur:: trier1(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from fournisseur order by nom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_f"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRIX_A"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("PRIX_V"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("QP"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("H_TRAVAIL"));

return  model ;
}

QSqlQueryModel *fournisseur :: trier2()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from fournisseur  order by PRIX_A ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_f"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRIX_A"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("PRIX_V"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("QP"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("H_TRAVAIL"));

return  model ;
}

bool fournisseur::ajfichehisto(int id_f)
{QSqlQuery query;
    query.prepare("INSERT INTO FOURNISSEUR(ID_F,NOM,PRIX_A,PRIX_V,H_TRAVAIL,QP) SELECT ID_F,NOM,PRIX_A,PRIX_V,H_TRAVAIL,QP FROM FOURNISSEUR where ID_F= :id_f "   );

    query.bindValue(":ID_F",id_f);
    query.bindValue(":nom",nom);
    query.bindValue(":PRIX_A",PRIX_A);
    query.bindValue(":PRIX_V",PRIX_V);
    query.bindValue(":H_TRAVAIL",H_TRAVAIL);
query.bindValue(":QP",QP);


    return    query.exec();


}


