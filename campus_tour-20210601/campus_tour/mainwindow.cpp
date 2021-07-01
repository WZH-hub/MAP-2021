#include <QMessageBox>
#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    setWindowTitle("BUPT校园导览系统");
    ui->setupUi(this);

    createAction();
    initMainWindow();

    tour = new MainWindow::findShortestPath();

    tour->createGraph();

    ui->log->document()->setMaximumBlockCount(11);
    ui->log->append("我是日志1");
    ui->log->append("lalalala");
    ui->log->append("我是日志2");
    ui->log->append("我是日志3");
    ui->log->append("我是日志4");
    ui->log->append("我是日志5");
    ui->log->append("我是日志6");

    //ui->log->moveCursor(QTextCursor::End);


//    QLabel *label = new QLabel("",0);
//    QImage img;
//    img.load("F:/Qt5/2021-MAP/campus_tour-20210601/campus_tour/dot.png");
//    QPixmap mp;
//    mp = mp.fromImage(img);
//    mp = mp.load("F:/Qt5/2021-MAP/campus_tour-20210601/campus_tour/dot.png");
//    label->setPixmap(mp);
//    label->show();

//    QFrame *frame = new QFrame;
//    frame->resize(30,30);
//    QPixmap pixmap("F:/Qt5/2021-MAP/campus_tour-20210601/campus_tour/dot.png");
//    QPalette palette;
//    palette.setBrush(frame->backgroundRole(),QBrush(pixmap));
//    frame->setPalette(palette);
//    //frame->setMask(pixmap.mask());
//    frame->setAutoFillBackground(true);
//    frame->show();


    QParallelAnimationGroup *p = new QParallelAnimationGroup;

    /*  声明动画类，并将控制对象 this (this一定是继承自QObject的窗口部件)  以及属性名 "geometry" 传入构造函数  */
    QPropertyAnimation* animation = new QPropertyAnimation(ui->frame, "geometry");
    /*  设置动画持续时长为 2 秒钟  */
    animation->setDuration(10000);
    /*  设置动画的起始状态 起始点 (1,2)  起始大小 (3,4)  */
    animation->setStartValue(QRect(0, 0, 30, 40));
    animation->setEndValue(QRect(0, 0, 30, 40));
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    QPropertyAnimation* animation2 = new QPropertyAnimation(ui->frame_2, "geometry");
    /*  设置动画持续时长为 2 秒钟  */
    animation2->setDuration(20000);
    /*  设置动画的起始状态 起始点 (1,2)  起始大小 (3,4)  */
    animation2->setStartValue(QRect(500, 500, 30, 40));
    //animation->setKeyValueAt(0.5,QRect(700,100,30,30));
    /*  设置动画的结束状态 结束点 (100,200)  结束大小 (300,400)  */
    animation2->setEndValue(QRect(400, 300, 30, 40));
    /*  设置动画效果  */
    //animation->setEasingCurve(QEasingCurve::OutBounce);
    /*  开始执行动画 QAbstractAnimation::DeleteWhenStopped 动画结束后进行自清理(效果就好像智能指针里的自动delete animation) */
    animation2->start(QAbstractAnimation::DeleteWhenStopped);

    p->addAnimation(animation);
    p->addAnimation(animation2);
    //p->start(QAbstractAnimation::DeleteWhenStopped);




}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //ui->plainTextEdit->insertPlainText(" "+QString::number(event->x())+" "+QString::number(event->y())+'\n');
    QString tmp = QString::number(event->globalX())+","+QString::number(event->globalY())+"\n"+QString::number(event->x())+","+ QString::number(event->y());
    QMessageBox::information(this, "pos",tmp, QMessageBox::Ok);
}

