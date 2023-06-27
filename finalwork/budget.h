#ifndef BUDGET_H
#define BUDGET_H
//#include "Bill.h"//包含Bill的头文件
#include<QDebug>

class Budget//:public Bill
{
private:
    double budget;
public:
    Budget(double budgetPriece,QString timeBegin,QString timeEnd);

    //显示相应日期剩余预算
    double showSurplus(QString timeBegin,QString timeEnd);
    //重新设置对应日期的预算的金额
    void setBudget(double budgetPriece,QString timeBegin,QString timeEnd);
    //删除对应日期的预算
    void deleteBudget(QString timeBegin,QString timeEnd);

};

#endif // BUDGET_H
