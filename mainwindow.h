#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"

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
    void on_pb_ajouter_clicked();
    //void on_push_load_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();
    //void on_valider_modifier_clicked();
    //void on_pushButton_9_clicked();
    //void on_pb_modifier_2_clicked();


private:
    Ui::MainWindow *ui;
    client C ;
};

#endif // MAINWINDOW_H
