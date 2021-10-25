#include "afficherproduits.h"
#include "ui_afficherproduits.h"

AfficherProduits::AfficherProduits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfficherProduits)
{
    ui->setupUi(this);
}

AfficherProduits::~AfficherProduits()
{
    delete ui;
}
