#include <QMessageBox>
#include <QPainter>
#include <QSequentialAnimationGroup>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    setWindowTitle("BUPT校园导览系统");
    ui->setupUi(this);
    clear();
    createAction();
    initMainWindow();

    tour = new MainWindow::findShortestPath();
    tour->createGraph();

}

//初始化ui界面
void MainWindow::initMainWindow()
{

    ui->toolBar->addAction(findPathAction);
    ui->toolBar->addSeparator();
    /*
    ui->toolBar->addAction(multiFindAction);
    ui->toolBar->addSeparator();
    */
    ui->toolBar->addAction(ctrlAction);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(clearAction);
    ui->toolBar->addSeparator();

    userLabel = new QLabel;
    userLabel->setText("用户");
    userComboBox = new QComboBox;
    ui->toolBar->addWidget(userLabel);
    ui->toolBar->addWidget(userComboBox);

    userComboBox->addItem("用户1");
    userComboBox->addItem("用户2");
    userComboBox->addItem("用户3");
//--------------------------------------------------------
    ui->toolBar->addSeparator();

    startLabel = new QLabel;
    startLabel->setText("起点");
    startComboBox = new QComboBox;
    ui->toolBar->addWidget(startLabel);
    ui->toolBar->addWidget(startComboBox);

        startComboBox->addItem("(以下为地点列表)");
        startComboBox->addItem("");
        startComboBox->addItem("");
        startComboBox->addItem("沙河-医务室");
        startComboBox->addItem("");
        startComboBox->addItem("沙河-运动场");
        startComboBox->addItem("");
        startComboBox->addItem("沙河-雁北园北区");
        startComboBox->addItem("沙河-洗衣店");
        startComboBox->addItem( "沙河-教工食堂");
        startComboBox->addItem( "沙河-二维码广场");
        startComboBox->addItem( "沙河-综合办公楼");
        startComboBox->addItem("");
        startComboBox->addItem( "沙河-东配楼");
        startComboBox->addItem( "沙河-雁北园南区");
        startComboBox->addItem( "沙河-小麦铺");
        startComboBox->addItem( "沙河-球场");
        startComboBox->addItem("");
        startComboBox->addItem( "沙河-学生食堂");
        startComboBox->addItem( "沙河-西餐厅");
        startComboBox->addItem( "沙河-学生活动中心&邮局");
        startComboBox->addItem( "沙河-校西门");
        startComboBox->addItem( "沙河-菜鸟驿站");
        startComboBox->addItem("");
        startComboBox->addItem( "沙河-商贸服务区");
        startComboBox->addItem("");
        startComboBox->addItem("");
        startComboBox->addItem( "沙河-图书馆" );
        startComboBox->addItem( "沙河-教学实验综合楼&报告厅" );
        startComboBox->addItem("");
        startComboBox->addItem( "沙河-雁南园S2" );
        startComboBox->addItem( "沙河-雁南园S3" );
        startComboBox->addItem("");
        startComboBox->addItem( "沙河-雁南园S4" );
        startComboBox->addItem("");
        startComboBox->addItem( "沙河-雁南园S5北" );//起点的名称
        startComboBox->addItem( "沙河-雁南园S6" );
        startComboBox->addItem("");


        startComboBox->addItem("西土城-校北门");
        startComboBox->addItem("西土城-学十一公寓");
        startComboBox->addItem("西土城-经管楼");
        startComboBox->addItem("西土城-学六公寓");
        startComboBox->addItem("西土城-家属区");
        startComboBox->addItem("西土城-科研大楼");
        startComboBox->addItem("西土城-校东北门&青年教师公寓");
        startComboBox->addItem("西土城-留学生公寓");
        startComboBox->addItem("西土城-学九公寓");
        startComboBox->addItem("西土城-学十公寓");
        startComboBox->addItem("西土城-学生活动中心西门");
        startComboBox->addItem("西土城-青年公寓");
        startComboBox->addItem("西土城-综合食堂");
        startComboBox->addItem("");//14
        startComboBox->addItem("西土城-外卖窗口西");
        startComboBox->addItem("西土城-外卖窗口东");
        startComboBox->addItem("西土城-学苑超市");
        startComboBox->addItem("西土城-水房澡堂锅炉房");
        startComboBox->addItem("西土城-学五公寓");
        startComboBox->addItem("西土城-喷泉北");
        startComboBox->addItem("西土城-学八公寓");
        startComboBox->addItem("西土城-教工餐厅");
        startComboBox->addItem("");//23
        startComboBox->addItem("西土城-小松林");
        startComboBox->addItem("西土城-学苑书屋");
        startComboBox->addItem("西土城-学十三公寓");
        startComboBox->addItem("西土城-学三公寓");
        startComboBox->addItem("");//28
        startComboBox->addItem("西土城-学四公寓");
        startComboBox->addItem("");//30
        startComboBox->addItem("西土城-球场");
        startComboBox->addItem("西土城-学生食堂");
        startComboBox->addItem("西土城-家属区&保卫处");
        startComboBox->addItem("西土城-图书馆");
        startComboBox->addItem("西土城-鸿雁楼");
        startComboBox->addItem("西土城-学一公寓");
        startComboBox->addItem("");//37
        startComboBox->addItem("西土城-学二公寓");
        startComboBox->addItem("西土城-时光广场路口");
        startComboBox->addItem("西土城-行政办公楼");
        startComboBox->addItem("西土城-篮球场");
        startComboBox->addItem("西土城-网球场排球场");
        startComboBox->addItem("西土城-体育馆");
        startComboBox->addItem("西土城-游泳馆&学29公寓");
        startComboBox->addItem("西土城-校东门");
        startComboBox->addItem("西土城-财务处&后勤楼");
        startComboBox->addItem("西土城-移动营业厅");
        startComboBox->addItem("西土城-教四楼");
        startComboBox->addItem("");//49
        startComboBox->addItem("西土城-教一楼");
        startComboBox->addItem("");//51
        startComboBox->addItem("西土城-科学会堂");
        startComboBox->addItem("西土城-全民健身");
        startComboBox->addItem("西土城-校西门&主席像");
        startComboBox->addItem("西土城-主楼&音乐喷泉");
        startComboBox->addItem("西土城-体育场");
        startComboBox->addItem("西土城-停车坪");
        startComboBox->addItem("西土城-教三楼");
        startComboBox->addItem("");//59
        startComboBox->addItem("西土城-教二楼");
        startComboBox->addItem("");//61
        startComboBox->addItem("");//62
        startComboBox->addItem("");//63
        startComboBox->addItem("西土城-中门邮局");
        startComboBox->addItem("");//65
        startComboBox->addItem("西土城-可信网络通信协同创新中心");
        startComboBox->addItem("西土城-时光咖啡店");
        startComboBox->addItem("西土城-校医院");
        startComboBox->addItem("西土城-中门");
        startComboBox->addItem("西土城-南区超市");
        startComboBox->addItem("西土城-南门");
        startComboBox->addItem("");//72
        startComboBox->addItem("");//73
        startComboBox->addItem("西土城-校车车库");
        startComboBox->addItem("西土城-体育场西南角");

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

    midLabel = new QLabel;
    midLabel->setText("中间必经点");
    midComboBox = new QComboBox;
    ui->toolBar->addWidget(midLabel);
    ui->toolBar->addWidget(midComboBox);

    midComboBox->addItem( "无" );
        midComboBox->addItem("");
        midComboBox->addItem("");
        midComboBox->addItem("沙河-医务室");
        midComboBox->addItem("");
        midComboBox->addItem("沙河-运动场");
        midComboBox->addItem("");
        midComboBox->addItem("沙河-雁北园北区");
        midComboBox->addItem("沙河-洗衣店");
        midComboBox->addItem( "沙河-教工食堂");
        midComboBox->addItem( "沙河-二维码广场");
        midComboBox->addItem( "沙河-综合办公楼");
        midComboBox->addItem("");
        midComboBox->addItem( "沙河-东配楼");
        midComboBox->addItem( "沙河-雁北园南区");
        midComboBox->addItem( "沙河-小麦铺");
        midComboBox->addItem( "沙河-球场");
        midComboBox->addItem("");
        midComboBox->addItem( "沙河-学生食堂");
        midComboBox->addItem( "沙河-西餐厅");
        midComboBox->addItem( "沙河-学生活动中心&邮局");
        midComboBox->addItem( "沙河-校西门");
        midComboBox->addItem( "沙河-菜鸟驿站");
        midComboBox->addItem("");
        midComboBox->addItem( "沙河-商贸服务区");
        midComboBox->addItem("");
        midComboBox->addItem("");
        midComboBox->addItem( "沙河-图书馆" );
        midComboBox->addItem( "沙河-教学实验综合楼&报告厅" );
        midComboBox->addItem("");
        midComboBox->addItem( "沙河-雁南园S2" );
        midComboBox->addItem( "沙河-雁南园S3" );
        midComboBox->addItem("");
        midComboBox->addItem( "沙河-雁南园S4" );
        midComboBox->addItem("");
        midComboBox->addItem( "沙河-雁南园S5北" );//起点的名称
        midComboBox->addItem( "沙河-雁南园S6" );
        midComboBox->addItem("");


        midComboBox->addItem("西土城-校北门");
        midComboBox->addItem("西土城-学十一公寓");
        midComboBox->addItem("西土城-经管楼");
        midComboBox->addItem("西土城-学六公寓");
        midComboBox->addItem("西土城-家属区");
        midComboBox->addItem("西土城-科研大楼");
        midComboBox->addItem("西土城-校东北门&青年教师公寓");
        midComboBox->addItem("西土城-留学生公寓");
        midComboBox->addItem("西土城-学九公寓");
        midComboBox->addItem("西土城-学十公寓");
        midComboBox->addItem("西土城-学生活动中心西门");
        midComboBox->addItem("西土城-青年公寓");
        midComboBox->addItem("西土城-综合食堂");
        midComboBox->addItem("");//14
        midComboBox->addItem("西土城-外卖窗口西");
        midComboBox->addItem("西土城-外卖窗口东");
        midComboBox->addItem("西土城-学苑超市");
        midComboBox->addItem("西土城-水房澡堂锅炉房");
        midComboBox->addItem("西土城-学五公寓");
        midComboBox->addItem("西土城-喷泉北");
        midComboBox->addItem("西土城-学八公寓");
        midComboBox->addItem("西土城-教工餐厅");
        midComboBox->addItem("");//23
        midComboBox->addItem("西土城-小松林");
        midComboBox->addItem("西土城-学苑书屋");
        midComboBox->addItem("西土城-学十三公寓");
        midComboBox->addItem("西土城-学三公寓");
        midComboBox->addItem("");//28
        midComboBox->addItem("西土城-学四公寓");
        midComboBox->addItem("");//30
        midComboBox->addItem("西土城-球场");
        midComboBox->addItem("西土城-学生食堂");
        midComboBox->addItem("西土城-家属区&保卫处");
        midComboBox->addItem("西土城-图书馆");
        midComboBox->addItem("西土城-鸿雁楼");
        midComboBox->addItem("西土城-学一公寓");
        midComboBox->addItem("");//37
        midComboBox->addItem("西土城-学二公寓");
        midComboBox->addItem("西土城-时光广场路口");
        midComboBox->addItem("西土城-行政办公楼");
        midComboBox->addItem("西土城-篮球场");
        midComboBox->addItem("西土城-网球场排球场");
        midComboBox->addItem("西土城-体育馆");
        midComboBox->addItem("西土城-游泳馆&学29公寓");
        midComboBox->addItem("西土城-校东门");
        midComboBox->addItem("西土城-财务处&后勤楼");
        midComboBox->addItem("西土城-移动营业厅");
        midComboBox->addItem("西土城-教四楼");
        midComboBox->addItem("");//49
        midComboBox->addItem("西土城-教一楼");
        midComboBox->addItem("");//51
        midComboBox->addItem("西土城-科学会堂");
        midComboBox->addItem("西土城-全民健身");
        midComboBox->addItem("西土城-校西门&主席像");
        midComboBox->addItem("西土城-主楼&音乐喷泉");
        midComboBox->addItem("西土城-体育场");
        midComboBox->addItem("西土城-停车坪");
        midComboBox->addItem("西土城-教三楼");
        midComboBox->addItem("");//59
        midComboBox->addItem("西土城-教二楼");
        midComboBox->addItem("");//61
        midComboBox->addItem("");//62
        midComboBox->addItem("");//63
        midComboBox->addItem("西土城-中门邮局");
        midComboBox->addItem("");//65
        midComboBox->addItem("西土城-可信网络通信协同创新中心");
        midComboBox->addItem("西土城-时光咖啡店");
        midComboBox->addItem("西土城-校医院");
        midComboBox->addItem("西土城-中门");
        midComboBox->addItem("西土城-南区超市");
        midComboBox->addItem("西土城-南门");
        midComboBox->addItem("");//72
        midComboBox->addItem("");//73
        midComboBox->addItem("西土城-校车车库");
        midComboBox->addItem("西土城-体育场西南角");

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

    endLabel = new QLabel;
    endLabel->setText("终点");
    endComboBox = new QComboBox;
    ui->toolBar->addWidget(endLabel);
    ui->toolBar->addWidget(endComboBox);

    endComboBox->addItem("(以下为地点列表)");
        endComboBox->addItem("");
        endComboBox->addItem("");
        endComboBox->addItem("沙河-医务室");
        endComboBox->addItem("");
        endComboBox->addItem("沙河-运动场");
        endComboBox->addItem("");
        endComboBox->addItem("沙河-雁北园北区");
        endComboBox->addItem("沙河-洗衣店");
        endComboBox->addItem( "沙河-教工食堂");
        endComboBox->addItem( "沙河-二维码广场");
        endComboBox->addItem( "沙河-综合办公楼");
        endComboBox->addItem("");
        endComboBox->addItem( "沙河-东配楼");
        endComboBox->addItem( "沙河-雁北园南区");
        endComboBox->addItem( "沙河-小麦铺");
        endComboBox->addItem( "沙河-球场");
        endComboBox->addItem("");
        endComboBox->addItem( "沙河-学生食堂");
        endComboBox->addItem( "沙河-西餐厅");
        endComboBox->addItem( "沙河-学生活动中心&邮局");
        endComboBox->addItem( "沙河-校西门");
        endComboBox->addItem( "沙河-菜鸟驿站");
        endComboBox->addItem("");
        endComboBox->addItem( "沙河-商贸服务区");
        endComboBox->addItem("");
        endComboBox->addItem("");
        endComboBox->addItem( "沙河-图书馆" );
        endComboBox->addItem( "沙河-教学实验综合楼&报告厅" );
        endComboBox->addItem("");
        endComboBox->addItem( "沙河-雁南园S2" );
        endComboBox->addItem( "沙河-雁南园S3" );
        endComboBox->addItem("");
        endComboBox->addItem( "沙河-雁南园S4" );
        endComboBox->addItem("");
        endComboBox->addItem( "沙河-雁南园S5北" );//起点的名称
        endComboBox->addItem( "沙河-雁南园S6" );
        endComboBox->addItem("");


        endComboBox->addItem("西土城-校北门");
        endComboBox->addItem("西土城-学十一公寓");
        endComboBox->addItem("西土城-经管楼");
        endComboBox->addItem("西土城-学六公寓");
        endComboBox->addItem("西土城-家属区");
        endComboBox->addItem("西土城-科研大楼");
        endComboBox->addItem("西土城-校东北门&青年教师公寓");
        endComboBox->addItem("西土城-留学生公寓");
        endComboBox->addItem("西土城-学九公寓");
        endComboBox->addItem("西土城-学十公寓");
        endComboBox->addItem("西土城-学生活动中心西门");
        endComboBox->addItem("西土城-青年公寓");
        endComboBox->addItem("西土城-综合食堂");
        endComboBox->addItem("");//14
        endComboBox->addItem("西土城-外卖窗口西");
        endComboBox->addItem("西土城-外卖窗口东");
        endComboBox->addItem("西土城-学苑超市");
        endComboBox->addItem("西土城-水房澡堂锅炉房");
        endComboBox->addItem("西土城-学五公寓");
        endComboBox->addItem("西土城-喷泉北");
        endComboBox->addItem("西土城-学八公寓");
        endComboBox->addItem("西土城-教工餐厅");
        endComboBox->addItem("");//23
        endComboBox->addItem("西土城-小松林");
        endComboBox->addItem("西土城-学苑书屋");
        endComboBox->addItem("西土城-学十三公寓");
        endComboBox->addItem("西土城-学三公寓");
        endComboBox->addItem("");//28
        endComboBox->addItem("西土城-学四公寓");
        endComboBox->addItem("");//30
        endComboBox->addItem("西土城-球场");
        endComboBox->addItem("西土城-学生食堂");
        endComboBox->addItem("西土城-家属区&保卫处");
        endComboBox->addItem("西土城-图书馆");
        endComboBox->addItem("西土城-鸿雁楼");
        endComboBox->addItem("西土城-学一公寓");
        endComboBox->addItem("");//37
        endComboBox->addItem("西土城-学二公寓");
        endComboBox->addItem("西土城-时光广场路口");
        endComboBox->addItem("西土城-行政办公楼");
        endComboBox->addItem("西土城-篮球场");
        endComboBox->addItem("西土城-网球场排球场");
        endComboBox->addItem("西土城-体育馆");
        endComboBox->addItem("西土城-游泳馆&学29公寓");
        endComboBox->addItem("西土城-校东门");
        endComboBox->addItem("西土城-财务处&后勤楼");
        endComboBox->addItem("西土城-移动营业厅");
        endComboBox->addItem("西土城-教四楼");
        endComboBox->addItem("");//49
        endComboBox->addItem("西土城-教一楼");
        endComboBox->addItem("");//51
        endComboBox->addItem("西土城-科学会堂");
        endComboBox->addItem("西土城-全民健身");
        endComboBox->addItem("西土城-校西门&主席像");
        endComboBox->addItem("西土城-主楼&音乐喷泉");
        endComboBox->addItem("西土城-体育场");
        endComboBox->addItem("西土城-停车坪");
        endComboBox->addItem("西土城-教三楼");
        endComboBox->addItem("");//59
        endComboBox->addItem("西土城-教二楼");
        endComboBox->addItem("");//61
        endComboBox->addItem("");//62
        endComboBox->addItem("");//63
        endComboBox->addItem("西土城-中门邮局");
        endComboBox->addItem("");//65
        endComboBox->addItem("西土城-可信网络通信协同创新中心");
        endComboBox->addItem("西土城-时光咖啡店");
        endComboBox->addItem("西土城-校医院");
        endComboBox->addItem("西土城-中门");
        endComboBox->addItem("西土城-南区超市");
        endComboBox->addItem("西土城-南门");
        endComboBox->addItem("");//72
        endComboBox->addItem("");//73
        endComboBox->addItem("西土城-校车车库");
        endComboBox->addItem("西土城-体育场西南角");

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
        ui->toolBar->addSeparator();

        logicLabel = new QLabel;
        logicLabel->setText("逻辑功能选取");
        logicCombo = new QComboBox;
        ui->toolBar->addWidget(logicLabel);
        ui->toolBar->addWidget(logicCombo);

        logicCombo->addItem("请选择需要的功能");    //加入拥塞系数，
        logicCombo->addItem("运动");//1   操场——球场
        logicCombo->addItem("吃饭");//2   两个食堂
        logicCombo->addItem("购物");//3   小卖铺和超市

//--------------------------------------------------------
        ui->toolBar->addSeparator();

        trafficLabe = new QLabel;
        trafficLabe->setText("选择适当交通工具");
        trafficCombo = new QComboBox;
        ui->toolBar->addWidget(trafficLabe);
        ui->toolBar->addWidget(trafficCombo);

        trafficCombo->addItem("步行");
        trafficCombo->addItem("骑车");//1
        //trafficCombo->addItem("吃饭");//2
        //trafficCombo->addItem("汽车");
}

