#include "ajouterproduits.h"
#include "ui_ajouterproduits.h"

AjouterProduits::AjouterProduits(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AjouterProduits)
{
    ui->setupUi(this);
}

AjouterProduits::~AjouterProduits()
{
    delete ui;
}


