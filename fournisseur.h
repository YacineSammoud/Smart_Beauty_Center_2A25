#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>

class fournisseur
{private:
    QString nom,ID_f,H_TRAVAIL;
    QString PRIX_A,PRIX_V,QP;


public:
    fournisseur ();
    fournisseur(QString,QString,QString,QString,QString,QString);
    QString getID_f();
    QString getnom();
    QString getH_TRAVAIL();
    QString getPRIX_A();
    QString getPRIX_V();
    QString getQP();
    void setID_f(QString);
    void setnom(QString);
    void setH_TRAVAIL(QString);
    void setPRIX_A(QString);
    void setPRIX_V(QString);
    void setQP(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
     bool modifier(QString);
     QSqlQueryModel * trier();
     QSqlQueryModel * trier1();
     QSqlQueryModel * trier2();

bool ajfichehisto(int);
void imp();

};


#endif // FOURNISSEUR_H
