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
    //计算指定日期一天的支出
    double showDayOut(QString time);
    //计算出输入的开始时间到终止时间之间的所有支出
    double showOut(QString timeBegin,QString timeEnd);
    //重新设置对应日期的预算的金额
    void setBudget(double budgetPriece,QString timeBegin,QString timeEnd);
    //显示相应日期剩余预算
    double showSurplus(QString timeBegin,QString timeEnd); 
    //删除对应日期的预算
    void deleteBudget(QString timeBegin,QString timeEnd);

};

#endif // BUDGET_H
