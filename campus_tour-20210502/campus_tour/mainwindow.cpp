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
/*
数组使用的是序号减一
01 雁北园北区西北角     02 雁北园北区东北角     03 医务室      04 综合办公楼东北角     05 运动场
06 雁北园北区西南角     07 雁北园北区        08 洗衣店      09 教工食堂     10 二维码广场        11 综合办公楼    12 综合办公楼东南角
13 东配楼      14 雁北园南区    15 小麦铺      16 球场       17 雁北园南区西       18 学生食堂
19 西餐厅      20 学生活动中心&邮局    21 校西门      22 快递站      23 鸿雁路西     24 沙河商贸服务区
25 鸿雁路中西     26 鸿雁路中    27 图书馆      28 教学实验综合楼&报告厅      29 鸿雁路东
30 雁南园S2    31 雁南园S3
32 雁南园S3后侧
33 雁南园S4    34 雁南园S4后侧      35 雁南园S5北       36 雁南园S6        37 雁南园S5南
*/
    Map.arc[0][1].dis = Map.arc[1][0].dis = 145;
    Map.arc[0][4].dis = Map.arc[4][0].dis = 40;
    Map.arc[1][2].dis = Map.arc[2][1].dis = 80;
    Map.arc[2][3].dis = Map.arc[3][2].dis = 80;
    Map.arc[4][5].dis = Map.arc[5][4].dis = 50;
    Map.arc[5][6].dis = Map.arc[6][5].dis = 45;
    Map.arc[6][7].dis = Map.arc[7][6].dis = 100;
    Map.arc[7][8].dis = Map.arc[8][7].dis = 40;
    Map.arc[8][9].dis = Map.arc[9][8].dis = 40;
    Map.arc[9][10].dis = Map.arc[10][9].dis = 50;
    Map.arc[10][11].dis = Map.arc[11][10].dis = 30;
    Map.arc[11][12].dis = Map.arc[12][11].dis = 160;
    Map.arc[13][7].dis = Map.arc[7][13].dis = 30;
    Map.arc[14][9].dis = Map.arc[9][14].dis = 35;
    Map.arc[15][16].dis = Map.arc[16][15].dis = 10;
    Map.arc[16][22].dis = Map.arc[22][16].dis = 55;
    Map.arc[17][13].dis = Map.arc[13][17].dis = 35;
    Map.arc[17][18].dis = Map.arc[18][17].dis = 80;
    Map.arc[17][24].dis = Map.arc[24][17].dis = 40;
    Map.arc[18][14].dis = Map.arc[14][18].dis = 40;
    Map.arc[18][25].dis = Map.arc[25][18].dis = 30;
    Map.arc[18][19].dis = Map.arc[19][18].dis = 45;
    Map.arc[19][11].dis = Map.arc[11][19].dis = 100;
    Map.arc[20][21].dis = Map.arc[21][20].dis = 20;
    Map.arc[21][22].dis = Map.arc[22][21].dis = 300;
    Map.arc[22][23].dis = Map.arc[23][22].dis = 100;
    Map.arc[23][24].dis = Map.arc[24][23].dis = 35;
    Map.arc[24][25].dis = Map.arc[25][24].dis = 80;
    Map.arc[25][26].dis = Map.arc[26][25].dis = 80;
    Map.arc[26][27].dis = Map.arc[27][26].dis = 70;
    Map.arc[27][28].dis = Map.arc[28][27].dis = 90;
    Map.arc[28][12].dis = Map.arc[12][28].dis = 105;
    Map.arc[29][24].dis = Map.arc[24][29].dis = 48;
    Map.arc[29][30].dis = Map.arc[30][29].dis = 40;
    Map.arc[30][31].dis = Map.arc[31][30].dis = 80;
    Map.arc[30][32].dis = Map.arc[32][30].dis = 32;
    Map.arc[31][33].dis = Map.arc[33][31].dis = 30;
    Map.arc[33][22].dis = Map.arc[33][22].dis = 130;
    Map.arc[32][34].dis = Map.arc[34][32].dis = 40;
    Map.arc[34][33].dis = Map.arc[33][34].dis = 100;
    Map.arc[34][35].dis = Map.arc[35][34].dis = 130;
    Map.arc[35][36].dis = Map.arc[36][35].dis = 25;
    Map.arc[34][36].dis = Map.arc[36][34].dis = 50;

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

    QPixmap pixmap("E:/campus_tour/campus_tour/map_3.jpg");
        pixmap = pixmap.scaled(1216, 604, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QGraphicsPixmapItem * item = scene->addPixmap(pixmap);
        item->setPos(-100, 0);
    /*
    QGraphicsPixmapItem * item = scene->addPixmap(QPixmap("E:/campus_tour/campus_tour/map_3.jpg"));
    item->setPos(0, 0);
    */
}



