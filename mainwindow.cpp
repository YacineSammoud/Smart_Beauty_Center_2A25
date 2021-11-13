#include "mainwindow.h"

#include"client.h"
#include<QIntValidator>
#include <QApplication>
#include <QMessageBox>
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//ui->ID_C->setValidator(new QIntValidator(1000, 9999999, this));
client C ;

ui->tab_client->setModel(C.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}



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
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Modification effectuée\n"
                            "Click Cancel non to exit.") , QMessageBox :: Cancel);

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
            }
            else
                QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                      QObject::tr("Suppression non effectuée.\n"
                                                  "Click Cancel to exit."),QMessageBox::Cancel);
            ui->tab_client->setModel((C.afficher()));
}
