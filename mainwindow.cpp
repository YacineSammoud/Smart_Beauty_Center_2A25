#include "mainwindow.h"
#include<QSqlQueryModel>
#include <QApplication>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include<QPixmap>
#include <QFile>
#include<iostream>
#include<QTextStream>
#include<fstream>
#include<QDebug>
#include <QDateTime>
#include<QCoreApplication>
#include"client.h"
#include<QIntValidator>
#include <QApplication>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock2.h>
#include <winbase.h>
#include "exportexcelobjet.h"
#include <QFileDialog>
#include"employes.h"
#include <QObject>
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

//CHIHEB
#include "produit.h"
#include<QMessageBox>
#include <QFileDialog>
#include <QLineEdit>
#include "smtp.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QTextStream>
#include "mail.h"

////ASSIL
#include "rendezvous.h"
#include <QApplication>
#include <QMessageBox>
#include <QIntValidator>
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
#include <QtCharts>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
/////AMINE
#include"fournisseur.h"
#include <QMessageBox>
#include<QString>
#include <QSqlError>
#include<QtWidgets>
#include <QFileDialog>
#include <QtDebug>
#include <QPrinter>
#include<QPdfWriter>
#include <QFile>
#include<QMessageBox>
#include<QDesktopServices>
#include "statj.h"
#include "historique.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /////ASSIL
    QString language ="FR";
    ui->Le_ID->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_rendez_vous->setModel(R.afficher());
    ui->comboBox->addItem("FR");
        ui->comboBox->addItem("ENG");


    ////ASMA
    employes E ;

    ui->tab_employes->setModel(E.afficher());
    ui->id->setValidator(new QIntValidator(1000, 9999, this));
    ui->nbr_point->setValidator(new QIntValidator(1000, 9999, this));
//ui->ID_C->setValidator(new QIntValidator(1000, 9999999, this));
    ////YACINE
client C ;

ui->tab_client->setModel(C.afficher());
/////CHIHEB
ui->tabaffiche->setModel(Prod.afficherProduits());
////AMINE
ui->tableView->setModel(f.afficher());


}

QString language ="FR";

MainWindow::~MainWindow()
{
    delete ui;
}

////ASMA

