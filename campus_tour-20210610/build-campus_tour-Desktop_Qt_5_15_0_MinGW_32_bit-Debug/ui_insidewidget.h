/********************************************************************************
** Form generated from reading UI file 'insidewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSIDEWIDGET_H
#define UI_INSIDEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_insideWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *insideWidget)
    {
        if (insideWidget->objectName().isEmpty())
            insideWidget->setObjectName(QString::fromUtf8("insideWidget"));
        insideWidget->resize(968, 648);
        verticalLayoutWidget = new QWidget(insideWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 220, 160, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        stackedWidget = new QStackedWidget(insideWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(210, 20, 691, 571));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setStyleSheet(QString::fromUtf8("image: url(:/image/S4_1.jpg);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setStyleSheet(QString::fromUtf8("image: url(:/image/S4_2.jpg);"));
        stackedWidget->addWidget(page_2);

        retranslateUi(insideWidget);

        QMetaObject::connectSlotsByName(insideWidget);
    } // setupUi

    void retranslateUi(QWidget *insideWidget)
    {
        insideWidget->setWindowTitle(QCoreApplication::translate("insideWidget", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("insideWidget", "\344\270\200\346\245\274", nullptr));
        pushButton_2->setText(QCoreApplication::translate("insideWidget", "\344\272\214\346\245\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insideWidget: public Ui_insideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSIDEWIDGET_H
