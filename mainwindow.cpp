#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QTableView>
#include <QTableView>
#include <QMessageBox>
#include <qcustomplot.h>
//#include <QCPLayer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hasmade = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawPlot()
{
    QPen pen;
    QVector<double> x(100), y(100);

//    if(!hasmade){
//        for(int i =0 ; i< len ; i++){
//            ui->customPlot->addGraph();
//        }
//        qDebug()<<len << " made ";
//    }
//    hasmade =true;

    //for each generated number
    for(int i=0 ; i<len ; i++){
        //generate x,y according to that number
        for(int j =0 ; j<100 ; j++){
            x[j]=j*2;
            y[j]=qSin((intVector.at(i))*2+j)*3 + up;
        }

        //shifting the graph up for not overlapping
        up +=50;

        //for each generated number , we make graph
        ui->customPlot->addGraph();
        /////////////////////////////////////////////////////////////
        //if we use setData , there will be  overlapping and it seems all y numbers will be added to eachother!
        ui->customPlot->graph(i)->addData(x,y);

        //if we use addData , there wont be any overlapping and each graph will be dissapeared after next graph started to be shown
//        ui->customPlot->graph(i)->setData(x, y);

        /////////////////////////////////////////////////////////////
    }
    ui->customPlot->xAxis->setRange(0,100);
    ui->customPlot->yAxis->setRange(-10,up);

    ui->customPlot->replot();
    x.clear();
    y.clear();
//    ui->customPlot->graph()->data().clear();
}

void MainWindow::setRand()
{
    //append random numbers to intVector for later uses
    for(int i =0 ; i<len ; i++){
        rand = RandObj.bounded(low , high);
        intVector.push_back(rand);
    }
    //initializa plot using intVector
    drawPlot();

    //initializing table view
    model = new QStandardItemModel(1,len,this);
    ui->tableView->setModel(model);
    for(int i=0 ; i<len ; i++){
       QModelIndex index = model->index(0,i,QModelIndex());
        model->setData(index,QString::number(intVector.at(i)));
    }
    //clear vector for next time
    intVector.clear();
}

void MainWindow::startTimer()
{
    //if start button has been clicked , continue
    if(continueRand){
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, [=](){
             if(continueRand){
                  setRand();
             }
        });
        //each 1s restart the timer
        //and if stop button hasnt been clicked , call setRand to generate random number
        timer->start(1000);
        qDebug()<<"timer";
    }
}

void MainWindow::on_startButton_clicked()
{
    //set low , high , len from ui and start the timer
    intVector.clear();
    low = ui->low->text().toInt();
    high = ui->high->text().toInt() ;
    len =  ui->len->text().toInt();
    continueRand = true;
    startTimer();
    qDebug()<<"start clicked";
}


void MainWindow::on_stopButton_clicked()
{
     qDebug()<<"stop clicked";
     continueRand =false;

}

