#include "mapwidget.h"
//#include <QSlider>
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QGraphicsScene>
#include <math.h>

MapWidget::MapWidget(){ //读取地图信息——用于描述地图信息的文件
    readMap();
    zoom= 60;
    int wid= map.width();
    int hei=map.height();

    //创建QGraphicsScene对象，连接主窗口
    QGraphicsScene * scene = new QGraphicsScene(this);
    scene->setSceneRect(-wid/2, -hei/2, wid, hei);
    setScene(scene);

    setCacheMode(CacheBackground);

    //地图缩放功能待补充

    setWindowTitle("MAP_WIDGET");
    setMinimumSize(600, 400);

}

void MapWidget::readMap(){  //读文件信息
    QString name;
    QFile mapFile("campus_info.txt");

    int ready = mapFile.open(QIODevice::ReadOnly);
    if(ready){
        QTextStream s(&mapFile);
        if(!s.atEnd()){
            s>>name;
            s >> x1 >> y1 >> x2 >> y2;
        }
    }
    map.load(name);
}

void MapWidget::drawBackground(QPainter * painter, const QRectF &rect){
    painter->drawPixmap(int (sceneRect().left()) + 10, int(sceneRect().top()) - 10, map);
}


//处理图片——把输入的坐标和图片中实际坐标转换，待修改

void MapWidget::mouseMoveEvent(QMouseEvent* event){ //鼠标&坐标

    QPoint viewPoint = event->pos();
    viewcoord->setText(QString::number(viewPoint.x()) + "," + QString::number(viewPoint.y()));

    QPointF scenePoint = mapToScene(viewPoint);
    sceneCoord->setText(QString::number(scenePoint.x()) + "," + QString::number(scenePoint.y()));

    QPointF xy = mapToMap(scenePoint);
    mapCoord->setText(QString::number(xy.x()) + "," + QString::number(xy.y()));
}

QPointF MapWidget::mapToMap(QPointF m){     //实际值和坐标转换
    QPointF xy;
    qreal w = sceneRect().width();
    qreal h = sceneRect().height();
    qreal x = x1 + ((w/2+m.x())*abs(x1-x2)/w);
    qreal y = y1 - ((h/2+m.y())*abs(y1-y2)/h);

    xy.setX(x);
    xy.setY(y);
    return xy;
}
