#ifndef AFFICHERPRODUITS_H
#define AFFICHERPRODUITS_H

#include <QDialog>

namespace Ui {
class AfficherProduits;
}

class AfficherProduits : public QDialog
{
    Q_OBJECT

public:
    explicit AfficherProduits(QWidget *parent = nullptr);
    ~AfficherProduits();

private:
    Ui::AfficherProduits *ui;
};

#endif // AFFICHERPRODUITS_H
