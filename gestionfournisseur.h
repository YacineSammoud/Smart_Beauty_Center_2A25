#ifndef GESTIONFOURNISSEUR_H
#define GESTIONFOURNISSEUR_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>


class gestionFOURNISSEUR


{
private:
    QString nom,H_TRAVAIL;
    float PRIX_A,PRIX_V,QP;
    int ID_f;

public:
    gestionFOURNISSEUR();
     gestionFOURNISSEUR(int,QString,QString,float,float,float);
     int getID_f(){return ID_f;}
     QString getnom(){return nom;};
     QString getH_TRAVAIL(){return H_TRAVAIL;}
     float getPRIX_A(){return PRIX_A;}
     float getPRIX_V(){return PRIX_V;}
     float getQP(){return QP;}
     void setID_f(int id){this->ID_f=id;}
    void setnom(QString n){nom=n;}
    void setH_TRAVAIL(QString H){H_TRAVAIL=H;}
    void setPRIX_A(float A){PRIX_A=A;}
    void setPRIX_V(float V){PRIX_V=V;}
    void setQP(float Q){QP=Q;}
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
};







#endif // GESTIONFOURNISSEUR_H
