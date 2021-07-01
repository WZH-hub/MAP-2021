#include "mainwindow.h"
#include "mapwidget.h"
#include <QApplication>
#include <QFont>
#include <QDebug>
#include <QPixmap>
#include <QSplashScreen>
#include <qtextcodec.h>

#include <QApplication>

QElapsedTimer find_time;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QPixmap pixmap("../Bupt.jpeg");         //创建启动界面图片
    QSplashScreen splash(pixmap);   //启动界面
    splash.show();                  //显示图片


    a.processEvents();              //接收事件

    QFont font("Microsoft Yahei", 18);//设置字体
    font.setBold(true);
    a.setFont(font);
    //防止中文乱码
    #if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    #if _MSC_VER
        QTextCodec *codec = QTextCodec::codecForName("gbk");
    #else
        QTextCodec *codec = QTextCodec::codecForName("utf-8");
    #endif
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForCStrings(codec);
        QTextCodec::setCodecForTr(codec);
    #else
        QTextCodec *codec = QTextCodec::codecForName("utf-8");
        QTextCodec::setCodecForLocale(codec);
    #endif

    qDebug()<<"启动中";

    find_time.start();

    MainWindow w;
    w.show();

    QDir dir;
       QString pathname;
       //修改相对路径为exe目录路径
       QDir::setCurrent(QCoreApplication::applicationDirPath());
       pathname = dir.currentPath();
       qDebug()<<pathname;


    //结束动画
    //splash.finish (&w);

    return a.exec();
}