void MainWindow::createAction(){
    findPathAction = new QAction(QIcon(":/image/Search.png"),tr("搜索路径"), this);
    findPathAction->setShortcut (tr("Ctrl+F"));
    findPathAction->setStatusTip (tr("搜索路径"));
    connect (findPathAction, SIGNAL(triggered(bool)), this, SLOT(navigation()));

    clearAction = new QAction(QIcon(":/image/Clear.png"), tr("清理路径"), this);
    clearAction->setShortcut (tr("Ctrl+W"));
    clearAction->setStatusTip (tr("清理路径"));
    connect (clearAction, SIGNAL(triggered(bool)), this, SLOT(clear()));

    multiFindAction = new QAction (QIcon("Multi.png"), tr("中间最短"), this);
    multiFindAction->setShortcut(tr("Ctrl+G"));
    multiFindAction->setStatusTip(tr("中间最短路径"));
    connect(multiFindAction, SIGNAL(triggered(bool)), this, SLOT(multiFind()));

    ctrlAction = new QAction(QIcon(":/image/Ctrl.png"), tr("控制"),this);
    ctrlAction->setShortcut(tr("Ctrl+Q"));
    connect(ctrlAction, SIGNAL(triggered(bool)), this, SLOT(control()));
}

void MainWindow::clear(){

    ani = new QPropertyAnimation(ui->frame,"geometry");
    ani->setDuration(100);
    ani->setStartValue(QRect(1, -5, 40, 50));
    ani->setEndValue(QRect(1, -5,40, 50));
    ani->start();
    printLog("clear");
    screenLog("clear");
}

