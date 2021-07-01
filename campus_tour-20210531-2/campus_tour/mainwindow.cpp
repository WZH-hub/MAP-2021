#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainwindow();
}

void MainWindow::initMainwindow()
{
    QLabel *z = new QLabel;
    z->setText("用户");
    QComboBox *userComboBox = new QComboBox;
    ui->toolBar->addWidget(z);
    ui->toolBar->addWidget(userComboBox);

    userComboBox->addItem("用户0");
    userComboBox->addItem("用户1");
    userComboBox->addItem("用户2");
//--------------------------------------------------------
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
//5.29
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //ui->plainTextEdit->insertPlainText(" "+QString::number(event->x())+" "+QString::number(event->y())+'\n');
    QString tmp = QString::number(event->globalX())+","+QString::number(event->globalY())+"\n"+QString::number(event->x())+","+ QString::number(event->y());
    QMessageBox::information(this, "pos",tmp, QMessageBox::Ok);
}

}

MainWindow::~MainWindow()
{
    delete ui;
}