void MainWindow::initMainWindow()
{

    ui->toolBar->addAction(findPathAction);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(clearAction);
    ui->toolBar->addSeparator();

    QLabel *z = new QLabel;
    z->setText("用户");
    QComboBox *userComboBox = new QComboBox;
    ui->toolBar->addWidget(z);
    ui->toolBar->addWidget(userComboBox);

    userComboBox->addItem("用户1");
    userComboBox->addItem("用户2");
    userComboBox->addItem("用户3");
//--------------------------------------------------------
    ui->toolBar->addSeparator();

    QLabel *a = new QLabel;
    a->setText("起点");
    QComboBox *startComboBox = new QComboBox;
    ui->toolBar->addWidget(a);
    ui->toolBar->addWidget(startComboBox);

        startComboBox->addItem("(以下为地点列表)");
        startComboBox->addItem("");
        startComboBox->addItem("");
        startComboBox->addItem("医务室");
        startComboBox->addItem("");
        startComboBox->addItem("运动场");
        startComboBox->addItem("");
        startComboBox->addItem("雁北园北区");
        startComboBox->addItem("洗衣店");
        startComboBox->addItem( "教工食堂");
        startComboBox->addItem( "二维码广场");
        startComboBox->addItem( "综合办公楼");
        startComboBox->addItem("");
        startComboBox->addItem( "东配楼");
        startComboBox->addItem( "雁北园南区");
        startComboBox->addItem( "小麦铺");
        startComboBox->addItem( "球场");
        startComboBox->addItem("");
        startComboBox->addItem( "学生食堂");
        startComboBox->addItem( "西餐厅");
        startComboBox->addItem( "学生活动中心&邮局");
        startComboBox->addItem( "校西门");
        startComboBox->addItem( "菜鸟驿站");
        startComboBox->addItem("");
        startComboBox->addItem( "沙河商贸服务区");
        startComboBox->addItem("");
        startComboBox->addItem("");
        startComboBox->addItem( "图书馆" );
        startComboBox->addItem( "教学实验综合楼&报告厅" );
        startComboBox->addItem("");
        startComboBox->addItem( "雁南园S2" );
        startComboBox->addItem( "雁南园S3" );
        startComboBox->addItem("");
        startComboBox->addItem( "雁南园S4" );
        startComboBox->addItem("");
        startComboBox->addItem( "雁南园S5北" );//起点的名称
        startComboBox->addItem( "雁南园S6" );
        startComboBox->addItem("");


        startComboBox->addItem("校北门");
        startComboBox->addItem("学十一公寓");
        startComboBox->addItem("经管楼");
        startComboBox->addItem("学六公寓");
        startComboBox->addItem("家属区");
        startComboBox->addItem("科研大楼");
        startComboBox->addItem("校东北门&青年教师公寓");
        startComboBox->addItem("留学生公寓");
        startComboBox->addItem("学九公寓");
        startComboBox->addItem("学十公寓");
        startComboBox->addItem("学生活动中心西门");
        startComboBox->addItem("青年公寓");
        startComboBox->addItem("综合食堂");
        startComboBox->addItem("");//14
        startComboBox->addItem("外卖窗口西");
        startComboBox->addItem("外卖窗口东");
        startComboBox->addItem("学苑超市");
        startComboBox->addItem("水房澡堂锅炉房");
        startComboBox->addItem("学五公寓");
        startComboBox->addItem("喷泉北");
        startComboBox->addItem("学八公寓");
        startComboBox->addItem("教工餐厅");
        startComboBox->addItem("");//23
        startComboBox->addItem("小松林");
        startComboBox->addItem("学苑书屋");
        startComboBox->addItem("学十三公寓");
        startComboBox->addItem("学三公寓");
        startComboBox->addItem("");//28
        startComboBox->addItem("学四公寓");
        startComboBox->addItem("");//30
        startComboBox->addItem("球场");
        startComboBox->addItem("学生食堂");
        startComboBox->addItem("家属区&保卫处");
        startComboBox->addItem("图书馆");
        startComboBox->addItem("鸿雁楼");
        startComboBox->addItem("学一公寓");
        startComboBox->addItem("");//37
        startComboBox->addItem("学二公寓");
        startComboBox->addItem("时光广场路口");
        startComboBox->addItem("行政办公楼");
        startComboBox->addItem("篮球场");
        startComboBox->addItem("网球场排球场");
        startComboBox->addItem("体育馆");
        startComboBox->addItem("游泳馆&学29公寓");
        startComboBox->addItem("校东门");
        startComboBox->addItem("财务处&后勤楼");
        startComboBox->addItem("移动营业厅");
        startComboBox->addItem("教四楼");
        startComboBox->addItem("");//49
        startComboBox->addItem("教一楼");
        startComboBox->addItem("");//51
        startComboBox->addItem("科学会堂");
        startComboBox->addItem("全民健身");
        startComboBox->addItem("校西门&主席像");
        startComboBox->addItem("主楼&音乐喷泉");
        startComboBox->addItem("体育场");
        startComboBox->addItem("停车坪");
        startComboBox->addItem("教三楼");
        startComboBox->addItem("");//59
        startComboBox->addItem("教二楼");
        startComboBox->addItem("");//61
        startComboBox->addItem("");//62
        startComboBox->addItem("");//63
        startComboBox->addItem("中门邮局");
        startComboBox->addItem("");//65
        startComboBox->addItem("可信网络通信协同创新中心");
        startComboBox->addItem("时光咖啡店");
        startComboBox->addItem("校医院");
        startComboBox->addItem("中门");
        startComboBox->addItem("南区超市");
        startComboBox->addItem("南门");
        startComboBox->addItem("");//72
        startComboBox->addItem("");//73
        startComboBox->addItem("校车车库");
        startComboBox->addItem("体育场西南角");

        startComboBox->addItem("");//转折点1
        startComboBox->addItem("");//转折点2

        QListView *view = qobject_cast<QListView *>(startComboBox->view());
            Q_ASSERT(view!=nullptr);

            view->setRowHidden(1, true);
            view->setRowHidden(2, true);
            view->setRowHidden(4, true);
            view->setRowHidden(6, true);
            view->setRowHidden(12, true);
            view->setRowHidden(17, true);
            view->setRowHidden(23, true);
            view->setRowHidden(25, true);
            view->setRowHidden(26, true);
            view->setRowHidden(29, true);
            view->setRowHidden(32, true);
            view->setRowHidden(34, true);
            view->setRowHidden(37, true);

            view->setRowHidden(37+14, true);
            view->setRowHidden(37+23, true);
            view->setRowHidden(37+28, true);
            view->setRowHidden(37+30, true);
            view->setRowHidden(37+37, true);
            view->setRowHidden(37+49, true);
            view->setRowHidden(37+51, true);
            view->setRowHidden(37+59, true);
            view->setRowHidden(37+61, true);
            view->setRowHidden(37+62, true);
            view->setRowHidden(37+63, true);
            view->setRowHidden(37+65, true);
            view->setRowHidden(37+72, true);
            view->setRowHidden(37+73, true);

            view->setRowHidden(37+76, true);
            view->setRowHidden(37+77, true);


//--------------------------------------------------------
    ui->toolBar->addSeparator();

    QLabel *b = new QLabel;
    b->setText("中间必经点");
    QComboBox *midComboBox = new QComboBox;
    ui->toolBar->addWidget(b);
    ui->toolBar->addWidget(midComboBox);

    midComboBox->addItem( "无" );
        midComboBox->addItem("");
        midComboBox->addItem("");
        midComboBox->addItem("医务室");
        midComboBox->addItem("");
        midComboBox->addItem("运动场");
        midComboBox->addItem("");
        midComboBox->addItem("雁北园北区");
        midComboBox->addItem("洗衣店");
        midComboBox->addItem( "教工食堂");
        midComboBox->addItem( "二维码广场");
        midComboBox->addItem( "综合办公楼");
        midComboBox->addItem("");
        midComboBox->addItem( "东配楼");
        midComboBox->addItem( "雁北园南区");
        midComboBox->addItem( "小麦铺");
        midComboBox->addItem( "球场");
        midComboBox->addItem("");
        midComboBox->addItem( "学生食堂");
        midComboBox->addItem( "西餐厅");
        midComboBox->addItem( "学生活动中心&邮局");
        midComboBox->addItem( "校西门");
        midComboBox->addItem( "菜鸟驿站");
        midComboBox->addItem("");
        midComboBox->addItem( "沙河商贸服务区");
        midComboBox->addItem("");
        midComboBox->addItem("");
        midComboBox->addItem( "图书馆" );
        midComboBox->addItem( "教学实验综合楼&报告厅" );
        midComboBox->addItem("");
        midComboBox->addItem( "雁南园S2" );
        midComboBox->addItem( "雁南园S3" );
        midComboBox->addItem("");
        midComboBox->addItem( "雁南园S4" );
        midComboBox->addItem("");
        midComboBox->addItem( "雁南园S5北" );//起点的名称
        midComboBox->addItem( "雁南园S6" );
        midComboBox->addItem("");


        midComboBox->addItem("校北门");
        midComboBox->addItem("学十一公寓");
        midComboBox->addItem("经管楼");
        midComboBox->addItem("学六公寓");
        midComboBox->addItem("家属区");
        midComboBox->addItem("科研大楼");
        midComboBox->addItem("校东北门&青年教师公寓");
        midComboBox->addItem("留学生公寓");
        midComboBox->addItem("学九公寓");
        midComboBox->addItem("学十公寓");
        midComboBox->addItem("学生活动中心西门");
        midComboBox->addItem("青年公寓");
        midComboBox->addItem("综合食堂");
        midComboBox->addItem("");//14
        midComboBox->addItem("外卖窗口西");
        midComboBox->addItem("外卖窗口东");
        midComboBox->addItem("学苑超市");
        midComboBox->addItem("水房澡堂锅炉房");
        midComboBox->addItem("学五公寓");
        midComboBox->addItem("喷泉北");
        midComboBox->addItem("学八公寓");
        midComboBox->addItem("教工餐厅");
        midComboBox->addItem("");//23
        midComboBox->addItem("小松林");
        midComboBox->addItem("学苑书屋");
        midComboBox->addItem("学十三公寓");
        midComboBox->addItem("学三公寓");
        midComboBox->addItem("");//28
        midComboBox->addItem("学四公寓");
        midComboBox->addItem("");//30
        midComboBox->addItem("球场");
        midComboBox->addItem("学生食堂");
        midComboBox->addItem("家属区&保卫处");
        midComboBox->addItem("图书馆");
        midComboBox->addItem("鸿雁楼");
        midComboBox->addItem("学一公寓");
        midComboBox->addItem("");//37
        midComboBox->addItem("学二公寓");
        midComboBox->addItem("时光广场路口");
        midComboBox->addItem("行政办公楼");
        midComboBox->addItem("篮球场");
        midComboBox->addItem("网球场排球场");
        midComboBox->addItem("体育馆");
        midComboBox->addItem("游泳馆&学29公寓");
        midComboBox->addItem("校东门");
        midComboBox->addItem("财务处&后勤楼");
        midComboBox->addItem("移动营业厅");
        midComboBox->addItem("教四楼");
        midComboBox->addItem("");//49
        midComboBox->addItem("教一楼");
        midComboBox->addItem("");//51
        midComboBox->addItem("科学会堂");
        midComboBox->addItem("全民健身");
        midComboBox->addItem("校西门&主席像");
        midComboBox->addItem("主楼&音乐喷泉");
        midComboBox->addItem("体育场");
        midComboBox->addItem("停车坪");
        midComboBox->addItem("教三楼");
        midComboBox->addItem("");//59
        midComboBox->addItem("教二楼");
        midComboBox->addItem("");//61
        midComboBox->addItem("");//62
        midComboBox->addItem("");//63
        midComboBox->addItem("中门邮局");
        midComboBox->addItem("");//65
        midComboBox->addItem("可信网络通信协同创新中心");
        midComboBox->addItem("时光咖啡店");
        midComboBox->addItem("校医院");
        midComboBox->addItem("中门");
        midComboBox->addItem("南区超市");
        midComboBox->addItem("南门");
        midComboBox->addItem("");//72
        midComboBox->addItem("");//73
        midComboBox->addItem("校车车库");
        midComboBox->addItem("体育场西南角");

        midComboBox->addItem("");//转折点1
        midComboBox->addItem("");//转折点2

        QListView *midview = qobject_cast<QListView *>(midComboBox->view());
        Q_ASSERT(midview!=nullptr);

        midview->setRowHidden(1, true);
        midview->setRowHidden(2, true);
        midview->setRowHidden(4, true);
        midview->setRowHidden(6, true);
        midview->setRowHidden(12, true);
        midview->setRowHidden(17, true);
        midview->setRowHidden(23, true);
        midview->setRowHidden(25, true);
        midview->setRowHidden(26, true);
        midview->setRowHidden(29, true);
        midview->setRowHidden(32, true);
        midview->setRowHidden(34, true);
        midview->setRowHidden(37, true);

        midview->setRowHidden(37+14, true);
        midview->setRowHidden(37+23, true);
        midview->setRowHidden(37+28, true);
        midview->setRowHidden(37+30, true);
        midview->setRowHidden(37+37, true);
        midview->setRowHidden(37+49, true);
        midview->setRowHidden(37+51, true);
        midview->setRowHidden(37+59, true);
        midview->setRowHidden(37+61, true);
        midview->setRowHidden(37+62, true);
        midview->setRowHidden(37+63, true);
        midview->setRowHidden(37+65, true);
        midview->setRowHidden(37+72, true);
        midview->setRowHidden(37+73, true);

        midview->setRowHidden(37+76, true);
        midview->setRowHidden(37+77, true);
//--------------------------------------------------------
    ui->toolBar->addSeparator();

    QLabel *c = new QLabel;
    c->setText("终点");
    QComboBox *endComboBox = new QComboBox;
    ui->toolBar->addWidget(c);
    ui->toolBar->addWidget(endComboBox);

    endComboBox->addItem("(以下为地点列表)");
        endComboBox->addItem("");
        endComboBox->addItem("");
        endComboBox->addItem("医务室");
        endComboBox->addItem("");
        endComboBox->addItem("运动场");
        endComboBox->addItem("");
        endComboBox->addItem("雁北园北区");
        endComboBox->addItem("洗衣店");
        endComboBox->addItem( "教工食堂");
        endComboBox->addItem( "二维码广场");
        endComboBox->addItem( "综合办公楼");
        endComboBox->addItem("");
        endComboBox->addItem( "东配楼");
        endComboBox->addItem( "雁北园南区");
        endComboBox->addItem( "小麦铺");
        endComboBox->addItem( "球场");
        endComboBox->addItem("");
        endComboBox->addItem( "学生食堂");
        endComboBox->addItem( "西餐厅");
        endComboBox->addItem( "学生活动中心&邮局");
        endComboBox->addItem( "校西门");
        endComboBox->addItem( "菜鸟驿站");
        endComboBox->addItem("");
        endComboBox->addItem( "沙河商贸服务区");
        endComboBox->addItem("");
        endComboBox->addItem("");
        endComboBox->addItem( "图书馆" );
        endComboBox->addItem( "教学实验综合楼&报告厅" );
        endComboBox->addItem("");
        endComboBox->addItem( "雁南园S2" );
        endComboBox->addItem( "雁南园S3" );
        endComboBox->addItem("");
        endComboBox->addItem( "雁南园S4" );
        endComboBox->addItem("");
        endComboBox->addItem( "雁南园S5北" );//起点的名称
        endComboBox->addItem( "雁南园S6" );
        endComboBox->addItem("");


        endComboBox->addItem("校北门");
        endComboBox->addItem("学十一公寓");
        endComboBox->addItem("经管楼");
        endComboBox->addItem("学六公寓");
        endComboBox->addItem("家属区");
        endComboBox->addItem("科研大楼");
        endComboBox->addItem("校东北门&青年教师公寓");
        endComboBox->addItem("留学生公寓");
        endComboBox->addItem("学九公寓");
        endComboBox->addItem("学十公寓");
        endComboBox->addItem("学生活动中心西门");
        endComboBox->addItem("青年公寓");
        endComboBox->addItem("综合食堂");
        endComboBox->addItem("");//14
        endComboBox->addItem("外卖窗口西");
        endComboBox->addItem("外卖窗口东");
        endComboBox->addItem("学苑超市");
        endComboBox->addItem("水房澡堂锅炉房");
        endComboBox->addItem("学五公寓");
        endComboBox->addItem("喷泉北");
        endComboBox->addItem("学八公寓");
        endComboBox->addItem("教工餐厅");
        endComboBox->addItem("");//23
        endComboBox->addItem("小松林");
        endComboBox->addItem("学苑书屋");
        endComboBox->addItem("学十三公寓");
        endComboBox->addItem("学三公寓");
        endComboBox->addItem("");//28
        endComboBox->addItem("学四公寓");
        endComboBox->addItem("");//30
        endComboBox->addItem("球场");
        endComboBox->addItem("学生食堂");
        endComboBox->addItem("家属区&保卫处");
        endComboBox->addItem("图书馆");
        endComboBox->addItem("鸿雁楼");
        endComboBox->addItem("学一公寓");
        endComboBox->addItem("");//37
        endComboBox->addItem("学二公寓");
        endComboBox->addItem("时光广场路口");
        endComboBox->addItem("行政办公楼");
        endComboBox->addItem("篮球场");
        endComboBox->addItem("网球场排球场");
        endComboBox->addItem("体育馆");
        endComboBox->addItem("游泳馆&学29公寓");
        endComboBox->addItem("校东门");
        endComboBox->addItem("财务处&后勤楼");
        endComboBox->addItem("移动营业厅");
        endComboBox->addItem("教四楼");
        endComboBox->addItem("");//49
        endComboBox->addItem("教一楼");
        endComboBox->addItem("");//51
        endComboBox->addItem("科学会堂");
        endComboBox->addItem("全民健身");
        endComboBox->addItem("校西门&主席像");
        endComboBox->addItem("主楼&音乐喷泉");
        endComboBox->addItem("体育场");
        endComboBox->addItem("停车坪");
        endComboBox->addItem("教三楼");
        endComboBox->addItem("");//59
        endComboBox->addItem("教二楼");
        endComboBox->addItem("");//61
        endComboBox->addItem("");//62
        endComboBox->addItem("");//63
        endComboBox->addItem("中门邮局");
        endComboBox->addItem("");//65
        endComboBox->addItem("可信网络通信协同创新中心");
        endComboBox->addItem("时光咖啡店");
        endComboBox->addItem("校医院");
        endComboBox->addItem("中门");
        endComboBox->addItem("南区超市");
        endComboBox->addItem("南门");
        endComboBox->addItem("");//72
        endComboBox->addItem("");//73
        endComboBox->addItem("校车车库");
        endComboBox->addItem("体育场西南角");

        endComboBox->addItem("");//转折点1
        endComboBox->addItem("");//转折点2

        QListView *endview = qobject_cast<QListView *>(endComboBox->view());
        Q_ASSERT(endview!=nullptr);

        endview->setRowHidden(1, true);
        endview->setRowHidden(2, true);
        endview->setRowHidden(4, true);
        endview->setRowHidden(6, true);
        endview->setRowHidden(12, true);
        endview->setRowHidden(17, true);
        endview->setRowHidden(23, true);
        endview->setRowHidden(25, true);
        endview->setRowHidden(26, true);
        endview->setRowHidden(29, true);
        endview->setRowHidden(32, true);
        endview->setRowHidden(34, true);
        endview->setRowHidden(37, true);

        endview->setRowHidden(37+14, true);
        endview->setRowHidden(37+23, true);
        endview->setRowHidden(37+28, true);
        endview->setRowHidden(37+30, true);
        endview->setRowHidden(37+37, true);
        endview->setRowHidden(37+49, true);
        endview->setRowHidden(37+51, true);
        endview->setRowHidden(37+59, true);
        endview->setRowHidden(37+61, true);
        endview->setRowHidden(37+62, true);
        endview->setRowHidden(37+63, true);
        endview->setRowHidden(37+65, true);
        endview->setRowHidden(37+72, true);
        endview->setRowHidden(37+73, true);

        endview->setRowHidden(37+76, true);
        endview->setRowHidden(37+77, true);
//--------------------------------------------------------

}


