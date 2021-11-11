#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QBuffer>
Produit::Produit() //Constructeur par défaut
{
Code_Barre=0 ;
Nom="";
Stockage=0 ;
Categorie="";
Image="" ;
Prix =0;
ID_E="";
ID_F="";
}
Produit::Produit(int Code_Barre,int Stockage,QString Nom,QString Categorie,QString Image,double Prix,QString ID_E,QString ID_F)
{
    this->Code_Barre=Code_Barre;
    this->Stockage=Stockage;
    this->Nom=Nom;
    this->Categorie=Categorie;
    this->Image=Image;
    this->Prix=Prix;
    this->ID_E=ID_E;
    this->ID_F=ID_F;

}
int Produit::getCode_Barre(){return Code_Barre;}
int Produit::getStockage(){return Stockage;}
QString Produit::getNom(){return Nom;}
QString Produit::getCategorie(){return Categorie;}
QString Produit::getImage(){return Image;}
double Produit::getPrix(){return Prix;}
QString Produit::getEmployes(){return ID_E;}
QString Produit::getFournisseurs(){return ID_F;}


void Produit::setCode_Barre(int Code_Barre){this->Code_Barre=Code_Barre;}
void Produit::setStockage(int Stockage){this->Stockage=Stockage;}
void Produit::setNom(QString Nom){this->Nom=Nom;}
void Produit::setCategorie(QString Categorie){this->Categorie=Categorie;}
void Produit::setImage(QString Image){this->Image=Image;}
void Produit::setPrix(double Prix){this->Prix=Prix;}
void Produit::setEmployes(QString ID_E){this->ID_E=ID_E;}
void Produit::setFournisseurs(QString ID_F){this->ID_F=ID_F;}


bool Produit::ajouterProduits()
{


    QSqlQuery query;
    QString res= QString::number(Code_Barre);
    QString res1= QString::number(Stockage);
    QString res2= QString::number(Prix);


    query.prepare("INSERT INTO PRODUIT(CODE_BARRE,STOCKAGE,NOM,CATEGORIE,IMAGE,PRIX,ID_E,ID_F)"
                  "VALUES (:Code_Barre,:Stockage,:Nom,:Categorie,:Image,:Prix,:ID_E,:ID_F)");

    query.bindValue(":Code_Barre", res);
    query.bindValue(":Stockage", res1);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Categorie", Categorie);
    query.bindValue(":Image", Image);
    query.bindValue(":Prix", res2);
    query.bindValue(":ID_E", ID_E);
    query.bindValue(":ID_F", ID_F);

    return query.exec();


}
QSqlQueryModel* Produit::afficherProduits()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM produit");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code à barre "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Stockage"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Catégorie"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Employes"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Fournisseurs"));

        return model;
}


QSqlQueryModel *Produit::rechercherProduits(int Code_Barre )
{
    QString res= QString::number(Code_Barre);
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from produit where (Code_Barre LIKE '"+res+"%'  ) ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code à barre "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Stockage"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Catégorie"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Image"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("Employes"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Fournisseurs"));

    return model;
}

bool Produit::supprimerProduits(int Code_Barre)
{
QSqlQuery query;
QString res= QString::number(Code_Barre);
query.prepare("Delete from produit where Code_Barre = :Code_Barre ");
query.bindValue(":Code_Barre", res);
return    query.exec();
}

bool Produit::modifierProduits(int Code_Barre)
{
    QSqlQuery query;
    QString res= QString::number(Code_Barre);
    QString res1= QString::number(Stockage);
    QString res2= QString::number(Prix);
    query.prepare("UPDATE  produit set Stockage=:Stockage,Nom=:Nom,Categorie=:Categorie,Image=:Image,Prix=:Prix,ID_E=:ID_E,ID_F=:ID_F where Code_Barre=:Code_Barre");

    query.bindValue(":Code_Barre", res);
    query.bindValue(":Stockage", res1);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Categorie", Categorie);
    query.bindValue(":Image", Image);
    query.bindValue(":Prix", res2);
    query.bindValue(":ID_E", ID_E);
    query.bindValue(":ID_F", ID_F);



    return    query.exec();


}


void Produit::stat()
{
    QSqlQuery query ;

    query.exec("SELECT * from produit where categorie LIKE 'Soins visage'");
    int i = 0 ;

    QBarSet *set0 = new QBarSet("Nombre De Produit Par Categories");
    while (query.next()) {
        i++ ;
    }
    *set0 << i ;

    query.exec("SELECT * from produit where categorie LIKE 'Maquillage'");
    i = 0 ;
    while (query.next()) {
        i++ ;
    }
    *set0 << i ;

    query.exec("SELECT * from produit where categorie LIKE 'Soins corps'");
    i = 0 ;
    while (query.next()) {
        i++ ;
    }
    *set0 << i ;

    query.exec("SELECT * from produit where categorie LIKE 'Coloration cheveux'");
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