void MainWindow::paintPath(){

    QMessageBox::information(this, "oo", "开始实时导航", QMessageBox::Ok);

    tour->findPath(startComboBox->currentIndex()-1);  //根据起点寻路
    nextPath = tour->getPath(endComboBox->currentIndex()-1);      //根据终点选择绘制路线

    qDebug()<<"起点是：\n"<<startComboBox->currentText()<<"\n"<<startComboBox->currentIndex()<<"\n"<<"终点是：\n"<<endComboBox->currentText()<<"\n"<<endComboBox->currentIndex()<<"\n";

    //调用出错了
    clear();//清除界面以准备绘制路线

    for(int i = 1; i< nextPath.size(); i++ ){
        qDebug() << nextPath[i]+1 <<"_\n";
    }

    //处理坐标
    setStartStation();
    setEndStation();
    QPoint tmp1(startX, startY),tmp2(endX, endY);

    //动画
    ani = new QPropertyAnimation(ui->frame,"geometry");
    //ani->setEasingCurve(QEasingCurve::OutBounce);
    ani->setDuration(10000);
    ani->setStartValue(QRect(startX-13, startY-50, 30, 40));
    ani->setEndValue(QRect(endX-13, endY-50,30, 40));
    qDebug()<<"start:"<<startX<<" "<<startY<<"_\n";
    qDebug()<<"end:"<<endX<<" "<<endY<<"_\n";

    //QMessageBox::information(this, "sd", QString::number(tmp1.x())+","+QString::number(tmp1.y()),QMessageBox::Ok);

    QString strtmp,temp;
    double weight=0.0;
    QVector<double> weight_log;
    qDebug()<<"size:"<<nextPath.size()<<"_\n";
    for(int i = 1; i < nextPath.size()-1; i++){   //把坐标存入路径中

        setNextPos(nextPath[i]+1);

        ani->setKeyValueAt(weight+1.0/(nextPath.size()-1),QRect(tmpX-13, tmpY-50, 30, 40));
        qDebug()<<"tmp:"<<tmpX<<" "<<tmpY<<"_\n";
        weight+=1.0/(nextPath.size()-1);
        weight_log.push_back(1.0/(nextPath.size()-1));//将数据保存下来，便于计时
    }

    ani->start();
    qDebug()<<"start"<<"_\n";
    double delay = 10000;//总体的时延
    for(int i = 1; i < nextPath.size()-1; i++)
    {
        Delay_MSec(weight_log[i-1]*delay);
        QString str_temp =startComboBox->itemText(nextPath[i]+1);
        temp = QString::number(nextPath[i]+1);
        strtmp = "用户已到：" + temp + "->" + str_temp;
        printLog(strtmp);
        screenLog(strtmp);
    }
    Delay_MSec((1-weight)*delay);
    QString str_temp =startComboBox->itemText(nextPath[nextPath.size()-1]+1);
    temp = QString::number(nextPath[nextPath.size()-1]+1);//获取重点的标号
    strtmp = "用户已到：" + temp + "->" + str_temp;
    printLog(strtmp);
    screenLog(strtmp);
    printLog("---------------------------------------------");
    screenLog("------------------------");


}

