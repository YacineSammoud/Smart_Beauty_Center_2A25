#include "mainwindow.h"

#include"employes.h"
#include<QIntValidator>
#include <QApplication>
#include <QMessageBox>
#include "ui_mainwindow.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->id->setValidator(new QIntValidator(1000, 9999, this)); // inserer uniquement des nombres
ui->nbr_point->setValidator(new QIntValidator(1000, 9999, this));
employes E ;

ui->tab_employes->setModel(E.afficher()); //remplir ce tableau via un model qui a 2 type

}

MainWindow::~MainWindow()
{
    delete ui;
}

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
