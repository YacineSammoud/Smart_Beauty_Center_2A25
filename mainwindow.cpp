#include "mainwindow.h"

#include"employes.h"
#include<QIntValidator>
#include <QApplication>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include <QObject>
#include <QPdfWriter>
#include <QPainter>

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
#include<QtCharts>

#include "widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
ui->tab_employes->setModel(E.afficher()); //remplir ce tableau via un model qui a 2 type
ui->id->setValidator(new QIntValidator(1000, 9999, this)); // inserer uniquement des nombres

ui->nbr_point->setValidator(new QIntValidator(1000, 9999, this));

employes E ;



}

MainWindow::~MainWindow()
{
    delete ui;
}
/////////////////////////
void MainWindow::on_pt_ajouter_clicked()
{
    int id=ui->id->text().toInt();//convertie la chaine de caractere en entier

    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString service=ui->service->text();

    int nbr_heure=ui->nbr_heure->text().toInt();
      int nbr_point=ui->nbr_point->text().toInt();
       ui->nom->setMaxLength(5); // max longueur de nom (line_edit)
        ui->prenom->setMaxLength(20);
        ui->nbr_heure->setMaxLength(4);

    employes E  (id,nom,prenom,service,nbr_heure,nbr_point); //on cree ajouter puis on appel ajout




bool test=E.ajouter(); //recupere la valeur de retour //inserer l'employes
     if(test) //si requete executee :qmessagebox::info
      {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                    QObject::tr("ajout successful.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_employes->setModel(E.afficher());

                }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                    QObject::tr("ajout failed.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

}
////////////////////////////////////




///////////////
void MainWindow::on_push_supprimer_clicked()
{
    employes E ;

        int id = ui->id_supp->text().toInt();//et convertir en int
        bool test=E.supprimer(id);//appel de la methode supp()
        if (test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                    QObject::tr("Suppression effectuée\n"
                                "Click Cancel non to exit.") , QMessageBox :: Cancel);
           ui->tab_employes->setModel((E.afficher()));//refrerch
            }
            else
                QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                      QObject::tr("Suppression non effectuée.\n"
                                                  "Click Cancel to exit."),QMessageBox::Cancel);
            ui->tab_employes->setModel((E.afficher()));




}


//////////////////////////////////////////////////////////////////////////////







void MainWindow::on_bouton_modifier_clicked()
{
    int id= ui ->id->text().toInt();//conversion QString to int

    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString service=ui->service->text();

    int nbr_heure=ui->nbr_heure->text().toInt();
      int nbr_point=ui->nbr_point->text().toInt();
      ui->nom->setMaxLength(5); // max longueur de nom (line_edit)
       ui->prenom->setMaxLength(20);
       ui->nbr_heure->setMaxLength(4);
             employes E  (id,nom,prenom,service,nbr_heure,nbr_point);
            bool test=E.modifier(id);//appel a la methode modifier
            if (test)
        {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Modification effectuée\n"
                            "Click Cancel non to exit.") , QMessageBox :: Cancel);

        ui->tab_employes->setModel((E.afficher()));


        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                  QObject::tr("Modification non effectuée.\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
        ui->tab_employes->setModel((E.afficher()));
}
/////////////////////////////////////////

void MainWindow::on_trie_nom_clicked()
{
    employes E;
          ui->tab_employes->setModel(E.trier1());
}
///////////////////////////////////////
void MainWindow::on_pushButton_id_clicked()
{
    employes E;
          ui->tab_employes->setModel(E.trier());
}

/////////////////////////////
void MainWindow::on_pushButton_prenom_clicked()
{
    employes E;
          ui->tab_employes->setModel(E.trier2());
}


