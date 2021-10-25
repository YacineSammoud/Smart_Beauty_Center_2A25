#ifndef CLIENT_H
#define CLIENT_H


#include <string>
#include <iostream>

using namespace std;

class Client
{
    public:
        Client();
        Client(string prenom,string nom,string service,string adresse_email,long numCIN,long ID_rdv);
            ~Client();

        string Getprenom() const {return prenom; }
        void Setprenom(string val) {prenom = val; }

        string Getnom() const {return nom; }
        void Setnom(string val) {nom = val; }

        string Getservice() const {return service; }
        void Setservice(string val) {service = val; }

        string Getadresse_email()const {return adresse_email; }
        void Setadresse_email(string val) {adresse_email = val; }

        long GetCIN() const{return CIN; }
        void SetCIN(long val) {CIN = val; }

        long GetID_rdv() const{return ID_rdv; }
        void SetID_rdv(long val) {ID_rdv = val; }

    private:
        long ID_rdv;
        string service;
        string prenom;
        string nom;
        string adresse_email;
        long CIN;
};

#endif // CLIENT_H
