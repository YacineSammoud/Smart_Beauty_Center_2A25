#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QLabel>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

class Produit
{
public:
    Produit(); //Constructeur par défaut
    Produit(int,int,QString,QString,QString,double,QString,QString); //Constructeur parametré
    int getCode_Barre();
    int getStockage();
    QString getNom();
    QString getCategorie();
    QString getImage();
    double getPrix();
    QString getEmployes();
    QString getFournisseurs();
    void setCode_Barre(int);
    void setStockage(int);
    void setNom(QString);
    void setCategorie(QString);
    void setImage(QString);
    void setPrix(double);
    void setEmployes(QString);
    void setFournisseurs(QString);
    bool ajouterProduits(int CB ,int Stockage,QString Nom,QString Categorie,QString Image,double Prix,QString ID_E,QString ID_F);
    QSqlQueryModel* afficherProduits();
    QSqlQueryModel *rechercherProduits(int Code_barre, QString Nom);
    bool supprimerProduits(int);
    bool modifierProduits(int);
    void stat();
    void verifCB(int Code_barre);
    void CBExist(int Code_barre);
    QSqlQueryModel* triParNom();
    QSqlQueryModel* triParPrix();
    QSqlQueryModel* triParId();


private:
    int Code_Barre ,Stockage  ;
    QString Nom , Categorie ,Image,ID_E,ID_F;
    double Prix ;


};

#endif // PRODUIT_H
