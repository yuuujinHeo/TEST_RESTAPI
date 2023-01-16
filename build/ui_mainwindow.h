/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *BTN_GET_TOKEN;
    QTextEdit *TE_POST;
    QTextEdit *TE_REPLY;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *LE_ERROR_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_5;
    QLineEdit *LE_ERROR_3;
    QLineEdit *LE_ERROR_1;
    QLineEdit *LE_TOKEN;
    QLineEdit *LE_MANAGER;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_9;
    QLineEdit *LE_PLATFORM;
    QLineEdit *LE_RECEIVER;
    QPushButton *BTN_GET_TEMPLETE;
    QPushButton *BTN_SET_TEMPLETE;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 726);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BTN_GET_TOKEN = new QPushButton(centralwidget);
        BTN_GET_TOKEN->setObjectName(QString::fromUtf8("BTN_GET_TOKEN"));
        BTN_GET_TOKEN->setGeometry(QRect(480, 30, 131, 51));
        TE_POST = new QTextEdit(centralwidget);
        TE_POST->setObjectName(QString::fromUtf8("TE_POST"));
        TE_POST->setGeometry(QRect(60, 320, 291, 301));
        TE_REPLY = new QTextEdit(centralwidget);
        TE_REPLY->setObjectName(QString::fromUtf8("TE_REPLY"));
        TE_REPLY->setGeometry(QRect(430, 320, 291, 301));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 290, 56, 12));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(440, 300, 56, 12));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 441, 248));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        LE_ERROR_2 = new QLineEdit(layoutWidget);
        LE_ERROR_2->setObjectName(QString::fromUtf8("LE_ERROR_2"));
        LE_ERROR_2->setMinimumSize(QSize(300, 30));

        gridLayout->addWidget(LE_ERROR_2, 5, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        LE_ERROR_3 = new QLineEdit(layoutWidget);
        LE_ERROR_3->setObjectName(QString::fromUtf8("LE_ERROR_3"));
        LE_ERROR_3->setMinimumSize(QSize(300, 30));

        gridLayout->addWidget(LE_ERROR_3, 6, 1, 1, 1);

        LE_ERROR_1 = new QLineEdit(layoutWidget);
        LE_ERROR_1->setObjectName(QString::fromUtf8("LE_ERROR_1"));
        LE_ERROR_1->setMinimumSize(QSize(300, 30));

        gridLayout->addWidget(LE_ERROR_1, 4, 1, 1, 1);

        LE_TOKEN = new QLineEdit(layoutWidget);
        LE_TOKEN->setObjectName(QString::fromUtf8("LE_TOKEN"));
        LE_TOKEN->setMinimumSize(QSize(300, 30));

        gridLayout->addWidget(LE_TOKEN, 0, 1, 1, 1);

        LE_MANAGER = new QLineEdit(layoutWidget);
        LE_MANAGER->setObjectName(QString::fromUtf8("LE_MANAGER"));
        LE_MANAGER->setMinimumSize(QSize(300, 30));

        gridLayout->addWidget(LE_MANAGER, 3, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        LE_PLATFORM = new QLineEdit(layoutWidget);
        LE_PLATFORM->setObjectName(QString::fromUtf8("LE_PLATFORM"));
        LE_PLATFORM->setMinimumSize(QSize(300, 30));

        gridLayout->addWidget(LE_PLATFORM, 2, 1, 1, 1);

        LE_RECEIVER = new QLineEdit(layoutWidget);
        LE_RECEIVER->setObjectName(QString::fromUtf8("LE_RECEIVER"));
        LE_RECEIVER->setMinimumSize(QSize(300, 30));

        gridLayout->addWidget(LE_RECEIVER, 1, 1, 1, 1);

        BTN_GET_TEMPLETE = new QPushButton(centralwidget);
        BTN_GET_TEMPLETE->setObjectName(QString::fromUtf8("BTN_GET_TEMPLETE"));
        BTN_GET_TEMPLETE->setGeometry(QRect(620, 30, 131, 51));
        BTN_SET_TEMPLETE = new QPushButton(centralwidget);
        BTN_SET_TEMPLETE->setObjectName(QString::fromUtf8("BTN_SET_TEMPLETE"));
        BTN_SET_TEMPLETE->setGeometry(QRect(480, 110, 131, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        BTN_GET_TOKEN->setText(QCoreApplication::translate("MainWindow", "get API token", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "POST", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "REPLY", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\353\247\244\354\236\245\353\252\205 :", nullptr));
        LE_ERROR_2->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\354\227\220\353\237\254\353\252\251\353\241\235 2 : ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\354\227\220\353\237\254\353\252\251\353\241\235 3 : ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TOKEN :", nullptr));
        LE_ERROR_3->setText(QString());
        LE_ERROR_1->setText(QString());
        LE_TOKEN->setText(QString());
        LE_MANAGER->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\352\263\240\352\260\235\353\252\205 : ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\354\227\220\353\237\254\353\252\251\353\241\235 1 : ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "CALL : ", nullptr));
        LE_PLATFORM->setText(QString());
        LE_RECEIVER->setText(QString());
        BTN_GET_TEMPLETE->setText(QCoreApplication::translate("MainWindow", "get Templete", nullptr));
        BTN_SET_TEMPLETE->setText(QCoreApplication::translate("MainWindow", "set Templete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
