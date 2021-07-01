#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QMessageBox>
#include <QEvent>
#include <QMouseEvent>
#include <QString>
#include <QListView>
#include <QPropertyAnimation>

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
    void continueAnimation();

protected:
    void mousePressEvent(QMouseEvent *);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