void MainWindow::on_pushButton_pdf_clicked()
{

        {
            QPdfWriter pdf("C:\\Users\\msi\\Documents\\Atelier_Connexion\\pdf\\PDF_employes.pdf");//generer un fichier pdf

           QPainter painter(&pdf); // dessiner des ligne .......
           int i = 4000;
                  painter.setPen(Qt::red); // couleur de la ligne
                  painter.setFont(QFont("Time New Roman", 25)); // style
                  painter.drawText(3000,1400,"la liste des employes  ");
                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Time New Roman", 15));
                  painter.drawRect(100,100,9400,2500); // dimension ta3 rectangle eli fih liste des animaux
                  painter.drawRect(100,3000,9400,500);
                  painter.setFont(QFont("Time New Roman", 9));
                  painter.drawText(400,3300,"id");
                  painter.drawText(1350,3300,"nom");
                  painter.drawText(2200,3300,"prenom");
                  painter.drawText(3400,3300,"service");
                  painter.drawText(4400,3300,"nbr_heure");
 painter.drawText(4400,3300,"nbr_point");
                  painter.drawRect(100,3000,9400,9000);

                  QSqlQuery query;
                  query.prepare("select * from employess"); // t7adher requete mta3 sql
                  query.exec();
                  while (query.next()) // mise a jour
                  {
                      painter.drawText(400,i,query.value(0).toString()); // ta9ra nass mel fichier // 400 blassa //i longueur
                      painter.drawText(1350,i,query.value(1).toString());
                      painter.drawText(2300,i,query.value(2).toString());
                      painter.drawText(3400,i,query.value(3).toString());
                      painter.drawText(4400,i,query.value(4).toString());

// query value ta9ra mel tableau


                     i = i + 350;
                  }
                  QMessageBox::information(this, QObject::tr("PDF Enregistré"),
                  QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

    }
}



void MainWindow::on_pushButton_stat_clicked()
{

        //ui->stackedWidget_2->setCurrentIndex(1);
           QSqlQueryModel * model= new QSqlQueryModel();  //allocation dynamique executi commande
           model->setQuery("select * from employess where nbr_point < 10 ");
           int nb1=model->rowCount(); // retourne somme
           model->setQuery("select * from employess where nbr_point  between 10 and 30 ");
           int nb2=model->rowCount();
           model->setQuery("select * from employess where nbr_point > 30 ");
           int nb3=model->rowCount();
          int total=nb1+nb2+nb3;

           QString a=QString("moins de 10 pointss . "+QString::number((nb1*100)/total,'f',2)+"%" ); //message yo5roj
           QString b=QString("entre 10 et 30 points.  "+QString::number((nb2*100)/total,'f',2)+"%" );
           QString c=QString("plus de 30 point"+QString::number((nb3*100)/total,'f',2)+"%" );

           QPieSeries *series = new QPieSeries(); // determiner size mta3 doura
           series->append(a,nb1);
           series->append(b,nb2);// concatener
           series->append(c,nb3);
           if (nb1!=0)
           {QPieSlice *slice = series->slices().at(0);
               slice->setLabelVisible(); //
               slice->setPen(QPen());} // couleur bordure
           if ( nb2!=0)
           {
               // Add label, explode and define brush for 2nd slice
               QPieSlice *slice1 = series->slices().at(1); // t5arej slice wa7da men doura
               //slice1->setExploded();
               slice1->setLabelVisible();
           }
           if(nb3!=0)
           {
               // Add labels to rest of slices
               QPieSlice *slice2 = series->slices().at(2);
               //slice1->setExploded();
               slice2->setLabelVisible();
           }
           // Create the chart widget
           QChart *chart = new QChart();
           // Add data to chart with title and hide legend
           chart->addSeries(series); // widget
           chart->setTitle("liste des e;ployees par points "+ QString::number(total));
           chart->legend()->hide();
           // Used to display the chart
           QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
           chartView->setRenderHint(QPainter::Antialiasing);
           chartView->resize(1000,500);
           chartView->show();

}

void MainWindow::on_pushButton_cam_clicked()
{
    Widget w ;
       w.setModal(true);
       w.exec();

}




void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    ui->tab_employes->setModel(E.recherche7(arg1));
}