void MainWindow::createAction(){
    findPathAction = new QAction(QIcon("Search.png"),tr("搜索路径"), this);
    findPathAction->setShortcut (tr("Ctrl+F"));
    findPathAction->setStatusTip (tr("搜索路径"));
    connect (findPathAction, SIGNAL(triggered(bool)), this, SLOT(paintPath()));

    clearAction = new QAction(QIcon("Clear.png"), tr("清理路径"), this);
    clearAction->setShortcut (tr("Ctrl+W"));
    clearAction->setStatusTip (tr("清理路径"));
    connect (clearAction, SIGNAL(triggered(bool)), this, SLOT(clear()));
}



void MainWindow::paintPath(){

    QMessageBox::information(this, "oo", "s", QMessageBox::Ok);
    QPainter *painter = new QPainter(this);

    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::blue);
    pen.setStyle(Qt::DotLine);
    painter->setPen(pen);
    painter->drawLine(500,500,800,800);

    /*
    //要操作widget
    //ui->widget::paintEvent();
    QGraphicsPathItem *item = new QGraphicsPathItem();//用路径项和笔把路线画出来
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::blue);
    pen.setStyle(Qt::DotLine);

    item->setPen(pen);

    item->setFlag(QGraphicsItem::ItemIsPanel);

    QPainterPath way;
    way.moveTo(500,500);
    way.lineTo(800,800);
    item->setPath(way);
    */


    /*
    QVector<QPoint> vec;
    tour->findPath(startComboBox->currentIndex()-1);  //根据起点寻路

    nextPath = tour->getPath(endComboBox->currentIndex()-1);      //根据终点选择绘制路线

    QString a= startComboBox->currentText();
    QString b =  endComboBox->currentText();

    qDebug()<<"起点是：\n"<<startComboBox->currentText()<<"\n"<<startComboBox->currentIndex()<<"\n"<<"终点是：\n"<<endComboBox->currentText()<<"\n"<<endComboBox->currentIndex()<<"\n";

    //调用出错了
    //clear();//清除界面以准备绘制路线

    QGraphicsPathItem *item = new QGraphicsPathItem();//用路径项和笔把路线画出来
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::blue);
    pen.setStyle(Qt::DotLine);

    item->setPen(pen);

    item->setFlag(QGraphicsItem::ItemIsPanel);
    item->setPos(-800,-500);

    for(int i = 1; i< nextPath.size(); i++ ){
        qDebug() << nextPath[i]+1 <<"_";
    }

    scene->addItem(item);

    QPainterPath way;

    QPoint tmp1(startX, startY),tmp2(endX, endY);
    QMessageBox::information(this, "sd", QString::number(tmp1.x())+","+QString::number(tmp1.y()),QMessageBox::Ok);

    QPoint t1=mapToParent(tmp1), t2=mapToParent(tmp2);

    QMessageBox::information(this, "sd", QString::number(t1.x())+","+QString::number(t1.y()),QMessageBox::Ok);
    way.moveTo(t1);
    //way.moveTo(startX -600, startY -200);

    QString strtmp,temp;
    for(int i = 1; i < nextPath.size(); i++){   //把坐标存入路径中


        setNextPos(nextPath[i]);

        const QPoint t3(endX, endY);
        t2 = mapToParent(t3);
        QMessageBox::information(this, "d", QString::number(t2.x())+","+QString::number(t2.y()),QMessageBox::Ok);
        way.lineTo(t2);

        temp = QString::number(nextPath[i]+1);
        strtmp = strtmp + "用户已到：" + temp;
        printLog(strtmp);
    }
     printLog("---------------------------------------------");

    int i = item->x(),j=item->y();
    QMessageBox::information(this, "uni", QString::number(i)+","+QString::number(j),QMessageBox::Ok);
    item->setPath(way);
    */

}

