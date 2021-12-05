#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QBuffer>
#include<QFile>
#include<QFileDialog>
#include<QCoreApplication>

Produit::Produit() //Constructeur par défaut
{
CodeB=0 ;
Nom="";
Stockage=0 ;
Categorie="";
Image="" ;
Prix =0;
ID_F="";
ID=0;
}
Produit::Produit(int CodeB,int Stockage,QString Nom,QString Categorie,QString Image,double Prix,QString ID_F,int ID)
{
    this->CodeB=CodeB;
    this->Stockage=Stockage;
    this->Nom=Nom;
    this->Categorie=Categorie;
    this->Image=Image;
    this->Prix=Prix;
    this->ID_F=ID_F;
    this->ID=ID;

}
int Produit::getCodeB(){return CodeB;}
int Produit::getStockage(){return Stockage;}
QString Produit::getNom(){return Nom;}
QString Produit::getCategorie(){return Categorie;}
QString Produit::getImage(){return Image;}
double Produit::getPrix(){return Prix;}
QString Produit::getFournisseurs(){return ID_F;}
int Produit::getEmployes(){return ID;}


void Produit::setCodeB(int CodeB){this->CodeB=CodeB;}
void Produit::setStockage(int Stockage){this->Stockage=Stockage;}
void Produit::setNom(QString Nom){this->Nom=Nom;}
void Produit::setCategorie(QString Categorie){this->Categorie=Categorie;}
void Produit::setImage(QString Image){this->Image=Image;}
void Produit::setPrix(double Prix){this->Prix=Prix;}
void Produit::setFournisseurs(QString ID_F){this->ID_F=ID_F;}
void Produit::setEmployes(int ID){this->ID=ID;}


bool Produit::ajouterProduits(int CodeB ,int Stockage,QString Nom,QString Categorie,QString Image,double Prix,QString ID_F,int ID)
{

verifCB(CodeB);
    QSqlQuery query;
    QString res= QString::number(CodeB);
    QString res1= QString::number(Stockage);
    QString res2= QString::number(Prix);
    QString res3= QString::number(ID);



    query.prepare("INSERT INTO PRODUITS(CODEB,PRIX,NOM,STOCKAGE,CATEGORIE,IMAGE,ID_F,ID)"
                  "VALUES (:CodeB,:Prix,:Nom,:Stockage,:Categorie,:Image,:ID_F,:ID)");

    query.bindValue(":CodeB", res);
    query.bindValue(":Prix", res2);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Stockage", res1);
    query.bindValue(":Categorie", Categorie);
    query.bindValue(":Image", Image);
    query.bindValue(":ID_F", ID_F);
    query.bindValue(":ID", res3);


    return query.exec();


}
QSqlQueryModel* Produit::afficherProduits()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM produits");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code à barre "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Stockage"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Catégorie"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Fournisseurs"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Employes"));


        return model;
}


QSqlQueryModel *Produit::rechercherProduits(int CodeB , QString Nom ,int Stockage)
{
    QString res= QString::number(CodeB);
    QString res1= QString::number(Stockage);


QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from produits where (CodeB LIKE '"+res+"%'or Nom LIKE '"+Nom+"%' or Stockage LIKE '"+res1+"%' ) ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code à barre "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Stockage"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Catégorie"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Fournisseurs"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Employes"));


    return model;
}

bool Produit::supprimerProduits(int CodeB)
{
//CBExist(CodeB);
QSqlQuery query;
QString res= QString::number(CodeB);
query.prepare("Delete from produits where CodeB = :CodeB ");
query.bindValue(":CodeB", res);
return    query.exec();
}

bool Produit::modifierProduits(int CodeB)
{

    QSqlQuery query;
    QString res= QString::number(CodeB);
    QString res1= QString::number(Stockage);
    QString res2= QString::number(Prix);
    QString res3= QString::number(ID);

    query.prepare("UPDATE  produits set Prix=:Prix,Nom=:Nom,Stockage=:Stockage,Categorie=:Categorie,Image=:Image,ID_F=:ID_F,ID=:ID where CodeB=:CodeB");

    query.bindValue(":CodeB", res);
    query.bindValue(":Prix", res2);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Stockage", res1);
    query.bindValue(":Categorie", Categorie);
    query.bindValue(":Image", Image);
    query.bindValue(":ID_F", ID_F);
    query.bindValue(":ID", res3);




    return    query.exec();


}


void Produit::stat()
{
    QSqlQuery query ;

    query.exec("SELECT * from produits where categorie LIKE 'Soins visage'");
    int i = 0 ;

    QBarSet *set0 = new QBarSet("Nombre De Produit Par Categories");
    while (query.next()) {
        i++ ;
    }
    *set0 << i ;

    query.exec("SELECT * from produits where categorie LIKE 'Maquillage'");
    i = 0 ;
    while (query.next()) {
        i++ ;
    }
    *set0 << i ;

    query.exec("SELECT * from produits where categorie LIKE 'Soins corps'");
    i = 0 ;
    while (query.next()) {
        i++ ;
    }
    *set0 << i ;

    query.exec("SELECT * from produits where categorie LIKE 'Coloration cheveux'");
    i = 0 ;
    while (query.next()) {
        i++ ;
    }
    *set0 << i ;

    //*set0 << 900 << 1100 << 1000 << 1500 << 1600 ;
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques Des Produits");
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList categories;
    categories << "Soins visage" << "Maquillage" << "Soins corps" << "Coloration cheveux";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setWindowTitle("Statistique");
    chartView->resize(1000, 500);
    chartView->show();
}

void Produit::verifCB(int CB)
{
    if( CB > 99999999 )
        throw QString("Code à barre est Supérieure a 8 Chiffres");
    else if ( CB <= 9999999 )
        throw QString("Code à barre est inférieure a 8 chiffres");

}

QSqlQueryModel* Produit::triParNom()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select * from produits ORDER BY Nom ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code à barre "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Stockage"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Catégorie"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Fournisseurs"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Employes"));



    return model;
}

QSqlQueryModel* Produit::triParPrix()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select * from produits ORDER BY Prix ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code à barre "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Stockage"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Catégorie"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Fournisseurs"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Employes"));



    return model;
}

QSqlQueryModel* Produit::triParId()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("select * from produits ORDER BY CodeB ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code à barre "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Stockage"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Catégorie"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Fournisseurs"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Employes"));



    return model;
}
void Produit::CBExist(int CB)
{
    QSqlQuery query ;
    query.prepare("SELECT * from produits where CodeB = :CodeB");
    query.bindValue(":CodeB", CB);
    query.exec();

    int i = 0 ;
    while (query.next()) {
        i++ ;
    }

    if( i == 0 )
    {
        throw QString("Le Produit Demandé N'existe Pas");
    }



}


