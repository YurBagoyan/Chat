/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *connectButton;
    QTextBrowser *textBrowser;
    QPushButton *sendButton;
    QWidget *widget;
    QPushButton *themeButton;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(533, 574);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName("connectButton");

        gridLayout->addWidget(connectButton, 0, 0, 1, 1);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");

        gridLayout->addWidget(textBrowser, 2, 0, 1, 3);

        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(8);
        sizePolicy.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setStyleStrategy(QFont::PreferDefault);
        sendButton->setFont(font);
        sendButton->setMouseTracking(false);
        sendButton->setContextMenuPolicy(Qt::DefaultContextMenu);
        sendButton->setToolTipDuration(1);
        sendButton->setStyleSheet(QString::fromUtf8("* {background-color: #00b2ff} "));
        sendButton->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        sendButton->setIconSize(QSize(16, 16));
        sendButton->setCheckable(false);

        gridLayout->addWidget(sendButton, 3, 2, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");

        gridLayout->addWidget(widget, 1, 0, 1, 1);

        themeButton = new QPushButton(centralwidget);
        themeButton->setObjectName("themeButton");

        gridLayout->addWidget(themeButton, 0, 1, 1, 2);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setAutoFillBackground(true);

        gridLayout->addWidget(lineEdit, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 533, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        connectButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
#if QT_CONFIG(shortcut)
        connectButton->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        sendButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
#if QT_CONFIG(shortcut)
        sendButton->setShortcut(QCoreApplication::translate("MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        themeButton->setText(QCoreApplication::translate("MainWindow", "Theme", nullptr));
#if QT_CONFIG(shortcut)
        themeButton->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