void MainWindow::createAction(){

    /*
    //把寻路和按钮相关联

    //删除刚画出的路径

    //调用地图

    */


}

void MainWindow::createToolBar(){
    QToolBar * toolbar = addToolBar("功能");
    startLabel = new QLabel(tr("起点:"));
    startComboBox = new QComboBox;
    startComboBox->addItem(tr("医务室"));
    startComboBox->addItem(tr("运动场"));
    startComboBox->addItem(tr("雁北园北区"));
    startComboBox->addItem(tr("洗衣店"));
    startComboBox->addItem(tr("教工食堂"));
    startComboBox->addItem(tr("二维码广场"));
    startComboBox->addItem(tr("综合办公楼"));
    startComboBox->addItem(tr("东配楼"));
    startComboBox->addItem(tr("雁北园南区"));
    startComboBox->addItem(tr("小麦铺"));
    startComboBox->addItem(tr("球场"));
    startComboBox->addItem(tr("学生食堂"));
    startComboBox->addItem(tr("西餐厅"));
    startComboBox->addItem(tr("学生活动中心&邮局"));
    startComboBox->addItem(tr("校西门"));
    startComboBox->addItem(tr("菜鸟驿站"));

    startComboBox->addItem(tr("沙河商贸服务区"));
    startComboBox->addItem(tr("图书馆"));
    startComboBox->addItem(tr("教学实验综合楼&报告厅"));
    startComboBox->addItem(tr("雁南园S2"));
    startComboBox->addItem(tr("雁南园S3"));
    startComboBox->addItem(tr("雁南园S4"));
    startComboBox->addItem(tr("雁南园S5北"));//起点的名称
    startComboBox->addItem(tr("雁南园S6"));

    midLabel = new QLabel(tr("中间必经点:"));
    midComboBox = new QComboBox;
    midComboBox->addItem(tr("无"));
    midComboBox->addItem(tr("菜鸟驿站"));
    midComboBox->addItem(tr("学生食堂"));
    midComboBox->addItem(tr("教工食堂"));
    midComboBox->addItem(tr("图书馆"));
    midComboBox->addItem(tr("教学楼"));
    midComboBox->addItem(tr("校西门"));
    midComboBox->addItem(tr("雁南园"));
    midComboBox->addItem(tr("雁北园"));


    endLabel = new QLabel(tr("终点:"));
    endComboBox = new QComboBox;
    endComboBox->addItem(tr("医务室"));
    endComboBox->addItem(tr("运动场"));
    endComboBox->addItem(tr("雁北园北区"));
    endComboBox->addItem(tr("洗衣店"));
    endComboBox->addItem(tr("教工食堂"));
    endComboBox->addItem(tr("二维码广场"));
    endComboBox->addItem(tr("综合办公楼"));
    endComboBox->addItem(tr("东配楼"));
    endComboBox->addItem(tr("雁北园南区"));
    endComboBox->addItem(tr("小麦铺"));
    endComboBox->addItem(tr("球场"));
    endComboBox->addItem(tr("学生食堂"));
    endComboBox->addItem(tr("西餐厅"));
    endComboBox->addItem(tr("学生活动中心&邮局"));
    endComboBox->addItem(tr("校西门"));
    endComboBox->addItem(tr("菜鸟驿站"));

    endComboBox->addItem(tr("沙河商贸服务区"));
    endComboBox->addItem(tr("图书馆"));
    endComboBox->addItem(tr("教学实验综合楼&报告厅"));
    endComboBox->addItem(tr("雁南园S2"));
    endComboBox->addItem(tr("雁南园S3"));
    endComboBox->addItem(tr("雁南园S4"));
    endComboBox->addItem(tr("雁南园S5北"));//起点的名称
    endComboBox->addItem(tr("雁南园S6"));





    /*  功能按钮
    findLabel = new QLabel(tr("寻路"));
    findComboBox = new QComboBox;



    endLabel = new QLabel(tr("清除:"));
    endComboBox = new QComboBox;
//    */


    connect(startComboBox, SIGNAL(activated(int)), this, SLOT(setStartStation()));
    //connect(startComboBox, SIGNAL(activated(int)), this, SLOT(setMidStation()));
    connect(endComboBox, SIGNAL(activated(int)), this, SLOT(setEndStation()));

    toolbar->addWidget(startLabel);
    toolbar->addWidget(startComboBox);//起点设置

    toolbar->addSeparator();

    toolbar->addWidget(midLabel);
    toolbar->addWidget(midComboBox);//终点设置

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


//画图功能需要和图片匹配

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

    //vhg
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

