#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Rendezvous
{
    QString service , date , heure_d ;
    int id;

public:
    Rendezvous(){};
    Rendezvous(int, QString , QString , QString );

    QString getservice(){return service;}
    QString getdate(){return date;}
    QString getheure_d(){return heure_d;}
    int getid(){return id;}

    void setservice(QString s){service=s;}
    void setdate(QString d){date=d;}
    void setheure_d(QString hd){heure_d=hd;}
    void setid(int id){this->id=id;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();


};

#endif // RENDEZVOUS_H
