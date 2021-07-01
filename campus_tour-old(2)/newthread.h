#ifndef NEWTHREAD_H
#define NEWTHREAD_H

#include <QObject>
#include <QThread>
#include "mainwindow.h"

class newThread :public QThread
{
    Q_OBJECT
public:
    newThread(QObject *parent = nullptr);

protected:
    void run();
};

#endif // NEWTHREAD_H
