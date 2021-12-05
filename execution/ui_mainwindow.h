/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *menu;
    QWidget *tab_6;
    QLabel *label_14;
    QPushButton *client;
    QPushButton *employes;
    QPushButton *produit;
    QPushButton *fournisseurs;
    QPushButton *rendez_vous;
    QWidget *tab_3;
    QLabel *label_4;
    QWidget *tab;
    QPushButton *pt_ajouter;
    QLineEdit *nbr_heure;
    QLineEdit *nom;
    QLineEdit *id;
    QLineEdit *service;
    QPushButton *bouton_modifier;
    QLineEdit *prenom;
    QLabel *label_9;
    QLabel *label;
    QLabel *label_11;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_chercherE;
    QTableView *tab_employes;
    QLineEdit *nbr_point;
    QLabel *label_10;
    QPushButton *push_supprimer;
    QLineEdit *id_supp;
    QLabel *label_13;
    QPushButton *pushButton_stat;
    QLabel *label_2;
    QPushButton *trie_nom;
    QPushButton *pushButton_id;
    QPushButton *pushButton_prenom;
    QPushButton *pushButton_cam;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_pdf;
    QWidget *tab_2;
    QLabel *label_5;
    QWidget *tab_4;
    QLabel *label_6;
    QWidget *tab_5;
    QLabel *label_12;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1027, 620);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        menu = new QTabWidget(centralWidget);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setGeometry(QRect(10, 30, 811, 481));
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        label_14 = new QLabel(tab_6);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(6, 3, 801, 451));
        label_14->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/248085488_591901992026832_2710901618884620913_n (1).png")));
        client = new QPushButton(tab_6);
        client->setObjectName(QStringLiteral("client"));
        client->setGeometry(QRect(150, 130, 141, 31));
        employes = new QPushButton(tab_6);
        employes->setObjectName(QStringLiteral("employes"));
        employes->setGeometry(QRect(150, 180, 141, 31));
        produit = new QPushButton(tab_6);
        produit->setObjectName(QStringLiteral("produit"));
        produit->setGeometry(QRect(150, 230, 141, 31));
        fournisseurs = new QPushButton(tab_6);
        fournisseurs->setObjectName(QStringLiteral("fournisseurs"));
        fournisseurs->setGeometry(QRect(150, 280, 141, 31));
        rendez_vous = new QPushButton(tab_6);
        rendez_vous->setObjectName(QStringLiteral("rendez_vous"));
        rendez_vous->setGeometry(QRect(150, 330, 141, 31));
        menu->addTab(tab_6, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(6, 3, 801, 451));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/248085488_591901992026832_2710901618884620913_n (1).png")));
        menu->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pt_ajouter = new QPushButton(tab);
        pt_ajouter->setObjectName(QStringLiteral("pt_ajouter"));
        pt_ajouter->setGeometry(QRect(470, 260, 61, 28));
        nbr_heure = new QLineEdit(tab);
        nbr_heure->setObjectName(QStringLiteral("nbr_heure"));
        nbr_heure->setGeometry(QRect(440, 170, 113, 22));
        nom = new QLineEdit(tab);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(440, 60, 113, 22));
        id = new QLineEdit(tab);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(440, 30, 113, 22));
        service = new QLineEdit(tab);
        service->setObjectName(QStringLiteral("service"));
        service->setGeometry(QRect(440, 130, 113, 22));
        bouton_modifier = new QPushButton(tab);
        bouton_modifier->setObjectName(QStringLiteral("bouton_modifier"));
        bouton_modifier->setGeometry(QRect(470, 230, 61, 28));
        prenom = new QLineEdit(tab);
        prenom->setObjectName(QStringLiteral("prenom"));
        prenom->setGeometry(QRect(440, 100, 113, 22));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(390, 100, 85, 16));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(390, 200, 61, 20));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(390, 170, 51, 20));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(400, 30, 88, 16));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(390, 60, 89, 16));
        pushButton_chercherE = new QPushButton(tab);
        pushButton_chercherE->setObjectName(QStringLiteral("pushButton_chercherE"));
        pushButton_chercherE->setGeometry(QRect(150, 230, 201, 28));
        tab_employes = new QTableView(tab);
        tab_employes->setObjectName(QStringLiteral("tab_employes"));
        tab_employes->setGeometry(QRect(10, 260, 341, 192));
        nbr_point = new QLineEdit(tab);
        nbr_point->setObjectName(QStringLiteral("nbr_point"));
        nbr_point->setGeometry(QRect(440, 200, 113, 22));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(390, 130, 62, 16));
        push_supprimer = new QPushButton(tab);
        push_supprimer->setObjectName(QStringLiteral("push_supprimer"));
        push_supprimer->setGeometry(QRect(600, 390, 201, 28));
        id_supp = new QLineEdit(tab);
        id_supp->setObjectName(QStringLiteral("id_supp"));
        id_supp->setGeometry(QRect(650, 360, 113, 20));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(620, 320, 161, 31));
        pushButton_stat = new QPushButton(tab);
        pushButton_stat->setObjectName(QStringLiteral("pushButton_stat"));
        pushButton_stat->setGeometry(QRect(350, 370, 101, 23));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, -20, 811, 501));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/248085488_591901992026832_2710901618884620913_n.png")));
        trie_nom = new QPushButton(tab);
        trie_nom->setObjectName(QStringLiteral("trie_nom"));
        trie_nom->setGeometry(QRect(20, 150, 75, 23));
        pushButton_id = new QPushButton(tab);
        pushButton_id->setObjectName(QStringLiteral("pushButton_id"));
        pushButton_id->setGeometry(QRect(110, 150, 75, 23));
        pushButton_prenom = new QPushButton(tab);
        pushButton_prenom->setObjectName(QStringLiteral("pushButton_prenom"));
        pushButton_prenom->setGeometry(QRect(200, 150, 75, 23));
        pushButton_cam = new QPushButton(tab);
        pushButton_cam->setObjectName(QStringLiteral("pushButton_cam"));
        pushButton_cam->setGeometry(QRect(350, 310, 101, 23));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 120, 47, 14));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 230, 113, 20));
        pushButton_pdf = new QPushButton(tab);
        pushButton_pdf->setObjectName(QStringLiteral("pushButton_pdf"));
        pushButton_pdf->setGeometry(QRect(350, 340, 101, 23));
        menu->addTab(tab, QString());
        label_2->raise();
        pt_ajouter->raise();
        nbr_heure->raise();
        nom->raise();
        id->raise();
        service->raise();
        bouton_modifier->raise();
        prenom->raise();
        label_9->raise();
        label->raise();
        label_11->raise();
        label_7->raise();
        label_8->raise();
        pushButton_chercherE->raise();
        tab_employes->raise();
        nbr_point->raise();
        label_10->raise();
        push_supprimer->raise();
        id_supp->raise();
        label_13->raise();
        pushButton_stat->raise();
        trie_nom->raise();
        pushButton_id->raise();
        pushButton_prenom->raise();
        pushButton_cam->raise();
        label_3->raise();
        lineEdit->raise();
        pushButton_pdf->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(-4, 3, 811, 451));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/248085488_591901992026832_2710901618884620913_n (1).png")));
        menu->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(6, 3, 801, 451));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/248085488_591901992026832_2710901618884620913_n (1).png")));
        menu->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_12 = new QLabel(tab_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(6, 3, 801, 451));
        label_12->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/248085488_591901992026832_2710901618884620913_n (1).png")));
        menu->addTab(tab_5, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1027, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        menu->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        label_14->setText(QString());
        client->setText(QApplication::translate("MainWindow", "Gestion Clients ", Q_NULLPTR));
        employes->setText(QApplication::translate("MainWindow", "Gestion Employes ", Q_NULLPTR));
        produit->setText(QApplication::translate("MainWindow", "Gestion Produits", Q_NULLPTR));
        fournisseurs->setText(QApplication::translate("MainWindow", "Gestion Fournisseurs ", Q_NULLPTR));
        rendez_vous->setText(QApplication::translate("MainWindow", "Gestion Rendez-vous ", Q_NULLPTR));
        menu->setTabText(menu->indexOf(tab_6), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        label_4->setText(QString());
        menu->setTabText(menu->indexOf(tab_3), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        pt_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        bouton_modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "nbr_point", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "nbr_heure ", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "id", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        pushButton_chercherE->setText(QApplication::translate("MainWindow", "chercher", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "service", Q_NULLPTR));
        push_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "pour supprimer un employe", Q_NULLPTR));
        pushButton_stat->setText(QApplication::translate("MainWindow", "statistique", Q_NULLPTR));
        label_2->setText(QString());
        trie_nom->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        pushButton_id->setText(QApplication::translate("MainWindow", "id", Q_NULLPTR));
        pushButton_prenom->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        pushButton_cam->setText(QApplication::translate("MainWindow", "camera", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "trier :", Q_NULLPTR));
        pushButton_pdf->setText(QApplication::translate("MainWindow", "pdf ", Q_NULLPTR));
        menu->setTabText(menu->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        label_5->setText(QString());
        menu->setTabText(menu->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        label_6->setText(QString());
        menu->setTabText(menu->indexOf(tab_4), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        label_12->setText(QString());
        menu->setTabText(menu->indexOf(tab_5), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
