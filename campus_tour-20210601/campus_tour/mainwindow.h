#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QGraphicsLineItem>
#include <QListView>
#include <QMessageBox>
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
#include <QTime>
#include <QElapsedTimer>
#include <QLineEdit>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QDebug>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

//#include "findShortestPath.h"
//#include "mapwidget.h"

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
    //void initScene();
    void initMainWindow();
    void printLog(const QString& s);//打印日志


public slots:
    //void setStartStation();
    //void setMidStation();
    //void setEndStation();
    void paintPath();
    void clear();
    void continueAnimation();//绘制小点用来表示移动
    //void revise();
    //void callOtherMap();
    //void showDialog();

private :

    Ui::MainWindow *ui;

    static const int MAX_VERTEX_NUM = 115;
    static const int INF = 9999;

    //MapWidget *mapWidget
    //QComboBox *reviseComboBox;
    //关于图和寻路算法的实现
    typedef struct {//边信息
        int dis;//权值
    }Arc;

    typedef struct {

        QVector<int> vex;//顶点类型
        Arc arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//存储边的矩阵
        int vexnum;//顶点数
        int arcnum;//边数
    }MGraph;

    class findShortestPath{
        public:

            MGraph Map;

            findShortestPath();
            ~findShortestPath();
            void createGraph();
            int prev[MAX_VERTEX_NUM];//最短路上各前驱结点
            int distance[MAX_VERTEX_NUM];//表示权值
            bool used[MAX_VERTEX_NUM];//已被使用过的图
            void findPath(int startPos);//求出从起点到各点的最短路径。可能要改为用终点
            QVector<int> getPath(int endPos);//到终点的最短路径
    };


    findShortestPath *tour;

protected:  //鼠标事件
    void mouseDoubleClikEvent(QMouseEvent*event);
    //virtual void paintEvent(QPaintEvent* event)override;
    //5.29
    virtual void mousePressEvent(QMouseEvent *event) override;

private:

    QAction *findPathAction,*clearAction;

    QPixmap somePlace;//需要特殊展示的地点，可有多个
    QString strPath; //读取文件的路径
    QLabel *label;


};
#endif // MAINWINDOW_H
