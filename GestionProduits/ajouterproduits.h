#ifndef AJOUTERPRODUITS_H
#define AJOUTERPRODUITS_H

#include <QMainWindow>
#include "produit.h"
QT_BEGIN_NAMESPACE
namespace Ui { class AjouterProduits; }
QT_END_NAMESPACE

class AjouterProduits : public QMainWindow
{
    Q_OBJECT

public:
    AjouterProduits(QWidget *parent = nullptr);
    ~AjouterProduits();


private slots:
    void on_VA_clicked();

    void on_QA_clicked();

    void on_UP_clicked();

    void on_lineEdit_recherche_textChanged(const QString &arg1);

    void on_SupP_clicked();

    void on_VA_2_clicked();

    void on_StatButton_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_Export_clicked();



    void on_Email_clicked();

private:
    Ui::AjouterProduits *ui;
    Produit Prod;
};
#endif // AJOUTERPRODUITS_H
