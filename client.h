#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>


using namespace std;

class client
{
    public:
        client();
        client(int ID_C,QString NOM,QString PRENOM,QString SERVICE,QString ADRESSE_MAIL);
           // ~Client();

            int getID_C();
            QString getNOM();
            QString getPRENOM();
            QString getSERVICE();
            QString getADRESSE_MAIL();
            void setID_C(int);
            void setNOM(QString);
            void setPRENOM(QString);
            void setSERVICE(QString);
            void setADRESSE_MAIL(QString);
            bool ajouter();
            QSqlQueryModel* afficher();
            bool supprimer(int);
            bool modifier(int);

    private:
        //long ID_rdv;
        QString SERVICE;
        QString PRENOM;
        QString NOM;
        QString ADRESSE_MAIL;
        int ID_C;
};

#endif // CLIENT_H
