#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include"arduino.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(f.afficher());
    //int ret=A.connect_arduino(); // lancer la connexion à arduino
    //switch(ret){
    //case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
  //      break;
    //case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
      // break;
    //case(-1):qDebug() << "arduino is not available";
    }
     //QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).


//}

MainWindow::~MainWindow()
{
    delete ui;
}

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
QString link="C:\\Users\\amine\\OneDrive\\Bureau\\Makemeup\\his";
    QDesktopServices::openUrl(QUrl(link));
    //bool test=f.ajfichehisto(ui->lineEdit_ID_f_2->text().toInt());
}