void MainWindow::multiFind(){

    QMessageBox::information(this, "oo", "开始实时导航", QMessageBox::Ok);

    tour->findPath(startComboBox->currentIndex()-1);  //根据起点寻路
    nextPath = tour->getPath(midComboBox->currentIndex()-1);
    tour->findPath(midComboBox->currentIndex()-1);
    nextPath_mid = tour->getPath(endComboBox->currentIndex()-1);      //根据终点选择绘制路线
    for(int i = 1; i<nextPath_mid.size(); i++)//跳过第二段的第一个点，因为这个点也是第一段的最后一个
    {
        nextPath.push_back(nextPath_mid[i]);
    }
    //已经将两段路合并为一段路
    qDebug()<<"起点是：\n"<<startComboBox->currentText()<<"\n"<<startComboBox->currentIndex()<<"\n"<<"中间点是：\n"
           <<midComboBox->currentText()<<"\n"<<midComboBox->currentIndex()<<"\n"<<"终点是：\n"
          <<endComboBox->currentText()<<"\n"<<endComboBox->currentIndex()<<"\n";


    //调用出错了
    clear();//清除界面以准备绘制路线

//    for(int i = 1; i< nextPath_mid.size(); i++ ){
//        qDebug() << nextPath_mid[i]+1 <<"_\n";
//    }
    for(int i = 1; i< nextPath.size(); i++ ){
        qDebug() << nextPath[i]+1 <<"_\n";
    }

    //处理坐标
    setStartStation();
    setMidStation();
    setEndStation();

    //动画
    ani = new QPropertyAnimation(ui->frame,"geometry");
    //ani->setEasingCurve(QEasingCurve::OutBounce);
    ani->setDuration(10000);
    ani->setStartValue(QRect(startX-13, startY-50, 30, 40));
    ani->setEndValue(QRect(endX-13, endY-50,30, 40));
    qDebug()<<"start:"<<startX<<" "<<startY<<"_\n";
    qDebug()<<"end:"<<midX<<" "<<midY<<"_\n";
    qDebug()<<"end:"<<endX<<" "<<endY<<"_\n";

    //QMessageBox::information(this, "sd", QString::number(tmp1.x())+","+QString::number(tmp1.y()),QMessageBox::Ok);

    QString strtmp,temp;
    double weight=0.0;
    int num = nextPath.size();
    QVector<double> weight_log;

    for(int i = 1; i < nextPath.size()-1; i++){   //把坐标存入路径中

        setNextPos(nextPath[i]+1);

        ani->setKeyValueAt(weight+1.0/(num-1),QRect(tmpX-13, tmpY-50, 30, 40));
        qDebug()<<"tmp:"<<tmpX<<" "<<tmpY<<"_\n";
        weight+=1.0/(num-1);
        weight_log.push_back(1.0/(num-1));//将数据保存下来，便于计时

    }
    //有问题，权重！！！！！！！！！！！！！！！
    ani->start();
    qDebug()<<"start"<<"_\n";
    double delay = 10000;//总体的时延
    for(int i = 1; i < nextPath.size()-1; i++)
    {
        Delay_MSec(weight_log[i-1]*delay);
        QString str_temp =startComboBox->itemText(nextPath[i]+1);
        temp = QString::number(nextPath[i]+1);
        strtmp = "用户已到：" + temp + "->" + str_temp;
        printLog(strtmp);
        screenLog(strtmp);
    }
    Delay_MSec((1-weight)*delay);
    QString str_temp =startComboBox->itemText(nextPath[nextPath.size()-1]+1);
    temp = QString::number(nextPath[nextPath.size()-1]+1);//获取重点的标号
    strtmp = "用户已到：" + temp + "->" + str_temp;
    printLog(strtmp);
    screenLog("---------------------------------------------");
    screenLog(strtmp);
    printLog("---------------------------------------------");
}

