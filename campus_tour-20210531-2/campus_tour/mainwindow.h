#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QListView>
#include <QToolButton>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsView>
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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initMainwindow();

private:
    Ui::MainWindow *ui;
        QLabel * userLabel;
        QLabel *startLabel;
        QLabel *endLabel;
        QLabel *midLabel;
        QComboBox *userComboBox;
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

        int startX, startY, endX, endY,midX, midY;
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
