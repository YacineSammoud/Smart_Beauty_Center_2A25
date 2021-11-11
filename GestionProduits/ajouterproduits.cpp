#include "ajouterproduits.h"
#include "ui_ajouterproduits.h"
#include "produit.h"
#include<QMessageBox>
#include <QFileDialog>
#include <QLineEdit>
AjouterProduits::AjouterProduits(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AjouterProduits)
{
    ui->setupUi(this);
    ui->tabaffiche->setModel(Prod.afficherProduits());

}

AjouterProduits::~AjouterProduits()
{
    delete ui;
}



void AjouterProduits::on_VA_clicked()
{

    int CodeBarre=ui->CB->text().toInt();
    int Stockage=ui->SP->text().toInt();
    QString Nom=ui->NP->text();
    QString Categorie=ui->CP->currentText();
    QString Image=ui->IP->text();
    double Prix=ui->PP->value();
    QString ID_E=ui->EP->currentText();
    QString ID_F=ui->FP->currentText();
    Produit P(CodeBarre,Stockage,Nom,Categorie,Image,Prix,ID_E,ID_F);
    bool test = P.ajouterProduits();
    if(test){
        ui->tabaffiche->setModel(Prod.afficherProduits());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                          QObject::tr("Produit ajouté.\n"
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

    else {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }


}

void AjouterProduits::on_QA_clicked()
{
    close();
}

void AjouterProduits::on_UP_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
    if(QString::compare(filename,QString())!=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            ui->ILP->setPixmap(QPixmap::fromImage(image));
        }
        else{
        }

    }
}

void AjouterProduits::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    Produit P;
    int id = ui->lineEdit_recherche->text().toInt();
    ui->tabaffiche->setModel(P.rechercherProduits(id));

}

void AjouterProduits::on_SupP_clicked()
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

void AjouterProduits::on_VA_2_clicked()
{

            Produit P;
        int Code_Barre=ui->CB_2->text().toInt();

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
        QString ID_E=ui->EP_2->currentText();
        P.setEmployes(ID_E);
        QString ID_F=ui->FP_2->currentText();
        P.setFournisseurs(ID_F);

        bool test=P.modifierProduits(Code_Barre);
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



void AjouterProduits::on_StatButton_clicked()
{
    Produit P ;
       P.stat();
}

void AjouterProduits::on_pushButton_5_clicked()
{
    ui->tabaffiche->setModel(Prod.afficherProduits());
}
