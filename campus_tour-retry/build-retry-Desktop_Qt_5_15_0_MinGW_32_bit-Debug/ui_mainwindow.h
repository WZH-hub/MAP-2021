/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *widget;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QWidget *tab_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1262, 779);
        MainWindow->setMaximumSize(QSize(1262, 779));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 0, 1271, 781));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setIconSize(QSize(16, 16));
        widget = new QWidget();
        widget->setObjectName(QString::fromUtf8("widget"));
        widget1 = new QWidget(widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(60, 90, 451, 41));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(widget1);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        comboBox_2 = new QComboBox(widget1);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout->addWidget(comboBox_2);

        comboBox_3 = new QComboBox(widget1);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        horizontalLayout->addWidget(comboBox_3);

        tabWidget->addTab(widget, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setStyleSheet(QString::fromUtf8("image: url(:/new/map.jpeg);"));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\350\265\267\347\202\271", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\345\214\273\345\212\241\345\256\244", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\350\277\220\345\212\250\345\234\272", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\351\233\201\345\214\227\345\233\255\345\214\227\345\214\272", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "\345\277\205\347\273\217\347\202\271\357\274\210\346\227\240\357\274\211", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "\345\214\273\345\212\241\345\256\244", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "\350\277\220\345\212\250\345\234\272", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "\351\233\201\345\214\227\345\233\255\345\214\227\345\214\272", nullptr));

        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "\347\273\210\347\202\271", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "\345\214\273\345\212\241\345\256\244", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "\350\277\220\345\212\250\345\234\272", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("MainWindow", "\351\233\201\345\214\227\345\233\255\345\214\227\345\214\272", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(widget), QCoreApplication::translate("MainWindow", "\351\200\211\351\241\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "map", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
