#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QVector>
#include <QTableView>
#include <QStandardItemModel>
#include <qcustomplot.h>
#include "myobject.h"
#include"mythread.h"
#include "myobject.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setRand(int , int , int );
    void startTimer(bool ,int , int , int );

    MyThread * mthread;
    bool * continueRand;
    int * rand ;
    int * low;
    int * high ;
    int * len;
     QVector<int> * intVector;
    void setTable(QVector<int>);
private slots:

    void on_startButton_clicked();
    void on_stopButton_clicked();


private:
    Ui::MainWindow *ui;
    MyObject cObject;
    QThread cThread;
//    int rand , low , high , len;
    QRandomGenerator RandObj;

    QTimer *timer ;
    QTableView  * tableView;
    QStandardItemModel * model;
    int ret ;
    int up =0; //for shifting plot
    int count;
    bool hasmade;



    QCustomPlot * customPlot;

public slots :
    void onNumberChanged(int);
    void drawPlot(QVector<int>);
};
#endif // MAINWINDOW_H
