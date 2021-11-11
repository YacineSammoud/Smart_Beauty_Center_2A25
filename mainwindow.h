#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employes.h"

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

    void on_push_load_clicked();

    void on_push_supprimer_clicked();

    void on_bouton_modifier_clicked();



    void on_valider_modifier_clicked();

private:
    Ui::MainWindow *ui;
    employes E ;
};

#endif // MAINWINDOW_H