void MainWindow::clear(){

    /*
    QList<QGraphicsItem*> listItem = scene->items();
    while(!listItem.empty()){
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }

    //5.29
    //QGraphicsPixmapItem *item = scene->addPixmap(QPixmap("E:/campus_tour/map.jpeg"));
    //item->setPos(-500, -180);
    */
}

void MainWindow::continueAnimation()
{

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

MainWindow::findShortestPath::findShortestPath(){
    //创建图，把边设置为最长或不可达，设置结点数、边数
    Map.vexnum=115;
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

QVector<int> MainWindow::findShortestPath::getPath(int endPos){
    //用一个vector装路径上各结点，数组中是倒着的，所以要reverse
    QVector<int> pathRes;

    for(; endPos!=-1; endPos = prev[endPos]){
        qDebug()<<(endPos+1)<<"...\n";
        //qDebug()<<(endPos)<<"...\n";
        pathRes.push_back(endPos);
    }
    std::reverse(pathRes.begin(), pathRes.end());

    return pathRes;
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
    Map.arc[1][7].dis = Map.arc[7][1].dis = 90;
    Map.arc[2][3].dis = Map.arc[3][2].dis = 80;
    Map.arc[2][9].dis = Map.arc[9][2].dis = 90;
    Map.arc[3][11].dis = Map.arc[11][3].dis = 90;
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
    Map.arc[23][24].dis = Map.arc[24][23].dis = 45;
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
    Map.arc[33][22].dis = Map.arc[22][33].dis = 130;
    Map.arc[32][34].dis = Map.arc[34][32].dis = 40;
    Map.arc[34][33].dis = Map.arc[33][34].dis = 100;
    Map.arc[34][35].dis = Map.arc[35][34].dis = 130;
    Map.arc[35][36].dis = Map.arc[36][35].dis = 25;
    Map.arc[34][36].dis = Map.arc[36][34].dis = 50;


//    Map.arc[20][81].dis = Map.arc[81][20].dis = 1000;//从沙河西门到本部东门
    //修改，增加转折点
    Map.arc[20][112].dis = Map.arc[112][20].dis = 500;
    Map.arc[112][113].dis = Map.arc[113][112].dis = 1000;
    Map.arc[113][81].dis = Map.arc[81][113].dis = 200;
/*
 本部序号，使用时所有序号+36
 * 01 校北门   02 学十一公寓03 经管楼04 学六公寓
05 家属区06 科研大楼07 校东北门&青年教师公寓
08 留学生公寓09 学九公寓10 学十公寓11 学生活动中心西门   12 青年公寓13 综合食堂
14 学五公寓西北角15 外卖窗口西16 外卖窗口东17 学苑超市18 水房澡堂锅炉房
19 学五公寓20 喷泉北21 学八公寓22 教工餐厅 23 喷泉东24 小松林25 学苑书屋

26 学十三公寓27 学三公寓28 喷泉南29 学四公寓30 学四东31 球场32 学生食堂33 家属区&保卫处 34 图书馆
35 鸿雁楼36 学一公寓37 学一学二路口38 学二公寓39 时光广场路口40 行政办公楼41 篮球场西南角42 网球场排球场南43 体育馆44 游泳馆&学29公寓45 校东门
46 财务处&后勤楼  47 移动营业厅48 教四楼49 主干道中50 教一楼51 教一楼东南角52 科学会堂53 全民健身
54 校西门&主席像55 主楼&音乐喷泉 56 体育场
57 停车坪58 教三楼59 主干道南60 教二楼61 教二楼东北角62 科学会堂西南角63 科学会堂东南角
64 中门邮局65 教二楼东南角66 可信网络通信协同创新中心  67 时光咖啡店68 校医院69 中门  70 南区超市 71 南门
72 学五公寓西南角73 学八公寓东南角74 校车车库75 体育场西南角
*/

    Map.arc[37][38].dis = Map.arc[38][37].dis = 115;
    Map.arc[37][39].dis = Map.arc[39][37].dis = 60;
    Map.arc[38][45].dis = Map.arc[45][38].dis = 40;
    Map.arc[39][47].dis = Map.arc[47][39].dis = 20;
    Map.arc[40][41].dis = Map.arc[41][40].dis = 60;
    Map.arc[41][42].dis = Map.arc[42][41].dis = 30;
    Map.arc[41][54].dis = Map.arc[54][41].dis = 70;
    Map.arc[42][43].dis = Map.arc[43][42].dis = 160;
    Map.arc[43][69].dis = Map.arc[69][43].dis = 200;
    Map.arc[44][45].dis = Map.arc[45][44].dis = 37;
    Map.arc[44][48].dis = Map.arc[48][44].dis = 58;
    Map.arc[45][46].dis = Map.arc[46][45].dis = 37;
    Map.arc[45][51].dis = Map.arc[51][45].dis = 40;
    Map.arc[46][47].dis = Map.arc[47][46].dis = 38;
    Map.arc[47][49].dis = Map.arc[49][47].dis = 20;
    Map.arc[48][50].dis = Map.arc[50][48].dis = 20;
    Map.arc[49][52].dis = Map.arc[52][49].dis = 20;
    Map.arc[50][51].dis = Map.arc[51][50].dis = 75;
    Map.arc[50][108].dis = Map.arc[108][50].dis = 40;
    Map.arc[51][52].dis = Map.arc[52][51].dis = 75;
    Map.arc[51][56].dis = Map.arc[56][51].dis = 40;
    Map.arc[52][53].dis = Map.arc[53][52].dis = 25;
    Map.arc[52][109].dis = Map.arc[109][52].dis = 40;
    Map.arc[53][54].dis = Map.arc[54][53].dis = 120;
    Map.arc[53][60].dis = Map.arc[60][53].dis = 60;
    Map.arc[54][58].dis = Map.arc[58][54].dis = 25;
    Map.arc[55][56].dis = Map.arc[56][55].dis = 37;
    Map.arc[55][108].dis = Map.arc[108][55].dis = 38;
    Map.arc[56][57].dis = Map.arc[57][56].dis = 37;
    Map.arc[56][64].dis = Map.arc[64][56].dis = 35;
    Map.arc[57][109].dis = Map.arc[109][57].dis = 38;
    Map.arc[58][61].dis = Map.arc[61][58].dis = 35;
    Map.arc[59][60].dis = Map.arc[60][59].dis = 25;
    Map.arc[59][66].dis = Map.arc[66][59].dis = 10;
    Map.arc[59][109].dis = Map.arc[109][59].dis = 25;
    Map.arc[60][61].dis = Map.arc[61][60].dis = 120;
    Map.arc[61][67].dis = Map.arc[67][61].dis = 30;
    Map.arc[62][63].dis = Map.arc[63][62].dis = 38;
    Map.arc[62][71].dis = Map.arc[71][62].dis = 90;
    Map.arc[62][108].dis = Map.arc[108][62].dis = 35;
    Map.arc[63][64].dis = Map.arc[64][63].dis = 37;
    Map.arc[64][65].dis = Map.arc[65][64].dis = 37;
    Map.arc[64][73].dis = Map.arc[73][64].dis = 90;
    Map.arc[65][66].dis = Map.arc[66][65].dis = 38;
    Map.arc[66][70].dis = Map.arc[70][66].dis = 45;
    //Map.arc[66][75].dis = Map.arc[75][66].dis = 90;
    Map.arc[67][68].dis = Map.arc[68][67].dis = 30;
    Map.arc[67][77].dis = Map.arc[77][67].dis = 70;
    Map.arc[68][69].dis = Map.arc[69][68].dis = 105;
    Map.arc[69][79].dis = Map.arc[79][69].dis = 70;
    Map.arc[70][75].dis = Map.arc[75][70].dis = 45;
    Map.arc[71][72].dis = Map.arc[72][71].dis = 38;
    Map.arc[71][83].dis = Map.arc[83][71].dis = 65;
    Map.arc[72][73].dis = Map.arc[73][72].dis = 37;
    Map.arc[73][74].dis = Map.arc[74][73].dis = 37;
    Map.arc[74][75].dis = Map.arc[75][74].dis = 38;
    Map.arc[75][76].dis = Map.arc[76][75].dis = 65;
    Map.arc[75][82].dis = Map.arc[82][75].dis = 15;
    Map.arc[75][85].dis = Map.arc[85][75].dis = 65;
    Map.arc[76][77].dis = Map.arc[77][76].dis = 60;
    Map.arc[77][78].dis = Map.arc[78][77].dis = 95;
    Map.arc[77][87].dis = Map.arc[87][77].dis = 65;
    Map.arc[78][79].dis = Map.arc[79][78].dis = 40;
    Map.arc[78][89].dis = Map.arc[89][78].dis = 65;
    Map.arc[79][80].dis = Map.arc[80][79].dis = 25;
    Map.arc[80][81].dis = Map.arc[81][80].dis = 20;
    Map.arc[82][85].dis = Map.arc[85][82].dis = 50;
    Map.arc[83][84].dis = Map.arc[84][83].dis = 75;
    Map.arc[83][90].dis = Map.arc[90][83].dis = 65;
    Map.arc[84][85].dis = Map.arc[85][84].dis = 75;
    Map.arc[85][86].dis = Map.arc[86][85].dis = 65;
    Map.arc[85][91].dis = Map.arc[91][85].dis = 65;
    Map.arc[86][87].dis = Map.arc[87][86].dis = 60;
    Map.arc[87][88].dis = Map.arc[88][87].dis = 30;
    Map.arc[87][98].dis = Map.arc[98][87].dis = 110;
    Map.arc[88][89].dis = Map.arc[89][88].dis = 25;
    Map.arc[89][92].dis = Map.arc[92][89].dis = 80;
    Map.arc[90][93].dis = Map.arc[93][90].dis = 45;
    Map.arc[91][95].dis = Map.arc[95][91].dis = 55;
    Map.arc[92][99].dis = Map.arc[99][92].dis = 30;
    Map.arc[93][94].dis = Map.arc[94][93].dis = 75;
    Map.arc[93][110].dis = Map.arc[110][93].dis = 65;
    Map.arc[94][95].dis = Map.arc[95][94].dis = 75;
    Map.arc[95][96].dis = Map.arc[96][95].dis = 60;
    Map.arc[95][100].dis = Map.arc[100][95].dis = 65;
    Map.arc[96][97].dis = Map.arc[97][96].dis = 50;
    Map.arc[97][98].dis = Map.arc[98][97].dis = 5;
    Map.arc[97][101].dis = Map.arc[101][97].dis = 65;
    Map.arc[98][99].dis = Map.arc[99][98].dis = 55;
    Map.arc[99][111].dis = Map.arc[111][99].dis = 65;
    Map.arc[100][101].dis = Map.arc[101][100].dis = 120;
    Map.arc[100][105].dis = Map.arc[105][100].dis = 35;
    Map.arc[100][110].dis = Map.arc[110][100].dis = 150;
    Map.arc[101][102].dis = Map.arc[102][101].dis = 30;
    Map.arc[102][111].dis = Map.arc[111][102].dis = 30;
    Map.arc[103][104].dis = Map.arc[104][103].dis = 70;
    Map.arc[104][105].dis = Map.arc[105][104].dis = 35;
    Map.arc[105][106].dis = Map.arc[106][105].dis = 20;
    Map.arc[106][107].dis = Map.arc[107][106].dis = 164;
}


MainWindow::~MainWindow()
{
    delete ui;
}

