#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


//    QFrame *frame = new QFrame;
//    frame->resize(30,30);
//    QPixmap pixmap("F:/Qt5/2021-MAP/campus_tour-20210601/campus_tour/dot.png");
//    QPalette palette;
//    palette.setBrush(frame->backgroundRole(),QBrush(pixmap));
//    frame->setPalette(palette);
//    //frame->setMask(pixmap.mask());
//    frame->setAutoFillBackground(true);
//    frame->show();



//    /*  声明动画类，并将控制对象 this (this一定是继承自QObject的窗口部件)  以及属性名 "geometry" 传入构造函数  */
//    QPropertyAnimation* animation = new QPropertyAnimation(&w, "geometry");
//    /*  设置动画持续时长为 2 秒钟  */
//    animation->setDuration(2000);
//    /*  设置动画的起始状态 起始点 (1,2)  起始大小 (3,4)  */
//    animation->setStartValue(QRect(1, 2, 3, 4));
//    /*  设置动画的结束状态 结束点 (100,200)  结束大小 (300,400)  */
//    animation->setEndValue(QRect(100, 200, 300, 400));
//    /*  设置动画效果  */
//    animation->setEasingCurve(QEasingCurve::OutInExpo);
//    /*  开始执行动画 QAbstractAnimation::DeleteWhenStopped 动画结束后进行自清理(效果就好像智能指针里的自动delete animation) */
//    animation->start(QAbstractAnimation::DeleteWhenStopped);
    return a.exec();
}
