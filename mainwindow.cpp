#include "mainwindow.h"
#include "ui_mainwindow.h"
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


MainWindow::MainWindow(QWidget *parent) :
     QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString language ="FR";
    ui->Le_ID->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_rendez_vous->setModel(R.afficher());
    ui->comboBox->addItem("FR");
        ui->comboBox->addItem("ENG");
}
QString language ="FR";
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()

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





void MainWindow::on_pb_supprimer_clicked()
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




void MainWindow::on_pb_modifier_clicked()
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


void MainWindow::on_tabWidget_currentChanged(int index)
{
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
            QFile file("C:/Users/assil/Desktop/Project/Gestion_RendezVous "+nomFile+".csv");
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


