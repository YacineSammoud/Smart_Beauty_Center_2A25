#include "mail.h"
#include "ui_mail.h"
#include "smtp.h"

mail::mail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mail)
{
    ui->setupUi(this);
    //for email tab
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
}

mail::~mail()
{
    delete ui;
}


//mailing
void  mail::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   mail::sendMail()
{
    Smtp* smtp = new Smtp("chihebab94@gmail.com",ui->mail_pass->text(), "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("chihebab94@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("chihebab94@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void   mail::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}
