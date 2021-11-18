#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employes.h"
#include "widget.h"

#include <QMainWindow>

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
    void on_pt_ajouter_clicked();

    //void on_push_load_clicked();

    void on_push_supprimer_clicked();

    void on_bouton_modifier_clicked();



    //void on_valider_modifier_clicked();

    //void on_pushButton_14_clicked();

    //void on_pushButton_chercherE_clicked();

    //void on_pushButton_3_clicked();

    void on_trie_nom_clicked();

    void on_pushButton_id_clicked();

    void on_pushButton_prenom_clicked();

    void on_pushButton_pdf_clicked();

    //void on_pushButton_clicked();

    void on_pushButton_stat_clicked();

    void on_pushButton_cam_clicked();

    void on_id_supp_textChanged();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Widget *dialog;
    employes E ;
};

#endif // MAINWINDOW_H