void MainWindow::on_pb_ajouter_clicked()
{
    int ID_C=ui->le_ID_C->text().toInt();
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    QString SERVICE=ui->le_service->text();
    QString ADRESSE_MAIL=ui->le_adresse_mail->text();


       /*ui->NOM->setMaxLength(20);
       ui->PRENOM->setMaxLength(20);*/


    client C  (ID_C,NOM,PRENOM,SERVICE,ADRESSE_MAIL);


bool test=C.ajouter();
     if(test)
      {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                    QObject::tr("ajout successful.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_client->setModel(C.afficher());

                }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                    QObject::tr("ajout failed.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_client->setModel(C.afficher());
      foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                   le->clear();}
              QFile file("C:/Users/chihe/Desktop/IntegrationFinal");
              if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                  return;
              QTextStream cout(&file);
              QString d_info = QDateTime::currentDateTime().toString();
              QString message2=d_info+" - Un client a été ajouté avec l'a référence'id "+ID_C+"\n";
              cout << message2;


}

void MainWindow::on_pb_modifier_clicked()
{
    int ID_C= ui ->le_ID_C_modifier->text().toInt();
    QString NOM=ui->le_nom_modifier->text();
    QString PRENOM=ui->le_prenom_modifier->text();
    QString SERVICE=ui->le_service_modifier->text();
    QString ADRESSE_MAIL=ui->le_adresse_mail_modifier->text();
      //ui->NOM->setMaxLength(20);
       //ui->PRENOM->setMaxLength(20);

             client C(ID_C,NOM,PRENOM,SERVICE,ADRESSE_MAIL);
            bool test=C.modifier(ID_C);
            if (test)
        {
                QMessageBox::information(nullptr, QObject::tr("modifie un client"),
                                  QObject::tr("client modifie.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
                foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                             le->clear();}
                        QFile file("C:/Users/chihe/Desktop/IntegrationFinal/historique.txt");
                        if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                            return;
                        QTextStream cout(&file);
                        QString d_info = QDateTime::currentDateTime().toString();
                        QString message2=d_info+" - Un client a été modifié avec l'id "+ID_C+"\n";
                        cout << message2;
        ui->tab_client->setModel((C.afficher()));


        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                  QObject::tr("Modification non effectuée.\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
        ui->tab_client->setModel((C.afficher()));
}


void MainWindow::on_pb_supprimer_clicked()
{
    client C ;

        int ID_C = ui->le_ID_C_supprimer->text().toInt();
        bool test=C.supprimer(ID_C);
        if (test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                    QObject::tr("Suppression effectuée\n"
                                "Click Cancel non to exit.") , QMessageBox :: Cancel);
           ui->tab_client->setModel((C.afficher()));//refrersh
           foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                        le->clear();}
                   QFile file("C:/Users/chihe/Desktop/IntegrationFinal/historique.txt");
                   if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                       return;
                   QTextStream cout(&file);
                   QString d_info = QDateTime::currentDateTime().toString();
                   QString message2=d_info+" - Un client a été supprimée avec l'id "+ID_C+"\n";
                   cout << message2;
            }
            else
                QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                      QObject::tr("Suppression non effectuée.\n"
                                                  "Click Cancel to exit."),QMessageBox::Cancel);
            ui->tab_client->setModel((C.afficher()));
}




void MainWindow::on_pb_stats_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from clients where ID_C < 100 ");
    float ID_C=model->rowCount();
    model->setQuery("select * from clients where ID_C  between 100 and 200 ");
    float ID_C1=model->rowCount();
    model->setQuery("select * from clients where ID_C>200 ");
    float ID_C2=model->rowCount();
    float total=ID_C+ID_C1+ID_C2;
    QString a = QString("moins de 100 "+QString::number((ID_C*100)/total,'f',2)+"%" );
    QString b = QString("entre 100 et 200 "+QString::number((ID_C1*100)/total,'f',2)+"%" );
    QString c = QString("plus de 200 "+QString::number((ID_C2*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,ID_C);
    series->append(b,ID_C1);
    series->append(c,ID_C2);
    if (ID_C!= 0)
    {
        QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());
    }
    if ( ID_C1!=0)
    {
             // Add label, explode and define brush for 2nd slice
             QPieSlice *slice1 = series->slices().at(1);
             //slice1->setExploded();
             slice1->setLabelVisible();
    }
    if(ID_C2!=0)
    {
             // Add labels to rest of slices
             QPieSlice *slice2 = series->slices().at(2);
             //slice1->setExploded();
             slice2->setLabelVisible();
    }
            // Create the chart widget
            QChart *chart = new QChart();
            // Add data to chart with title and hide legend
            chart->addSeries(series);
            chart->setTitle("Pourcentage Par ID_C :Nombre Des clients "+ QString::number(total));
            chart->legend()->hide();
            // Used to display the chart
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            chartView->resize(1000,500);
            chartView->show();
}



void MainWindow::on_pb_rechercher_clicked()
{
    C.setID_C(ui->ID_C_rechercher->text().toInt());
    ui->tab_client_rechercher->setModel(C.rechercherID_C(C.getID_C()));
    //ui->ID_C_rechercher->clear();
   // ui->NOM_rechercher->clear();
    //ui->PRENOM_rechercher->clear();
   //ui->comboBox_Sexe->clear();
    //ui->SERVICE_rechercher->clear();
    //ui->ADRESSE_MAIL_rechercher->clear();
}

void MainWindow::on_pb_trier_clicked()
{
    if(C.trier())
    {
        ui->tab_client_trier->setModel(C.trier());

    }
}


void MainWindow::on_pb_trier_nom_clicked()
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM clients order by NOM"); //ASC pour ascendant, DESC pour descendant
           q->exec();
           model->setQuery(*q);

        ui->tab_client_trier->setModel(model);

}

