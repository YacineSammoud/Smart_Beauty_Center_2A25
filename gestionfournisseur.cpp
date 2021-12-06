#include "gestionfournisseur.h"
#include <QMessageBox>
#include "mainwindow.h"
#include <QString>
#include <QtDebug>

gestionFOURNISSEUR::gestionFOURNISSEUR()
{
ID_f=0;nom="";H_TRAVAIL="";PRIX_A=0;PRIX_V=0;QP=0;
}

gestionFOURNISSEUR::gestionFOURNISSEUR(int id, QString nom,QString H_TRAVAIL,float PRIX_A,float PRIX_V,float QP)

{
    this->ID_f=id;
    this->nom=nom;
    this->H_TRAVAIL=H_TRAVAIL;
    this->PRIX_A=PRIX_A;
    this->PRIX_V=PRIX_V;
    this->QP=QP;
}

bool gestionFOURNISSEUR::ajouter()
{
 QSqlQuery query;
 QString res=QString::number(ID_f);
 query.prepare("INSERT INTO GESTIONFOURNISSEUR(ID_f,NOM,PRIX_A,PRIX_V,H_TRAVAIL,QP)" "VALUES(:id,:nom,:PRIX_A,:PRIX_V,:H_TRAVAIL,:QP)");
query.bindValue(":id",res);
 query.bindValue(1,nom);
 query.bindValue(2,PRIX_A);
 query.bindValue(3,PRIX_V);
 query.bindValue(4,H_TRAVAIL);
 query.bindValue(5,QP);

 return query.exec();
}
