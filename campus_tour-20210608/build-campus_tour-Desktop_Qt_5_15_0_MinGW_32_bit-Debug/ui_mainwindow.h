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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *QComboBox;
    QAction *actionssd;
    QAction *actionsdsad;
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QWidget *centralwidget;
    QWidget *widget;
    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_3;
    QTextBrowser *log;
    QTextBrowser *around;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1700, 1100);
        MainWindow->setMinimumSize(QSize(1700, 1100));
        MainWindow->setMaximumSize(QSize(1700, 1100));
        QComboBox = new QAction(MainWindow);
        QComboBox->setObjectName(QString::fromUtf8("QComboBox"));
        actionssd = new QAction(MainWindow);
        actionssd->setObjectName(QString::fromUtf8("actionssd"));
        actionsdsad = new QAction(MainWindow);
        actionsdsad->setObjectName(QString::fromUtf8("actionsdsad"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QString::fromUtf8("action_6"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setLayoutDirection(Qt::RightToLeft);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1700, 1000));
        widget->setMinimumSize(QSize(1700, 1000));
        widget->setMaximumSize(QSize(1700, 1000));
        widget->setStyleSheet(QString::fromUtf8("image: url(:/image/map.png);"));
        frame = new QFrame(widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 41, 31));
        frame->setStyleSheet(QString::fromUtf8("image: url(:/image/mush.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(40, 0, 41, 31));
        frame_2->setStyleSheet(QString::fromUtf8("image: url(:/image/master.jpg);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(widget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(80, 0, 41, 31));
        frame_3->setStyleSheet(QString::fromUtf8("image: url(:/image/turtle.png);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        log = new QTextBrowser(widget);
        log->setObjectName(QString::fromUtf8("log"));
        log->setGeometry(QRect(0, 131, 251, 741));
        around = new QTextBrowser(widget);
        around->setObjectName(QString::fromUtf8("around"));
        around->setGeometry(QRect(1480, 130, 211, 241));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QFont font;
        font.setPointSize(9);
        toolBar->setFont(font);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QComboBox->setText(QCoreApplication::translate("MainWindow", "\350\265\267\347\202\271", nullptr));
        actionssd->setText(QCoreApplication::translate("MainWindow", "ssd]", nullptr));
        actionsdsad->setText(QCoreApplication::translate("MainWindow", "sdsad", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\345\214\273\345\212\241\345\256\244", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\350\277\220\345\212\250\345\234\272", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\351\233\201\345\214\227\345\233\255\345\214\227\345\214\272", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\345\214\273\345\212\241\345\256\244", nullptr));
        action_5->setText(QCoreApplication::translate("MainWindow", "\350\277\220\345\212\250\345\234\272", nullptr));
        action_6->setText(QCoreApplication::translate("MainWindow", "\351\233\201\345\214\227\345\233\255\345\214\227\345\214\272", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
