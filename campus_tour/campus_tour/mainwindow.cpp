#include "mainwindow.h"
#include <qdebug.h>
#include <QToolBar>
#include<QtAlgorithms>
#include <iostream>
#include <windows.h>

//移除了ui文件及其头文件

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, ui(new Ui::MainWindow)
{
    setWindowTitle("BUPT校园导览系统");
    //补充寻路功能
    tour = new MainWindow::findShortestPath();  //整个程序运行时的对象
    tour->createGraph();

    scene=new QGraphicsScene;
    scene->setSceneRect(-80, -90, 800, 800);  //图片布局
    initScene();

    view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(800, 800);
    view->show();
    setCentralWidget(view);

    createAction();         //定义各种行为——点击等
    createToolBar();        //创建工具栏
    setMinimumSize(800, 800);
    Sleep(3000);

    //ui->setupUi(this);
}

MainWindow::findShortestPath::findShortestPath(){
    //创建图，把边设置为最长或不可达，设置结点数、边数
    Map.vexnum=80;
    for(int i=0; i<Map.vexnum; i++)
        Map.vex.push_back(i);
    Map.arcnum = 200;
    for(int i =0; i<Map.vexnum; i++){
        for(int j =0 ; j<Map.vexnum; j++){
            if(i==j)
                Map.arc[i][j].dis=0;
            else
                Map.arc[i][j].dis=INF;
        }
    }
}

void MainWindow::findShortestPath::createGraph(){
    //输入边的信息——给数组元素赋值——复制粘贴保存好的边

}

void MainWindow::findShortestPath::findPath(int startPos){  //迪杰斯特拉算法，求出起点到各点的最短距离
    //赋初始值
    for(int i =0; i<Map.vexnum; i++)    {distance[i]=INF;}
    for(int i =0; i<Map.vexnum; i++)    {used[i]=false;}
    for(int i =0; i<Map.vexnum; i++)    {prev[i]=-1;}

    distance[startPos]=0;//第一个点的距离

    while(true){
        int v =-1;
        for(int u=0; u<Map.vexnum;u++){
            if(!used[u]&&(v==-1||distance[u]<distance[v]))
                v=u;
        }

        if(v==-1)   break;  //全被记录过或者
        used[v] = true;

        for(int u=0; u<Map.vexnum; u++){
            if(distance[u]>distance[v]+Map.arc[v][u].dis){  //如果u距离大于u-v的距离，更新并记录
                distance[u]=distance[v]+Map.arc[v][u].dis;
                prev[u]=v;
            }
        }
    }

}

//求所需要的最短路径
QVector<int> MainWindow::findShortestPath::getPath(int endPos){
    //用一个vector装路径上各结点，数组中是倒着的，所以要reverse
    QVector<int> pathRes;

    for(; endPos!=-1; endPos = prev[endPos]){
        pathRes.push_back(endPos);
    }
    std::reverse(pathRes.begin(), pathRes.end());

    return pathRes;
}

void MainWindow::initScene(){   //初始化界面
    QGraphicsPixmapItem * item = scene->addPixmap(QPixmap("E:/campus_tour/campus_tour/map_3.jpg"));
    item->setPos(0, 0);
}



void MainWindow::createAction(){

    /*
    //把寻路和按钮相关联

    //清理刚产生的路径

    //调用地图

    */


}

