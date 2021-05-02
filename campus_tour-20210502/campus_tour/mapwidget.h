#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include<QGraphicsView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMouseEvent>

class MapWidget : public QGraphicsView{
    Q_OBJECT
public :
    MapWidget();
    void readMap();
    QPointF mapToMap(QPointF);

public :
    void slotZoom(int);

protected :
    //地图的显示功能
    void drawBackground(QPainter*painter, const QRectF &rect);
    void mouseMoveEvent(QMouseEvent *event);

private :
    QPixmap map;
    qreal zoom;
    QLabel *viewcoord;//视图坐标——以窗口左上角为原点
    QLabel *sceneCoord;//场景坐标——以场景中心为原点
    QLabel *mapCoord;//地图的坐标

    double x1, y1, x2, y2;

};

#endif // MAPWIDGET_H