void MainWindow::on_pb_trier_prenom_clicked()
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM clients order by PRENOM"); //ASC pour ascendant, DESC pour descendant
           q->exec();
           model->setQuery(*q);

        ui->tab_client_trier->setModel(model);
}

void MainWindow::on_pb_trier_service_clicked()
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM clients order by SERVICE"); //ASC pour ascendant, DESC pour descendant
           q->exec();
           model->setQuery(*q);

        ui->tab_client_trier->setModel(model);
}
/********************50 dernieres requetes sql**************************/
/*
SELECT TOP 50 creation_time,
total_worker_time/execution_count AS [Avg CPU Time],
SUBSTRING(st.text, (qs.statement_start_offset/2)+1,((CASE qs.statement_end_offset WHEN -1 THEN DATALENGTH(st.text)
ELSE qs.statement_end_offset END - qs.statement_start_offset)/2) + 1) AS statement_text
FROM sys.dm_exec_query_stats AS qs
CROSS APPLY sys.dm_exec_sql_text(qs.sql_handle) AS st
ORDER BY creation_time DESC;
*/

/******************** excel (G) ***************************************/

void MainWindow::on_pb_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                ExportExcelObject obj(fileName, "mydata", ui->tab_client);

                // you can change the column order and
                // choose which colum to export
                obj.addField(0, "ID_C", "char(20)");
                obj.addField(1, "NOM", "char(20)");
                obj.addField(2, "PRENOM", "char(20)");
                obj.addField(3, "SERVICE", "char(20)");
                obj.addField(4, "ADRESSE_MAIL", "char(20)");


                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("FAIS!"),
                                             QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                             );
                    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                                 le->clear();}
                            QFile file("C:/Users/chihe/Desktop/IntegrationFinal/historique.txt");
                            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                return;
                            QTextStream cout(&file);
                            QString d_info = QDateTime::currentDateTime().toString();
                            QString message2=d_info+" - Une fichier exel a été génerée !\n";
                            cout << message2;

                }
}
void MainWindow::readfile(){
    QString filename="C:/Users/chihe/Desktop/IntegrationFinal/historique.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "NO existe el archivo "<<filename;
    }else{
        qDebug() << filename<<" encontrado...";
    }
    QString line;
    ui->tb_historique->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            ui->tb_historique->setText(ui->tb_historique->toPlainText()+line+"\n");
            qDebug() << "linea: "<<line;
        }
    }
    file.close();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    readfile();
}

void MainWindow::on_search_textEdited(const QString &arg1)
{
    //int ID_C=ui->le_ID_C->text().toInt();
    //QString ID=QString::number(ID_C);
     ui->tab_client->setModel(C.rechercher(arg1));
}

//***********************************************************************************************************************
//************************************************** PARTIE EMPLOYES ****************************************************
//***********************************************************************************************************************

void MainWindow::on_pb_ajouter_employes_clicked()
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

void MainWindow::on_pb_supprimer_employes_clicked()
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




void MainWindow::on_pb_modifier_employes_clicked()
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






void MainWindow::on_pb_tri_nom_employes_clicked()
{
    employes E;
              ui->tab_employes->setModel(E.trier1());
}

void MainWindow::on_pb_tri_id_employes_clicked()
{
    employes E;
              ui->tab_employes->setModel(E.trier());
}

void MainWindow::on_pb_tri_prenom_employes_clicked()
{
    employes E;
              ui->tab_employes->setModel(E.trier2());
}




