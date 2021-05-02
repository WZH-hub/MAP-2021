#include "mainwindow.h"
#include "mapwidget.h"
#include <QApplication>
#include<QFont>
#include <QDebug>
#include <QPixmap>
#include <QSplashScreen>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap("E:/campus_tour/campus_tour/Bupt.jpeg");         //创建启动界面图片
    QSplashScreen splash(pixmap);   //启动界面
    splash.show();                  //显示图片


    a.processEvents();              //显示启动动画同时接收事件

    QFont font("ARPL KaitiM GB", 20);//设置字体
    font.setBold(true);
    a.setFont(font);

    qDebug()<<"启动中";

    MainWindow w;
    w.show();

    //主窗体之后的结束动画
    //splash.finish (&w);

    return a.exec();
}
