#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>


class employes
{
public:
    employes();
    employes(int ,QString,QString,QString,int,int);
    int getid();
    int getnbr_point();
    int getnbr_heure();
    QString getnom();
    QString getprenom();
    QString getservice();
    void setid(int);
    void setnbr_heure(int);
    void setnbr_point(int);
    void setnom(QString);
    void setprenom(QString);
    void setservice(QString);
    bool ajouter();
    QSqlQueryModel* afficher(); //le resultat  ensemble d'information d'une requete query de type sql
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel* recherche8(QString );
     QSqlQueryModel* recherche7(QString a);
QSqlQueryModel* recherche(QString );
QSqlQueryModel* recherche1(QString );
QSqlQueryModel* recherche2(QString );
QSqlQueryModel * trier();
QSqlQueryModel * trier1();
QSqlQueryModel * trier2();

private:
    int id,nbr_heure,nbr_point;
    QString nom , prenom,service;


};

#endif // EMPLOYES_H