void MainWindow::on_pb_pdf_employes_clicked()
{
    {
                QPdfWriter pdf("C:\\Users\\chihe\\Desktop\\IntegrationFinal\\PDF\\PDF_employes.pdf");//generer un fichier pdf

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


void MainWindow::on_pb_stats_employes_clicked()
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


void MainWindow::on_pb_camera_employes_clicked()
{
    Widget w ;
           w.setModal(true);
           w.exec();
}

void MainWindow::on_lineEdit_recherche_employes_textEdited(const QString &arg1)
{
    ui->tab_employes->setModel(E.recherche7(arg1));

}


/////CHIHEB

void MainWindow::on_VA_clicked()
{

    int CodeB=ui->CB->text().toInt();
    int Stockage=ui->SP->text().toInt();
    QString Nom=ui->NP->text();
    QString Categorie=ui->CP->currentText();
    QString Image=ui->IP->text();
    double Prix=ui->PP->value();
    QString ID_F=ui->FP->currentText();
    int ID=ui->EP->currentText().toInt();

 try {
     Prod.ajouterProduits(CodeB,Stockage,Nom,Categorie,Image,Prix,ID_F,ID);
     QMessageBox::information(this, "Success", "Produit Ajoutée");


        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
           le->clear();
        }
        foreach(QSpinBox* le, findChildren<QSpinBox*>()) {
           le->clear();
        }
        foreach(QDoubleSpinBox* le, findChildren<QDoubleSpinBox*>()) {
           le->clear();
        }
        ui->tabaffiche->setModel(Prod.afficherProduits());

    }

 catch (QString e) {
        QMessageBox::information(this, "Erreur", e);
    }


}

void MainWindow::on_QA_clicked()
{
    close();
}


void MainWindow::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    Produit P;
    int id = ui->lineEdit_recherche->text().toInt();
    QString N = ui->lineEdit_recherche->text();
    int S = ui->lineEdit_recherche->text().toInt();



    ui->tabaffiche->setModel(P.rechercherProduits(id,N,S));

}

