#include "historique.h"
#include<QMessageBox>

Historique::Historique()
{
tmp="";
}
void Historique::save(QString ID_F,QString nom,QString QP)//fonction save
{    QFile file ("C:/Users/chihe/Desktop/IntegrationFinal/his.txt");//place de fichier
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))//
      qDebug()<<"erreur";
     QTextStream out(&file);
     out << ID_F+"\n"+nom << "\n" +QP << "\n";


}
QString Historique::load() //fonction load
{   tmp="";

    QFile file("C:/Users/chihe/Desktop/IntegrationFinal/his.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      tmp="";

    QTextStream in(&file);

   while (!in.atEnd()) {

         QString myString = in.readLine();
         tmp+=myString+"\n";

   }
   return tmp;
}
