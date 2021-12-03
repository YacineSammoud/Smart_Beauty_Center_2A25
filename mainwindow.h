#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "rendezvous.h"

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

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_checkBox_id_clicked();

    void on_checkBox_service_clicked();

    void on_checkBox_date_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pb_stat_clicked();



    void on_comboBox_activated(const QString &arg1);

    void on_pb_enr_clicked();

    void on_lineEdit_recherche_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Rendezvous R ;



};

#endif // MAINWINDOW_H
