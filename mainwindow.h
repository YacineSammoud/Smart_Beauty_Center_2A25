#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include <QMainWindow>
#include <QPrinter>
#include <QPrintDialog>
#include "statj.h"
#include"arduino.h"

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    //void on_pushButton_chercher_clicked();

    void on_pushButton_clicked();

    //void on_pushButton_trier_clicked();

    void on_pushButton_nom_clicked();

    void on_pushButton_ID_f_clicked();

    void on_pushButton_PRIX_A_clicked();

    void on_lineEdit_recherhche_textChanged(const QString &arg1);

    //void on_pushButton_2_clicked();

    //void on_pushButton_3_clicked();

    void on_pushButton_stat_clicked();

    void on_pushButton_fiche_clicked();

private:

    Ui::MainWindow *ui;
    fournisseur f;
    fournisseur Etmp;
     statj *stat_j;
     QByteArray data; // variable contenant les données reçues

         Arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
