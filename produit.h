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
    Produit(int,int,QString,QString,QString,double,QString,int); //Constructeur parametré
    int getCodeB();
    int getStockage();
    QString getNom();
    QString getCategorie();
    QString getImage();
    double getPrix();
    int getEmployes();
    QString getFournisseurs();
    void setCodeB(int);
    void setStockage(int);
    void setNom(QString);
    void setCategorie(QString);
    void setImage(QString);
    void setPrix(double);
    void setEmployes(int);
    void setFournisseurs(QString);
    bool ajouterProduits(int CB ,int Stockage,QString Nom,QString Categorie,QString Image,double Prix,QString ID_F,int ID);
    QSqlQueryModel* afficherProduits();
    QSqlQueryModel *rechercherProduits(int CodeB, QString Nom,int Stockage);
    bool supprimerProduits(int);
    bool modifierProduits(int);
    void stat();
    void verifCB(int CodeB);
    void CBExist(int CodeB);
    QSqlQueryModel* triParNom();
    QSqlQueryModel* triParPrix();
    QSqlQueryModel* triParId();


private:
    int CodeB ,Stockage,ID  ;
    QString Nom , Categorie ,Image,ID_F;
    double Prix ;


};

#endif // PRODUIT_H
