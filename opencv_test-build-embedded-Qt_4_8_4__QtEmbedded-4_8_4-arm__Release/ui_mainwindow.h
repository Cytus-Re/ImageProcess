/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Nov 24 14:32:55 2021
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *load;
    QPushButton *close;
    QLabel *showImageLabel;
    QPushButton *salt;
    QPushButton *gaussian;
    QLabel *PSNR;
    QLabel *MMSIM;
    QLabel *P_num;
    QLabel *b;
    QLabel *g;
    QLabel *r;
    QLabel *showImageLabel_2;
    QPushButton *blur;
    QPushButton *g_blur;
    QPushButton *m_blur;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *salt_combo;
    QPushButton *para;
    QComboBox *mu;
    QComboBox *sigma;
    QLabel *showImageLabel_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *para_2;
    QComboBox *b_combo;
    QComboBox *g_combo;
    QComboBox *m_combo;
    QPushButton *exponential;
    QComboBox *ex_combo;
    QPushButton *random;
    QPushButton *export_file;
    QPushButton *bilater;
    QPushButton *c_av;
    QPushButton *c_med;
    QPushButton *c_gau;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1073, 574);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        load = new QPushButton(centralWidget);
        load->setObjectName(QString::fromUtf8("load"));
        load->setGeometry(QRect(400, 350, 101, 61));
        close = new QPushButton(centralWidget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(400, 430, 101, 61));
        showImageLabel = new QLabel(centralWidget);
        showImageLabel->setObjectName(QString::fromUtf8("showImageLabel"));
        showImageLabel->setGeometry(QRect(10, 30, 300, 300));
        showImageLabel->setStyleSheet(QString::fromUtf8("background-color:rgb(170, 170, 255)"));
        salt = new QPushButton(centralWidget);
        salt->setObjectName(QString::fromUtf8("salt"));
        salt->setGeometry(QRect(10, 340, 170, 26));
        gaussian = new QPushButton(centralWidget);
        gaussian->setObjectName(QString::fromUtf8("gaussian"));
        gaussian->setGeometry(QRect(210, 340, 170, 26));
        PSNR = new QLabel(centralWidget);
        PSNR->setObjectName(QString::fromUtf8("PSNR"));
        PSNR->setGeometry(QRect(870, 400, 57, 15));
        MMSIM = new QLabel(centralWidget);
        MMSIM->setObjectName(QString::fromUtf8("MMSIM"));
        MMSIM->setGeometry(QRect(870, 420, 57, 16));
        P_num = new QLabel(centralWidget);
        P_num->setObjectName(QString::fromUtf8("P_num"));
        P_num->setGeometry(QRect(960, 400, 57, 15));
        b = new QLabel(centralWidget);
        b->setObjectName(QString::fromUtf8("b"));
        b->setGeometry(QRect(960, 490, 57, 15));
        g = new QLabel(centralWidget);
        g->setObjectName(QString::fromUtf8("g"));
        g->setGeometry(QRect(960, 465, 57, 15));
        r = new QLabel(centralWidget);
        r->setObjectName(QString::fromUtf8("r"));
        r->setGeometry(QRect(960, 440, 57, 15));
        showImageLabel_2 = new QLabel(centralWidget);
        showImageLabel_2->setObjectName(QString::fromUtf8("showImageLabel_2"));
        showImageLabel_2->setGeometry(QRect(330, 30, 300, 300));
        showImageLabel_2->setStyleSheet(QString::fromUtf8("background-color:rgb(170, 170, 255)"));
        blur = new QPushButton(centralWidget);
        blur->setObjectName(QString::fromUtf8("blur"));
        blur->setGeometry(QRect(611, 340, 141, 26));
        g_blur = new QPushButton(centralWidget);
        g_blur->setObjectName(QString::fromUtf8("g_blur"));
        g_blur->setGeometry(QRect(611, 380, 141, 26));
        m_blur = new QPushButton(centralWidget);
        m_blur->setObjectName(QString::fromUtf8("m_blur"));
        m_blur->setGeometry(QRect(611, 420, 141, 26));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(870, 440, 57, 15));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(870, 465, 57, 15));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(870, 490, 57, 15));
        salt_combo = new QComboBox(centralWidget);
        salt_combo->setObjectName(QString::fromUtf8("salt_combo"));
        salt_combo->setGeometry(QRect(10, 370, 170, 25));
        para = new QPushButton(centralWidget);
        para->setObjectName(QString::fromUtf8("para"));
        para->setGeometry(QRect(850, 340, 141, 21));
        mu = new QComboBox(centralWidget);
        mu->setObjectName(QString::fromUtf8("mu"));
        mu->setGeometry(QRect(210, 370, 82, 25));
        sigma = new QComboBox(centralWidget);
        sigma->setObjectName(QString::fromUtf8("sigma"));
        sigma->setGeometry(QRect(300, 370, 82, 25));
        showImageLabel_3 = new QLabel(centralWidget);
        showImageLabel_3->setObjectName(QString::fromUtf8("showImageLabel_3"));
        showImageLabel_3->setGeometry(QRect(660, 30, 300, 300));
        showImageLabel_3->setStyleSheet(QString::fromUtf8("background-color:rgb(170, 170, 255)"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 0, 70, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(420, 0, 90, 20));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(750, 0, 111, 20));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        para_2 = new QPushButton(centralWidget);
        para_2->setObjectName(QString::fromUtf8("para_2"));
        para_2->setGeometry(QRect(850, 370, 141, 21));
        b_combo = new QComboBox(centralWidget);
        b_combo->setObjectName(QString::fromUtf8("b_combo"));
        b_combo->setGeometry(QRect(761, 340, 82, 25));
        g_combo = new QComboBox(centralWidget);
        g_combo->setObjectName(QString::fromUtf8("g_combo"));
        g_combo->setGeometry(QRect(761, 380, 82, 25));
        m_combo = new QComboBox(centralWidget);
        m_combo->setObjectName(QString::fromUtf8("m_combo"));
        m_combo->setGeometry(QRect(761, 420, 82, 25));
        exponential = new QPushButton(centralWidget);
        exponential->setObjectName(QString::fromUtf8("exponential"));
        exponential->setGeometry(QRect(10, 420, 170, 26));
        ex_combo = new QComboBox(centralWidget);
        ex_combo->setObjectName(QString::fromUtf8("ex_combo"));
        ex_combo->setGeometry(QRect(10, 450, 170, 25));
        random = new QPushButton(centralWidget);
        random->setObjectName(QString::fromUtf8("random"));
        random->setGeometry(QRect(210, 420, 170, 26));
        export_file = new QPushButton(centralWidget);
        export_file->setObjectName(QString::fromUtf8("export_file"));
        export_file->setGeometry(QRect(760, 450, 81, 31));
        bilater = new QPushButton(centralWidget);
        bilater->setObjectName(QString::fromUtf8("bilater"));
        bilater->setGeometry(QRect(610, 460, 141, 26));
        c_av = new QPushButton(centralWidget);
        c_av->setObjectName(QString::fromUtf8("c_av"));
        c_av->setGeometry(QRect(520, 340, 80, 26));
        c_med = new QPushButton(centralWidget);
        c_med->setObjectName(QString::fromUtf8("c_med"));
        c_med->setGeometry(QRect(520, 420, 80, 26));
        c_gau = new QPushButton(centralWidget);
        c_gau->setObjectName(QString::fromUtf8("c_gau"));
        c_gau->setGeometry(QRect(520, 380, 80, 26));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1073, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        load->setText(QApplication::translate("MainWindow", "load image", 0, QApplication::UnicodeUTF8));
        close->setText(QApplication::translate("MainWindow", "close", 0, QApplication::UnicodeUTF8));
        showImageLabel->setText(QString());
        salt->setText(QApplication::translate("MainWindow", "add Salt Pepper noise", 0, QApplication::UnicodeUTF8));
        gaussian->setText(QApplication::translate("MainWindow", "add Gaussian noise", 0, QApplication::UnicodeUTF8));
        PSNR->setText(QApplication::translate("MainWindow", "PSNR:", 0, QApplication::UnicodeUTF8));
        MMSIM->setText(QApplication::translate("MainWindow", "MSSIM:", 0, QApplication::UnicodeUTF8));
        P_num->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        b->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        g->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        r->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        showImageLabel_2->setText(QString());
        blur->setText(QApplication::translate("MainWindow", "Average Blur", 0, QApplication::UnicodeUTF8));
        g_blur->setText(QApplication::translate("MainWindow", "Gaussian Blur", 0, QApplication::UnicodeUTF8));
        m_blur->setText(QApplication::translate("MainWindow", "Median Blur", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "r:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "g:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "b:", 0, QApplication::UnicodeUTF8));
        salt_combo->clear();
        salt_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "100", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10000", 0, QApplication::UnicodeUTF8)
        );
        para->setText(QApplication::translate("MainWindow", "calculate(before blur)", 0, QApplication::UnicodeUTF8));
        mu->clear();
        mu->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "100", 0, QApplication::UnicodeUTF8)
        );
        sigma->clear();
        sigma->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "100", 0, QApplication::UnicodeUTF8)
        );
        showImageLabel_3->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "source", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "add noise", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "blur result", 0, QApplication::UnicodeUTF8));
        para_2->setText(QApplication::translate("MainWindow", "calculate(after blur)", 0, QApplication::UnicodeUTF8));
        b_combo->clear();
        b_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "3*3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5*5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8*8", 0, QApplication::UnicodeUTF8)
        );
        g_combo->clear();
        g_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "3*3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5*5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7*7", 0, QApplication::UnicodeUTF8)
        );
        m_combo->clear();
        m_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
        );
        exponential->setText(QApplication::translate("MainWindow", "add Exponential noise", 0, QApplication::UnicodeUTF8));
        ex_combo->clear();
        ex_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "100", 0, QApplication::UnicodeUTF8)
        );
        random->setText(QApplication::translate("MainWindow", "add Random noise", 0, QApplication::UnicodeUTF8));
        export_file->setText(QApplication::translate("MainWindow", "export", 0, QApplication::UnicodeUTF8));
        bilater->setText(QApplication::translate("MainWindow", "Bilateral Filter", 0, QApplication::UnicodeUTF8));
        c_av->setText(QApplication::translate("MainWindow", "Average_", 0, QApplication::UnicodeUTF8));
        c_med->setText(QApplication::translate("MainWindow", "Median_", 0, QApplication::UnicodeUTF8));
        c_gau->setText(QApplication::translate("MainWindow", "Gaussian_", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
