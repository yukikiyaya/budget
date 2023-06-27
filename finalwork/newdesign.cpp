#include "newdesign.h"
#include "ui_newdesign.h"
#include"budget.h"
#include"mymainwindow.h"
#include<QMessageBox>
newDesign::newDesign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newDesign)
{
    ui->setupUi(this);
}

newDesign::~newDesign()
{
    delete ui;
}

//创建一个槽，按下按钮传递数据
void newDesign::on_pushButton_clicked()
{
    //创建Budget的对象
    Budget newBudget(0,"2022.3.3","2022.4.4");
    //接受用户输入的数据
    QString bud=ui->lineEdit->text();
    QString bTimee=ui->lineEdit_2->text();
    QString eTimee=ui->lineEdit_3->text();
    //类型转换，把字符串转换成double
    double num=bud.toDouble();
    //把用户输入的值传给newBudget对象
    newBudget.setBudget(num,bTimee,eTimee);
    //调用showBudget()计算出结余
    newBudget.showSurplus(bTimee,eTimee);
    //输入预算负数弹出窗口提示是错的
    if(num>0){
        //传递输入的数据给主页面
        emit sendBudget(bud);
        emit sendBeginTime(bTimee);
        emit sendEndTime(eTimee);
        //传递结余数据给主页面
        emit sendSurplus(newBudget.showSurplus(bTimee,eTimee));
    }else{
        QMessageBox::about(this,"警告","您输入的预算格式不正确！");
                    return;
    }
    }

