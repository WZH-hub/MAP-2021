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
#include <QtWidgets/QTextEdit>
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
    QTextEdit *textEdit;

    void setupUi(QWidget *insideWidget)
    {
        if (insideWidget->objectName().isEmpty())
            insideWidget->setObjectName(QString::fromUtf8("insideWidget"));
        insideWidget->resize(968, 648);
        verticalLayoutWidget = new QWidget(insideWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 90, 160, 171));
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
        stackedWidget->setGeometry(QRect(230, 30, 691, 571));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setStyleSheet(QString::fromUtf8("image: url(:/image/S4_1.jpg);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setStyleSheet(QString::fromUtf8("image: url(:/image/S4_2.jpg);"));
        stackedWidget->addWidget(page_2);
        textEdit = new QTextEdit(insideWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 310, 171, 281));

        retranslateUi(insideWidget);

        QMetaObject::connectSlotsByName(insideWidget);
    } // setupUi

    void retranslateUi(QWidget *insideWidget)
    {
        insideWidget->setWindowTitle(QCoreApplication::translate("insideWidget", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("insideWidget", "\344\270\200\346\245\274", nullptr));
        pushButton_2->setText(QCoreApplication::translate("insideWidget", "\344\272\214\346\245\274", nullptr));
        textEdit->setHtml(QCoreApplication::translate("insideWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\224\250\346\210\267\350\277\233\345\205\245S4\345\220\216\357\274\214\345\217\257\344\273\245\346\240\271\346\215\256\347\273\231\345\207\272\347\232\204\344\270\200\346\245\274\343\200\201\344\272\214\346\245\274\347\232\204\345\234\260\345\233\276\357\274\214\345\257\273\346\211\276\350\207\252\345\267\261\346\203\263\350\246\201\345\216\273\347\232\204\346\210\277\351\227\264\357\274\214\347\272\242\347\202\271\346\240\207\350\256\260\345\244\204\346\230\257S4\351\227\250\345\217\243\357\274\214\350\241\250\347\244\272\347\224\250\346\210\267\350\277\233\345"
                        "\205\245\346\245\274\345\206\205\345\220\216\347\232\204\351\273\230\350\256\244\344\275\215\347\275\256\343\200\202</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insideWidget: public Ui_insideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSIDEWIDGET_H
