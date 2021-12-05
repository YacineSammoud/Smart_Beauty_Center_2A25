#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include "produit.h"
#include <QMainWindow>

#include "employes.h"
#include "widget.h"
#include "rendezvous.h"
#include "fournisseur.h"
#include "statj.h"

#include <QPrinter>
#include <QPrintDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    //void on_push_load_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();
    //void on_valider_modifier_clicked();
    //void on_pushButton_9_clicked();
    //void on_pb_modifier_2_clicked();


    void on_pb_stats_clicked();

    //void on_pushButton_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_trier_clicked();

    void on_pb_trier_nom_clicked();

    void on_pb_trier_prenom_clicked();

    void on_pb_trier_service_clicked();

    void on_pb_excel_clicked();

    void readfile();

    void on_tabWidget_currentChanged(int index);

    void on_search_textEdited(const QString &arg1);

    void on_pb_ajouter_employes_clicked();

    void on_pb_supprimer_employes_clicked();

    void on_pb_modifier_employes_clicked();

    void on_pb_tri_nom_employes_clicked();

    void on_pb_tri_id_employes_clicked();

    void on_pb_tri_prenom_employes_clicked();

    void on_pb_pdf_employes_clicked();

    void on_pb_stats_employes_clicked();

    void on_pb_camera_employes_clicked();

    void on_lineEdit_recherche_employes_textEdited(const QString &arg1);

    ////CHIHEB

    void on_VA_clicked();

    void on_QA_clicked();

    void on_lineEdit_recherche_textChanged(const QString &arg1);

    void on_SupP_clicked();

    void on_VA_2_clicked();

    void on_StatButton_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_Export_clicked();

    void on_Email_clicked();

    ////ASSIL
    void on_checkBox_id_clicked();

    void on_checkBox_service_clicked();

    void on_checkBox_date_clicked();


    void on_pb_stat_clicked();



    void on_comboBox_activated(const QString &arg1);

    void on_pb_enr_clicked();


    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_modifier_2_clicked();

    void on_lineEdit_recherche_2_textChanged(const QString &arg1);

    void on_tabWidget_4_currentChanged(int index);

    ///AMINE
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

   // void on_pushButton_2_clicked();

   // void on_pushButton_3_clicked();

    void on_pushButton_stat_clicked();

    void on_pushButton_fiche_clicked();

private:
    Ui::MainWindow *ui;
    client C ;
    Widget *dialog;
    employes E ;
    Produit Prod;
    Rendezvous R ;

    fournisseur f;
    fournisseur Etmp;
     statj *stat_j;
     QByteArray data ;
};

#endif // MAINWINDOW_H
