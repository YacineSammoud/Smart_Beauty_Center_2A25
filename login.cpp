#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username=ui->lineEdit->text();
       QString pwd=ui->lineEdit_2->text();
      // QString combo =ui->LoginCombo->currentText();
       if(username=="admin" && pwd=="admin")
       {

          // if(combo=="Agent Commercial" or combo=="Admin")

           QMessageBox::information(nullptr, QObject::tr("login effecuté"),
                       QObject::tr("Login effecuté.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           this->hide();
           MainWindow *main = new MainWindow();
               main->show();
               //ui->tabWidget_2->setTabEnabled(3, false);


       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Login non effectué"),
                       QObject::tr("Login non effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }
}
