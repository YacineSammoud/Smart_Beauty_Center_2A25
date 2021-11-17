#include "employes.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QObject>



employes::employes()
{

id=0;nbr_heure=0;nbr_point=0;
     nom =""; prenom="";service="";
}


employes::employes(int id,QString nom,QString prenom ,QString service ,int nbr_heure,int nbr_point)
{
   this-> id=id;
    this->nbr_heure=nbr_heure ;
    this->nbr_point=nbr_point;
         this->nom =nom;
    this->prenom=prenom;
    this->service=service;

}

int employes::getid(){return  id;}
int employes::getnbr_heure(){return nbr_heure;}
int employes::getnbr_point(){return nbr_point;}
QString employes::getnom(){return nom;}
QString employes::getprenom(){return prenom;}
QString employes ::getservice(){return service;}
void employes::setid(int id){this->id=id;}
void employes::setnbr_heure(int nbr_heure){this->nbr_heure=nbr_heure;}
void employes::setnbr_point(int nbr_point){this->nbr_point=nbr_point;}
void employes::setnom(QString nom){this->nom=nom;}
void employes::setprenom(QString prenom){this->prenom=prenom;}
void employes::setservice(QString service){this->service=service;}
bool employes ::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id); //pour convertir en une chaine de caractere
    QString nbr_heure_string=QString::number(nbr_heure);
    QString nbr_point_string=QString::number(nbr_point);
          query.prepare("INSERT INTO employess ( id,nom, prenom , service , nbr_heure, nbr_point) "
                        "VALUES (:id, :nom, :prenom, :service, :nbr_heure, :nbr_point)");
          query.bindValue(":id", id_string); // faire la correspondance entre la variable et la valeure saisie
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom );
          query.bindValue(":service", service);
          query.bindValue(":nbr_heure", nbr_heure_string);
          query.bindValue(":nbr_point", nbr_point_string);


          return query.exec(); // methode qui retourne vrai ou faux
}

QSqlQueryModel* employes::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("SELECT* FROM employess");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
         model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom")); // ajouter les noms des colomnes de mon tableau
model->setHeaderData(3, Qt::Horizontal,QObject::tr("service"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("nbr_heure"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("nbr_point"));
    return  model ;
}
bool employes ::supprimer(int id)     //
{
   QSqlQuery query;
   //QString id=QString::number(id);// conversion

  query.prepare("Delete from employess where id = :id ");
   query.bindValue(":id",id); //inserer la valeure de id a supp
   return query.exec();

}

bool employes::modifier(int id)
{   QSqlQuery query;
    query.prepare( "UPDATE employess SET id=:id,nom=:nom,prenom=:prenom,service=:service,nbr_heure=:nbr_heure ,nbr_point=:nbr_point WHERE id=:id;");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":service", service);
    query.bindValue(":nbr_heure",nbr_heure);
    query.bindValue(":nbr_point", nbr_point);



 return query.exec();
}
QSqlQueryModel * employes:: trier(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from employess order by id desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("service"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("nbr_heure"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("nbr_point"));

return  model ;
}



QSqlQueryModel *employes:: trier1(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from employess order by nom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("service"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("nbr_heure"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("nbr_point"));

return  model ;
}

QSqlQueryModel *employes :: trier2()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from employess  order by prenom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("service"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("nbr_heure"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("nbr_point"));

return  model ;
}
QSqlQueryModel *employes::recherche(QString nom ){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from employess WHERE(nom='"+nom+"')");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("service"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("nbr_heure"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("nbr_point"));
return  model ;

}
QSqlQueryModel *employes::recherche1(QString prenom  ){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from employess WHERE(prenom='"+prenom+"')");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("service"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("nbr_heure"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("nbr_point"));
return  model ;

}

QSqlQueryModel *employes::recherche2(QString service ){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from employess WHERE(service='"+service+"')");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("service"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("nbr_heure"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("nbr_point"));
return  model ;

}
