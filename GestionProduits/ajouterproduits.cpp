#include "ajouterproduits.h"
#include "ui_ajouterproduits.h"
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
 try {
     Prod.ajouterProduits(CodeBarre,Stockage,Nom,Categorie,Image,Prix,ID_E,ID_F);
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
    QString N = ui->lineEdit_recherche->text();

    ui->tabaffiche->setModel(P.rechercherProduits(id,N));

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






void AjouterProduits::on_comboBox_3_currentIndexChanged(const QString &arg1)
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

void AjouterProduits::on_Export_clicked()
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
                                "<img src='C:/Users/chihe/Desktop/produits.jpg' width='550' height='200'>\n"
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

void AjouterProduits::on_Email_clicked()
{
    mail m;
        m.exec();
}
