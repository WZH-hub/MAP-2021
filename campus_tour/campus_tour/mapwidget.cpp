#include "mapwidget.h"
#include <QSlider>         //滑动条
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QGraphicsScene>
#include <math.h>

MapWidget::MapWidget(){ //读取地图信息——用于描述地图信息的文件
    readMap();
    zoom=50;
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

void MapWidget::readMap(){
    QString name;
    QFile mapFile("info.txt");

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

void MapWidget::mouseMoveEvent(QMouseEvent* event){

    QPoint viewPoint = event->pos();
    viewcoord->setText(QString::number(viewPoint.x()) + "," + QString::number(viewPoint.y()));

    QPointF scenePoint = mapToScene(viewPoint);
    sceneCoord->setText(QString::number(scenePoint.x()) + "," + QString::number(scenePoint.y()));

    QPointF xy = mapToMap(scenePoint);
    mapCoord->setText(QString::number(xy.x()) + "," + QString::number(xy.y()));
}

QPointF MapWidget::mapToMap(QPointF m){
    QPointF xy;
    qreal w = sceneRect().width();
    qreal h = sceneRect().height();
    qreal x = x1 + ((w/2+m.x())*abs(x1-x2)/w);
    qreal y = y1 - ((h/2+m.y())*abs(y1-y2)/h);

    xy.setX(x);
    xy.setY(y);
    return xy;
}
