#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include"newdelete.h"
#include"newdesign.h"
#include"budget.h"
myMainWindow::myMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myMainWindow)
{
    ui->setupUi(this);
}

myMainWindow::~myMainWindow()
{
    delete ui;
}



//按下删除跳出新的窗口
void myMainWindow::on_pushButton_2_clicked()
{
    newDelete *configWindow = new newDelete;
    //使newdesign和mymainwindow两个窗口连起来传递信号(预算、起始时间、终止时间、结余）
    connect(configWindow, SIGNAL(sendDeleteBudget(QString)), this, SLOT(receiveDeleteBudget(QString)));
    connect(configWindow, SIGNAL(sendDeleteBeginTime(QString)), this, SLOT(receiveDeleteBeginTime(QString)));
    connect(configWindow, SIGNAL(sendDeleteEndTime(QString)), this, SLOT(receiveDeleteEndTime(QString)));
    connect(configWindow, SIGNAL(sendDeleteSurplus(QString)), this, SLOT(receiveDeleteSurplus(QString)));
        configWindow->show();
}
//按下设计预算跳出新的窗口
void myMainWindow::on_pushButton_clicked()
{
    newDesign *configWindow = new newDesign;
    //使newdesign和mymainwindow两个窗口连起来传递信号(预算、起始时间、终止时间）
     connect(configWindow, SIGNAL(sendBudget(QString)), this, SLOT(receiveBudget(QString)));
     connect(configWindow, SIGNAL(sendBeginTime(QString)), this, SLOT(receiveBeginTime(QString)));
     connect(configWindow, SIGNAL(sendEndTime(QString)), this, SLOT(receiveEndTime(QString)));
     //使newdesign和mymainwindow两个窗口连起来传递信号(结余）
     connect(configWindow, SIGNAL(sendSurplus(double)), this, SLOT(receiveSurplus(double)));

        configWindow->show();
}
//按下修改跳出新的窗口
void myMainWindow::on_pushButton_3_clicked()
{
    newDesign *configWindow = new newDesign;
    connect(configWindow, SIGNAL(sendBudget(QString)), this, SLOT(receiveBudget(QString)));
    connect(configWindow, SIGNAL(sendBeginTime(QString)), this, SLOT(receiveBeginTime(QString)));
    connect(configWindow, SIGNAL(sendEndTime(QString)), this, SLOT(receiveEndTime(QString)));
        configWindow->show();
}
//设置修改预算
//接收传递过来的信号并输出
void myMainWindow::receiveBudget(QString budget){

   //ui->textBrowser_3->setText(QString::number(budget,'f',0));//获取传递过来的数据
    ui->textBrowser_3->setText(budget);
}
void myMainWindow::receiveBeginTime(QString bTime){

    ui->textBrowser_2->setText(bTime);
}
void myMainWindow::receiveEndTime(QString eTime){

    ui->textBrowser_5->setText(eTime);
}
//接受传递过来的double类型的数据结余
void myMainWindow::receiveSurplus(double  surplus){
    //将double类型转换成字符串类型
    QString str_surplus=QString::number(surplus,'f',0);
    //textBrowser_4输出surplus
    ui->textBrowser_4->setText(str_surplus);
}
void myMainWindow::receiveDeleteBudget(QString budget){
    ui->textBrowser_3->setText(budget);
}
//删除预算
//接受传递过来的信号并输出
void myMainWindow::receiveDeleteBeginTime(QString bbTime){
    ui->textBrowser_2->setText(bbTime);
}
void myMainWindow::receiveDeleteEndTime(QString eeTime){
    ui->textBrowser_5->setText(eeTime);
}
void myMainWindow::receiveDeleteSurplus(QString surplus){
    ui->textBrowser_4->setText(surplus);
}

