#include "newdelete.h"
#include "ui_newdelete.h"
#include "budget.h"

newDelete::newDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newDelete)
{
    ui->setupUi(this);
}

newDelete::~newDelete()
{
    delete ui;
}
//按下“是”按钮后，所有数据重置
void newDelete::on_pushButton_2_clicked()
{
    Budget newnewBudget(0,"2022.4.4","2022.5.5");
    newnewBudget.deleteBudget(" "," ");
    emit sendDeleteBudget("0");
    emit sendDeleteBeginTime("请设置时间");
    emit sendDeleteEndTime("请设置时间");
    emit sendDeleteSurplus("0");
}