void MainWindow::createToolBar(){
    QToolBar * toolbar = addToolBar("功能");
    startLabel = new QLabel(tr("起点:"));
    startComboBox = new QComboBox;
    startComboBox->addItem(tr("雁南园S1"));//起点的名称
    startComboBox->addItem(tr("雁南园S2"));
    startComboBox->addItem(tr("雁南园S3"));
    startComboBox->addItem(tr("雁南园S4"));
    startComboBox->addItem(tr("雁南园S5"));
    startComboBox->addItem(tr("雁南园S6"));
    //startComboBox->addItem(tr(""));

    endLabel = new QLabel(tr("终点:"));
    endComboBox = new QComboBox;
    endComboBox->addItem(tr("教工食堂"));//终点名称
    endComboBox->addItem(tr("学生食堂"));
    endComboBox->addItem(tr("体育场"));
    endComboBox->addItem(tr("学生活动中心"));
    endComboBox->addItem(tr("甲子钟"));
    endComboBox->addItem(tr("小南门"));

    /*
    findLabel = new QLabel(tr("寻路"));
    findComboBox = new QComboBox;



    endLabel = new QLabel(tr("清除:"));
    endComboBox = new QComboBox;
//    */


    connect(startComboBox, SIGNAL(activated(int)), this, SLOT(setStartStation()));
    connect(endComboBox, SIGNAL(activated(int)), this, SLOT(setEndStation()));

    toolbar->addWidget(startLabel);
    toolbar->addWidget(startComboBox);//起点设置

    toolbar->addSeparator();

    toolbar->addWidget(endLabel);
    toolbar->addWidget(endComboBox);//终点设置
    /*
    toolbar->addSeparator();
    toolbar->addWidget(endLabel);
    toolbar->addWidget(endComboBox);//按钮

    toolbar->addSeparator();
    toolbar->addWidget(endLabel);
    toolbar->addWidget(endComboBox);//按钮
*/

}

//设置起点和终点
void MainWindow::setStart(int X, int Y){
    startX = X;
    startY = Y;
}

void MainWindow::setEnd(int X, int Y){
    endX = X;
    endY = Y;
}

//设置起点和终点坐标
void MainWindow::setStartStation(){
    switch (startComboBox->currentIndex ()) {
    /*
    case 0:
          setEnd(0, 0);
         break;

    case n:
    default:
        break;
        */
    }
}

void MainWindow::setEndStation(){
    switch (endComboBox->currentIndex ()) {
        /*
    case 0:
        setEnd(0, 4);
        break;
    case n:

    default:
        break;
       */
    }
}

//设置下一个点
void MainWindow::setNextPos(int index){
    switch(index){
    case 0:

        break;
    case 1:

        break;
    default:
        break;
    }
}


void MainWindow::paintPath(){
    QVector<QPoint> vec;

    tour->findPath(startComboBox->currentIndex());  //根据起点寻路
    nextPath = tour->getPath(endComboBox->currentIndex());      //根据终点选择绘制路线

    clear();//清除界面以准备绘制路线

    QGraphicsPathItem *item = new QGraphicsPathItem();//用路径项和笔把路线画出来
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::blue);
    item->setPen(pen);
    item->setFlag(QGraphicsItem::ItemIsPanel);


    for(int i = 1; i< nextPath.size(); i++ ){
        qDebug() << nextPath[i] <<"_";
    }
    scene->addItem(item);

    QPainterPath way;
    way.moveTo(startX , startY );

    for(int i = 1; i < nextPath.size(); i++){   //把坐标存入路径中
        setNextPos(nextPath[i]);
        way.lineTo(endX , endY );
    }

    item->setPath(way);

}

//清理所画的path
void MainWindow::clear(){
    QList<QGraphicsItem*> listItem = scene->items();
    while(!listItem.empty()){
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
    QGraphicsPixmapItem *item = scene->addPixmap(QPixmap("E:/campus_tour/campus_tour/map_3.jpg"));
    item->setPos(-500, -420);
}


//鼠标事件          mouseDoubleClikEvent
void MainWindow::mouseDoubleClikEvent(QMouseEvent *e)
{
    QDialog * dialog = new QDialog;
    QGridLayout *layout = new QGridLayout(dialog);
    label = new QLabel;


}

//打开另一个图片
void MainWindow::callOtherMap ()
{
    mapWidget = new MapWidget;
    mapWidget->show ();
}


MainWindow::~MainWindow()
{
    //delete ui;
}

