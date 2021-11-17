#include "widget.h"
#include "ui_widget.h"
#include "employes.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QMenu>
#include<QAction>
#include<QFileDialog>


/*Widget::Widget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Widget)   // n3ayet classe
{
    ui->setupUi(this);

    mCamera = new QCamera(this); //declari cam
    mCameraViewfinder = new QCameraViewfinder(this); // tlawej pos view
    mCameraImageCapture = new QCameraImageCapture(mCamera, this); // variable caapture
    mLayout = new QVBoxLayout ;

    mOptionMenu = new QMenu("options",this);
    mAllumerAction = new QAction("Allumer",this);
    mEteindreAction = new QAction("ETeindre",this);
    mCaturerAction = new QAction ("Capturer",this);

    mOptionMenu->addActions({mAllumerAction , mEteindreAction , mCaturerAction}); // afficher bouton

    ui->option_pushButton->setMenu(mOptionMenu); //activer
    mCamera->setViewfinder(mCameraViewfinder);


    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);

    ui->scrollArea->setLayout(mLayout); // afficher elli fih taswira (mlayout)

    connect(mAllumerAction, &QAction::triggered,[&](){   mCamera->start();}); //connecter qt +cam w t7ell cam

    connect(mEteindreAction,&QAction::triggered,[&]() //
    {
        mCamera->stop();
    });

    connect(mCaturerAction,&QAction::triggered,[&]() // connecteur bech ta3mel capture
    {
     auto filename  = QFileDialog::getSaveFileName(this,"capturer", "/" , "Image (jpg; jpeg)"); // variable ye5i cap
        mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings ;
        imageEncoderSettings.setCodec("image/jpeg"); //ye5o taswira
        imageEncoderSettings.setResolution(1600,1200); //resolution
        mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
       mCamera->setCaptureMode(QCamera::CaptureStillImage); //cam tet7all
       mCamera->start();
       mCamera->searchAndLock();
       mCameraImageCapture->capture(filename);
       mCamera->unlock();

    });


}

Widget::~Widget()
{
    delete ui;
}
*/
