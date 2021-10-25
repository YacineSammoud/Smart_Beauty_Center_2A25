#ifndef AJOUTERPRODUITS_H
#define AJOUTERPRODUITS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AjouterProduits; }
QT_END_NAMESPACE

class AjouterProduits : public QMainWindow
{
    Q_OBJECT

public:
    AjouterProduits(QWidget *parent = nullptr);
    ~AjouterProduits();


private:
    Ui::AjouterProduits *ui;
};
#endif // AJOUTERPRODUITS_H
