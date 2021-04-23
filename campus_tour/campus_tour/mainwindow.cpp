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
    scene->setSceneRect(-100, -100, 700, 700);
    initScene();

    view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(800, 800);
    view->show();
    setCentralWidget(view);

    createAction();         //定义各种行为——点击等
    createToolBar();        //创建工具栏
    setMinimumSize(800, 800);//
    Sleep(2000);

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
    //输入边的信息——给数组元素赋值

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

        if(v==-1)   break;
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
    QVector<int> pathRes;

    for(; endPos!=-1; endPos = prev[endPos]){
        pathRes.push_back(endPos);
    }
    std::reverse(pathRes.begin(), pathRes.end());

    return pathRes;
}

void MainWindow::initScene(){
    QGraphicsPixmapItem * item = scene->addPixmap(QPixmap("Bupt.jpg"));
    item->setPos(-500, -420);
}



void MainWindow::createAction(){

    //把寻路和按钮相关联
    findPathAction = new QAction(QIcon(""), tr("寻路"), this);
    findPathAction->setShortcut(tr("Q"));
    findPathAction->setStatusTip(tr("寻找路径"));
    connect (findPathAction, SIGNAL(triggered(bool)), this, SLOT(paintPath()));

    //清理刚产生的路径
    clearAction = new QAction(QIcon(""), tr("清除"), this);
    clearAction->setShortcut(tr("W"));
    clearAction->setStatusTip(tr("清除结果"));
    connect(clearAction, SIGNAL(triggered(bool)), this, SLOT(clear()));

    //调用地图
    callMap = new QAction(QIcon(""), tr("测试用地图"), this);
    callMap->setShortcut(tr("E"));
    callMap->setStatusTip(tr("调用地图"));
    connect(callMap, SIGNAL(triggered(bool)), this, SLOT(callOtherMap()));

}

void MainWindow::createToolBar(){
    QToolBar * toolbar = addToolBar("选项");
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



    endLabel = new QLabel(tr("终点:"));
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
    toolbar->addWidget(endComboBox);//寻路按钮

    toolbar->addSeparator();
    toolbar->addWidget(endLabel);
    toolbar->addWidget(endComboBox);//清除按钮
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
        setStart(-660, -534); break;
    case 1:
        setStart (-673, -490); break;
    case 2:
        setStart (-682, -446); break;
    case 3:
        setStart (-690, -400); break;
    case 4:
        setStart (-701, -355); break;
    case 5:
        setStart (-711, -310); break;
    case 6:
        setStart (-457, -555); break;
    case 7:
        setStart (-449, -485); break;
    case 8:
        setStart(-446, -432); break;
    case 9:
        setStart (-451, -400); break;
    case 10:
        setStart (-328, -368); break;
    case 11:
        setStart (-720, -247); break;
    case 12:
        setStart (-789, -252); break;
    case 13:
        setStart (-721, -517); break;
    case 14:
        setStart (-271, -540); break;
    case 15:
        setStart (-721, -439); break;
    case 16:
        setStart (-274, -495); break;
    case 17:
        setStart (-180, -552); break;
    case 18:
        setStart (-178, -508); break;
    case 19:
        setStart (-179, -456); break;
    case 20:
        setStart (-41, -552); break;
    case 21:
        setStart (-56, -500); break;
    case 22:
        setStart (-59, -448); break;
    case 23:
        setStart (-83, -393); break;
    case 24:
        setStart (-69, -351); break;
    case 25:
        setStart (-1070, -92); break;
    case 26:
        setStart (-438, -125); break;
    case 27:
        setStart (-721, -119); break;
    case 28:
        setStart (-550, -122); break;
    case 29:
        setStart (-555, -263); break;
    case 30:
        setStart (-498, -235); break;
    case 31:
        setStart (-439, -306); break;
    case 32:
        setStart (-390, -344); break;
    case 33:
        setStart (-226, -386); break;
    case 34:
        setStart (-144, -370); break;
    case 35:
        setStart (-218, -454); break;
    case 36:
        setStart (-223, -495); break;
    case 37:
        setStart (-513, -379); break;
    default:
        break;
        */
    }
}

void MainWindow::setEndStation(){
    switch (endComboBox->currentIndex ()) {
        /*
    case 0:
        setEnd(-660, -534); break;
    case 1:
        setEnd (-673, -490); break;
    case 2:
        setEnd (-682, -446); break;
    case 3:
        setEnd (-690, -400); break;
    case 4:
        setEnd (-701, -355); break;
    case 5:
        setEnd (-711, -310); break;
    case 6:
        setEnd (-457, -555); break;
    case 7:
        setEnd (-449, -485); break;
    case 8:
        setEnd (-446, -432); break;
    case 9:
        setEnd (-451, -400); break;
    case 10:
        setEnd (-328, -368); break;
    case 11:
        setEnd (-720, -247); break;
    case 12:
        setEnd (-789, -252); break;
    case 13:
        setEnd (-721, -517); break;
    case 14:
        setEnd (-271, -540); break;
    case 15:
        setEnd (-721, -439); break;
    case 16:
        setEnd (-274, -495); break;
    case 17:
        setEnd (-180, -552); break;
    case 18:
        setEnd (-178, -508); break;
    case 19:
        setEnd (-179, -456); break;
    case 20:
        setEnd (-41, -552); break;
    case 21:
        setEnd (-56, -500); break;
    case 22:
        setEnd (-59, -448); break;
    case 23:
        setEnd (-83, -393); break;
    case 24:
        setEnd (-69, -351); break;
    case 25:
        setEnd (-1070, -92); break;
    case 26:
        setEnd (-438, -125); break;
    case 27:
        setEnd (-721, -119); break;
    case 28:
        setEnd (-550, -122); break;
    case 29:
        setEnd (-555, -263); break;
    case 30:
        setEnd (-498, -235); break;
    case 31:
        setEnd (-439, -306); break;
    case 32:
        setEnd (-390, -344); break;
    case 33:
        setEnd (-226, -386); break;
    case 34:
        setEnd (-144, -370); break;
    case 35:
        setEnd (-218, -454); break;
    case 36:
        setEnd (-223, -495); break;
    case 37:
        setEnd (-513, -379); break;
    default:
        break;
       */
    }
}

void MainWindow::setNextPos(int index){
    switch(endComboBox->currentIndex()){
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

    tour->findPath(startComboBox->currentIndex());
    nextPath = tour->getPath(endComboBox->currentIndex());

    clear();//清除界面以准备绘制路线
    QGraphicsPathItem *item = new QGraphicsPathItem();//路线

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
    way.moveTo(startX + 700, startY +440);

    for(int i = 1; i < nextPath.size(); i++){
        setNextPos(nextPath[i]);
        way.lineTo(endX + 700, endY + 440);
    }

    item->setPath(way);

}

void MainWindow::clear(){
    QList<QGraphicsItem*> listItem = scene->items();
    while(!listItem.empty()){
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
    QGraphicsPixmapItem *item = scene->addPixmap(QPixmap("BUPT.jpg"));
    item->setPos(-500, -420);
}


//鼠标事件          mouseDoubleClikEvent
void MainWindow::mouseDoubleClikEvent(QMouseEvent *e)
{
    QDialog * dialog = new QDialog;
    QGridLayout *layout = new QGridLayout(dialog);
    label = new QLabel;


}

void MainWindow::callOtherMap ()
{
    mapWidget = new MapWidget;
    mapWidget->show ();
}


MainWindow::~MainWindow()
{
    //delete ui;
}

