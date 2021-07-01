#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mapwidget.h"
#include <QToolButton>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QVector>
#include <QMouseEvent>
#include <QDialog>
#include <QPixmap>
#include <QGridLayout>
#include <QLineEdit>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QTime>
#include <QElapsedTimer>
#include <QDebug>
#include <QFile>
#include <QSignalMapper>

extern QElapsedTimer find_time;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createToolBar();
    void createAction();
    void setStart(int X, int Y);
    void setEnd(int X, int Y);
    void setMid(int X, int Y);
    void setNextPos (int index);
    void initScene();

    void printLog(QString s);//打印日志
    int timeChange();//将系统实际时间转换至程序时间，返回程序这一天的秒数
    QString printTime(int i);//将程序的秒数转为对应的时间，并用string输出

public slots:
    void setStartStation();
    void setEndStation();
    void setMidStation();
    void paintPath();
    void clear();
    //void revise();
    void callOtherMap();
    //void showDialog();

private :
    MapWidget *mapWidget;
    QLabel *startLabel;
    QLabel *endLabel;
    QLabel *midLabel;
    QComboBox *startComboBox;
    QComboBox *endComboBox;
    QComboBox *midComboBox;

    QLabel *findLabel;
    QLabel *clearLabel;


    //QComboBox *reviseComboBox;

    QAction *findPathAction;
    QAction *clearAction;
    QAction *reviseAction;
    QAction *callMap;

    QGraphicsScene *scene;
    QGraphicsView *view;

    int startX, startY, endX, endY, midX, midY;
    QVector<int> nextPath;


    //关于图和寻路算法的实现
    struct Arc{//边信息
        int dis;//权值
    };

    static const int MAX_VERTEX_NUM = 115;
    static const int INF = 9999;

    struct MGraph{

        QVector<int> vex;//顶点类型
        Arc arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//存储边的矩阵
        int vexnum;//顶点数
        int arcnum;//边数
};

class findShortestPath{
    public:
        findShortestPath();
        MGraph Map;

        void createGraph();
        int prev[MAX_VERTEX_NUM];//最短路上各前驱结点
        int distance[MAX_VERTEX_NUM];//表示权值
        bool used[MAX_VERTEX_NUM];//已被使用过的图
        void findPath(int startPos);//求出从起点到各点的最短路径。可能要改为用终点
        QVector<int> getPath(int endPos);//到终点的最短路径
    };

    findShortestPath *tour;

protected:  //鼠标事件
    void mouseDoubleClikEvent(QMouseEvent*eve);

    //5.29
    virtual void mousePressEvent(QMouseEvent *event) override;

private:
    QPixmap somePlace;//需要特殊展示的地点，可有多个

    QString strPath; //读取文件的路径
    QLabel *label;


};
#endif // MAINWINDOW_H