void MainWindow::on_SupP_clicked()
{

    int id = ui->SupprimerP->text().toInt();
    bool test=Prod.supprimerProduits(id);
    if(test)
    {ui->tabaffiche->setModel(Prod.afficherProduits());//refresh

        QMessageBox::information(nullptr, QObject::tr("Supprimer un Produit"),
                    QObject::tr("Produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
           le->clear();
        }


    }
    else

        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_VA_2_clicked()
{

            Produit P;
        int CodeB=ui->CB_2->text().toInt();

        int Stockage=ui->SP_2->text().toInt();
        P.setStockage(Stockage);
        QString Nom=ui->NP_2->text();
        P.setNom(Nom);
        QString Categorie=ui->CP_2->currentText();
        P.setCategorie(Categorie);
        QString Image=ui->IP_2->text();
        P.setImage(Image);
        double prix=ui->PP_2->value();
        P.setPrix(prix);
        QString ID_F=ui->FP_2->currentText();
        P.setFournisseurs(ID_F);
        int ID=ui->EP_2->currentText().toInt();
        P.setEmployes(ID);

        bool test=P.modifierProduits(CodeB);
        if(test)
        {
            ui->tabaffiche->setModel(Prod.afficherProduits());

            QMessageBox::information(nullptr, QObject::tr("modifier un produit"),
                        QObject::tr("Produit modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
               le->clear();
            }
            foreach(QSpinBox* le, findChildren<QSpinBox*>()) {
               le->clear();
            }
            foreach(QDoubleSpinBox* le, findChildren<QDoubleSpinBox*>()) {
               le->clear();
            }

        }
        else

        {
            QMessageBox::critical(nullptr, QObject::tr("modifier un Produit"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }

}



void MainWindow::on_StatButton_clicked()
{
    Produit P ;
       P.stat();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tabaffiche->setModel(Prod.afficherProduits());
}






void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
QString tri=ui->comboBox_3->currentText();


    if ( tri == "Nom" )
                    {
                        ui->tabaffiche->setModel(Prod.triParNom());
                    }
    else if ( tri == "Prix" )
                    {
                        ui->tabaffiche->setModel(Prod.triParPrix());
                    }

    else if ( tri == "Code à Barre" )
                    {
                        ui->tabaffiche->setModel(Prod.triParId());

                    }



}

void MainWindow::on_Export_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tabaffiche->model()->rowCount();
                    const int columnCount =ui->tabaffiche->model()->columnCount();

                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("PRODUITS")
                            <<  "</head>\n"
                            "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                                "<img src='C:/Users/chihe/Desktop/produits.jpg' width='500' height='200'>\n"
                                "<h1>Liste des Produits</h1>"



                                "<table border=1 cellspacing=0 cellpadding=2>\n";


                    // headers
                        out << "<thead><tr bgcolor=#f0f0f0>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tabaffiche->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tabaffiche->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tabaffiche->isColumnHidden(column)) {
                                       QString data = ui->tabaffiche->model()->data(ui->tabaffiche->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table>\n"
                               "</body>\n"
                               "</html>\n";

                           QTextDocument *document = new QTextDocument();
                           document->setHtml(strStream);

                           QPrinter printer;

                           QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                           if (dialog->exec() == QDialog::Accepted) {
                               document->print(&printer);
                        }
}

void MainWindow::on_Email_clicked()
{
    mail m;
        m.exec();
}

//////ASSIL



void MainWindow::on_checkBox_id_clicked()
{
    ui->tab_rendez_vous->setModel(R.afficher());
          ui->tab_rendez_vous->setModel(R.trier_id());
    if(ui->checkBox_id->isChecked() == false )
        ui->tab_rendez_vous->setModel(R.afficher());

}

void MainWindow::on_checkBox_service_clicked()
{

    ui->tab_rendez_vous->setModel(R.afficher());

        ui->tab_rendez_vous->setModel(R.trier_service());

        if(ui->checkBox_service->isChecked() == false )
            ui->tab_rendez_vous->setModel(R.afficher());
}

void MainWindow::on_checkBox_date_clicked()
{
    ui->tab_rendez_vous->setModel(R.afficher());

        ui->tab_rendez_vous->setModel(R.trier_heure_d());

        if(ui->checkBox_date->isChecked() == false )
            ui->tab_rendez_vous->setModel(R.afficher());
}





void MainWindow::on_pb_stat_clicked()
{
        //ui->stackedWidget_2->setCurrentIndex(1);
            QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select * from Rendezvous where id < 100 ");
            float salaire=model->rowCount();
            model->setQuery("select * from Rendezvous where id  between 100 and 250 ");
            float salairee=model->rowCount();
            model->setQuery("select * from Rendezvous where id >250  ");
            float salaireee=model->rowCount();
            float total=salaire+salairee+salaireee;

            QString a=QString("moins de 100  . "+QString::number((salaire*100)/total,'f',2)+"%" );
            QString b=QString("entre 100 et 250 .  "+QString::number((salairee*100)/total,'f',2)+"%" );
            QString c=QString("plus de 250 ."+QString::number((salaireee*100)/total,'f',2)+"%" );

            QPieSeries *series = new QPieSeries();
            series->append(a,salaire);
            series->append(b,salairee);
            series->append(c,salaireee);
            if (salaire!=0)
            {QPieSlice *slice = series->slices().at(0);
                slice->setLabelVisible();
                slice->setPen(QPen());}
            if ( salairee!=0)
            {
                // Add label, explode and define brush for 2nd slice
                QPieSlice *slice1 = series->slices().at(1);
                //slice1->setExploded();
                slice1->setLabelVisible();
            }
            if(salaireee!=0)
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
            chart->setTitle("STATISTIQUE DES RENDEZVOUS SELON HEURE_D "+ QString::number(total));
            chart->legend()->hide();
            // Used to display the chart
            QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
            chartView->setRenderHint(QPainter::Antialiasing);
            chartView->resize(1000,500);
            chartView->show();
     }










void MainWindow::on_comboBox_activated(const QString &arg1)
{
    language = ui->comboBox->currentText();

      if(language == "FR"){
          ui->checkBox_id->setText("Trier par ID");
          ui->checkBox_service->setText("trier par service");
          ui->checkBox_date->setText("trier par heure_d");
          ui->label_7->setText("recherche");
          ui->pb_stat->setText("consulter statistique");
          ui->pb_supprimer->setText("supprimer");
          ui->pb_ajouter->setText("ajouter");
          ui->pb_modifier->setText("modifier");
          ui->pb_enr->setText("enregister");
      }else {
          ui->checkBox_id->setText(" order by ID");
          ui->checkBox_service->setText("order by service");
          ui->checkBox_date->setText("order by heure_d");
          ui->label_7->setText("search");
          ui->pb_stat->setText("consult statistics");
          ui->pb_supprimer->setText("delete");
          ui->pb_ajouter->setText("add");
          ui->pb_modifier->setText("update");
          ui->pb_enr->setText("save");




      }
}

void MainWindow::on_pb_enr_clicked()
{
    QString nomFile=ui->le_enr->text();
        QMessageBox msg;
        if(!nomFile.length()){

            msg.setText("entrer le nom du fichier");
            msg.exec();
        }
        else{
            QFile file("C:/Users/chihe/Desktop/IntegrationFinal/ "+nomFile+".csv");
            QString finalmsg="fichier modifie avec succes";
            if(!file.exists()){
                finalmsg="fichier crée avec succes";
            }
            file.open(QFile::WriteOnly | QFile::Text);
            QTextStream txt(&file);
            for(int i=0;i<100;i++){

                QString ID= ui->tab_rendez_vous->model()->index(i,0).data().toString();
                QString service= ui->tab_rendez_vous->model()->index(i,1).data().toString();
                QString dates= ui->tab_rendez_vous->model()->index(i,2).data().toString();


                if(ID.length()){

                    txt<< "ID    '"+ ID +"' \n";
                    txt<< "service          '"+ service +"' \n";
                    txt<< "dates        '"+ dates +"' \n";

                }
            }
            msg.setText(finalmsg);
            msg.exec();
            file.close();
        }
    }





void MainWindow::on_pb_ajouter_2_clicked()
{
    int id=ui->Le_ID->text().toInt();//convertie la chaine de caractere en entier

    QString service=ui->Le_Service->text();
    QString dates=ui->Le_Date->text();
    QString heure_D=ui->Le_heure_D->text();



    Rendezvous R (id,service,dates,heure_D); //on cree ajouter puis on appel ajout




bool test=R.ajouter(); //recupere la valeur de retour //inserer rendezvous
     if(test) //si requete executee :qmessagebox::info
      {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                    QObject::tr("ajout successful.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);


                }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                    QObject::tr("ajout failed.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    Rendezvous R1 ; R1.setid((ui->le_id_supp->text().toInt()));
    bool test=R1.supprimer((R1.getid()));

    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Suppression effectuée\n"
                            "Click Cancel non to exit.") , QMessageBox :: Cancel);
       ui->tab_rendez_vous->setModel((R.afficher()));//refrerch
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                  QObject::tr("Suppression non effectuée.\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
        ui->tab_rendez_vous->setModel((R.afficher()));
}

void MainWindow::on_pb_modifier_2_clicked()
{
    int i = ui->Le_ID_3->text().toInt();
   QString s = ui->Le_service_3->text();
   QString d= ui->le_date_3->text();
    QString h = ui->Le_heure_d_3->text();



    Rendezvous R(i,s,d,h);
    bool test = R.modifier();
         if (test)
         {

             ui->tab_rendez_vous->setModel(R.afficher());
             QMessageBox::information(nullptr,"MODIFER Rendezvous","MODFIER AJOUTEE");
         }
         else
         {
             QMessageBox::warning(nullptr,"MODIFER Rendezvous","Rendezvous NON MODIFER");
         }
}

void MainWindow::on_lineEdit_recherche_2_textChanged(const QString &arg1)
{
    QString rech=ui->lineEdit_recherche->text();
      ui->tab_rendez_vous->setModel(R.Recherche(rech));
}

void MainWindow::on_tabWidget_4_currentChanged(int index)
{
    ui->tab_rendez_vous->setModel(R.afficher());

}

//////AMINE

void MainWindow::on_pushButton_ajouter_clicked()
{
    QString ID_f=ui->lineEdit_ID_f->text();
    QString nom=ui->lineEdit_nom->text();
    QString H_TRAVAIL=ui->lineEdit_H_TRAVAIL->text();
    QString PRIX_A=ui->lineEdit_PRIX_A->text();
    QString PRIX_V=ui->lineEdit_PRIX_V->text();
    QString QP=ui->lineEdit_QP->text();
    fournisseur f(ID_f,nom,PRIX_A,PRIX_V,H_TRAVAIL,QP);
    bool test=f.ajouter();

    Historique h;
      h.save("ID_F:"+ID_f,"nom :"+nom,"QP:"+QP);

    if(test)

    {
         ui->tableView->setModel(f.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("ajout effectué\n""click concel to exit."),QMessageBox::Cancel);
    }
        else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                  QObject::tr("ajout non effectué.\n""click cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_supprimer_clicked()
{
   QString ID_f =ui->lineEdit_ID_f_2->text();
   bool test=Etmp.supprimer(ID_f);
   if(test)
       {
       ui->tableView->setModel(Etmp.afficher());

           QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectuée.\n""Click Cancel to exit."),QMessageBox::Cancel);
       }
   else


               QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("suppression non effectuée.\n""Click Cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_modifier_clicked()
{
    QString ID_f =ui->lineEdit_ID_f_3->text();
       QString nom=ui->lineEdit_nom_2->text();
       QString PRIX_A=ui->lineEdit_PRIX_A_2->text();
       QString PRIX_V=ui->lineEdit_PRIX_V_2->text();
       QString H_TRAVAIL=ui->lineEdit_H_TRAVAIL_2->text();
       QString QP =ui->lineEdit_QP_2->text();
       fournisseur f(ID_f,nom,PRIX_A,PRIX_V,H_TRAVAIL,QP);
        bool test=f.modifier( ID_f);
     if(test)
     {
         ui->tableView->setModel(Etmp.afficher());

         QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("connection successful.\n"
                                                                                       "click cancel to exit."),QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr,QObject::tr("data is not open"),QObject::tr("connection failed.\n"
                                                                                   "click cancel to exit."),QMessageBox::Cancel);
}





void MainWindow::on_pushButton_nom_clicked()
{
    fournisseur f;
    ui->tableView->setModel(f.trier1());

}

void MainWindow::on_pushButton_ID_f_clicked()
{
    fournisseur f;

             ui->tableView->setModel(f.trier());

}

void MainWindow::on_pushButton_PRIX_A_clicked()
{
    fournisseur f;

                 ui->tableView->setModel(f.trier2());
}

void MainWindow::on_pushButton_clicked()
{
    QPrinter  printer;
    printer.setPrinterName("test");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec()==QDialog::Rejected) return;
}

void MainWindow::on_lineEdit_recherhche_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
    if(ui->cobo_crit->currentText()=="ID_F"
            ){
        query->prepare("SELECT * FROM FOURNISSEUR WHERE ID_F LIKE'"+arg1+"%'");//
query->exec();
    model->setQuery(*query);
 ui->tableView->setModel(model);


    }
    else {
        if(ui->cobo_crit->currentText()=="nom"){
            query->prepare("SELECT * FROM FOURNISSEUR WHERE nom LIKE'"+arg1+"%'");//+tri
    query->exec();
        model->setQuery(*query);
   ui->tableView->setModel(model);
        }
        else{
            if(ui->cobo_crit->currentText()=="H_TRAVAIL")
                query->prepare("SELECT * FROM FOURNISSEUR WHERE H_TRAVAIL LIKE'"+arg1+"%'");//+tri
        query->exec();
            model->setQuery(*query);
        ui->tableView->setModel(model);
            }

        }
}



void MainWindow::on_pushButton_stat_clicked()
{

    stat_j=new statj(this);
    stat_j->show();
}

void MainWindow::on_pushButton_fiche_clicked()
{

    Historique h;
h.load();
h.load();

QString link="C:\\Users\\chihe\\Desktop\\IntegrationFinal\\his";
    QDesktopServices::openUrl(QUrl(link));
    //bool test=f.ajfichehisto(ui->lineEdit_ID_f_2->text().toInt());
}
