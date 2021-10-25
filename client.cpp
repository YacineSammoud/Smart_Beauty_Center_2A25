#include "client.h"

Client::Client()
{
    nom="XX";
    prenom="XX";
    adresse_email="XX";
    CIN=0;
}

Client::Client(string prenom,string nom,string service,string adresse_email,long CIN,long ID_rdv){
    this->prenom=prenom;
    this->nom=nom;
    this->service=service;
    this->adresse_email=adresse_email;
    this->CIN=CIN;
    this->ID_rdv=ID_rdv;
}

/*void Client::afficher() const{
    cout<<"Client:"<<nom<<"adresse_email"<<adresse_email<<"num cin"<<CIN<<endl;
}*/