void MainWindow::printLog(const QString& s)
{
    QFile file;
    //qDebug()<<"----------------------------------------"<<"\n";
    //file.setFileName("F:/Qt5/2021-MAP/campus_tour-20210601-3/campus_tour-20210601-3/build-campus_tour-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/log.txt");
    file.setFileName("./log.txt");
    if(file.open(QIODevice::ReadWrite |QIODevice::Append)){
            QTextStream stream(&file);
            stream<<printTime(timeChange())<<"  "<<s<<"\n";
            file.close();
            //qDebug()<<"--------------------close--------------------"<<"\n";
    }
}

int MainWindow::timeChange()
{
    QTime current_time =QTime::currentTime();
    int time_all;
    time_all =  current_time.hour()*60*60 + current_time.minute()*60 + current_time.second();
    int time_change;
    time_change = time_all % 7200;//相当于两小时
    return time_change;
}

QString MainWindow::printTime(int i)
{
    QString time_return;
    time_return += QString::number(i/300) + ":" + QString::number((i%300)/5);
    return time_return;
}

void MainWindow::Delay_MSec(unsigned int msec)
{
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}

void MainWindow::screenLog(const QString &s)
{
    ui->log->document()->setMaximumBlockCount(34);
    ui->log->append(s);
}

MainWindow::~MainWindow()
{
    delete ui;
}

