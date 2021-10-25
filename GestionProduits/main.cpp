#include "ajouterproduits.h"
#include "afficherproduits.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AjouterProduits w;
    w.show();
    /*AfficherProduits z;
    z.show();*/
    return a.exec();
}
