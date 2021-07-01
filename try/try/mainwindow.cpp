#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *pStartButton = new QPushButton(this);
        pStartButton->setText(QString::fromLocal8Bit("start"));

        m_pLabel = new QLabel(this);
        m_pLabel->setText(QString::fromLocal8Bit("this one"));
        m_pLabel->setAlignment(Qt::AlignCenter);
        m_pLabel->setStyleSheet("color: rgb(0, 160, 230);");

        QPropertyAnimation *pAnimation = new QPropertyAnimation();
        pAnimation->setTargetObject(this);
        pAnimation->setPropertyName("alpha");
        pAnimation->setDuration(100000);
        pAnimation->setKeyValueAt(0, 255);
        pAnimation->setKeyValueAt(0.5, 100);
        pAnimation->setKeyValueAt(1, 255);
        pAnimation->setLoopCount(-1);  //永远运行，直到stop
        connect(pStartButton, SIGNAL(clicked(bool)), pAnimation, SLOT(start()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::alpha() const
{
    return m_nAlpha;
}

void MainWindow::setAlpha(const int alpha)
{
    m_nAlpha = alpha;
    QString strQSS = QString("color: rgb(0, 160, 230); background-color: rgba(10, 160, 105, %1);").arg(m_nAlpha);
    m_pLabel->setStyleSheet(strQSS);
}
