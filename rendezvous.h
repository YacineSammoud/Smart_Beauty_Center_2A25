#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Rendezvous
{

public:
    Rendezvous();
    Rendezvous(int, QString , QString , QString );

    QString getservice();
    QString getdate();
    QString getheure_d();
    int getid();

    void setservice(QString );
    void setdate(QString );
    void setheure_d(QString );
    void setid(int );

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();

    QSqlQueryModel * chercherservice(const QString &);
    QSqlQueryModel * chercherdate(const QString &);
    QSqlQueryModel * chercherid(const QString &);

    QSqlQueryModel *trier_service();
    QSqlQueryModel *trier_heure_d();
    QSqlQueryModel *trier_id();

    QSqlQueryModel * Recherche(QString);


private:
    QString service , dates , heure_d ;
    int id;


};

#endif // RENDEZVOUS_H
