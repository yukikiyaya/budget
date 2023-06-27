#include "budget.h"
#include "newdesign.h"
#include<iostream>
#include"mySQLBase.h"
#include<QString>
#include<QDate>
using namespace std;
Budget::Budget(double budgetPriece,QString timeBegin,QString timeEnd)
{
    budgetPriece=0;
    budget=budgetPriece;

}
void Budget::setBudget(double budgetPriece,QString timeBegin,QString timeEnd){
   budget=budgetPriece;

}
double Budget::showDayOut(QString time){
    mySQLBase mysql;
    QSqlDatabase db1;
    mysql.createConnectionByName("ConnectionName" , db1);
    //创建一个对象，获取账单的全部信息
  vector<std::vector<QString>> test1=mysql.getBillsByDate_User(db1,time,"29292929");
  int count=int(test1.size());
  //遍历，获取一天的总支出
  double dayOut=0;
  for(int i=0;i<=count;i++){
      if(test1[i][2]=="支出"){
          dayOut+=test1[i][5].toDouble();
      }else{
          dayOut=dayOut;
      }
  }
  return dayOut;
}
double Budget::showOut(QString timeBegin,QString timeEnd){
    double out=0;
    // 将起始时间和终止时间转换为 QDateTime 对象
    QDateTime begin=QDateTime::fromString(timeBegin,"yyyy-MM-dd");
    QDateTime end=QDateTime::fromString(timeEnd,"yyyy-MM-dd");
    // 获取起始日期、终止日期及两日期差值（单位：天）
    QDate beginTimeObj=begin.date();
    QDate endTimeObj=end.date();
    qint64 days=beginTimeObj.daysTo(endTimeObj);
    // 计算每个日期的支出，加总得出总支出
    for(int i=0;i<=days;i++){
        QString currentTime=beginTimeObj.addDays(i).toString("yyyy-MM-dd");
        out+=showDayOut(currentTime);
    }

}
double Budget::showSurplus(QString timeBegin,QString timeEnd){
    double surplus=0;

    surplus=budget-showOut(timeBegin,timeEnd);
    return surplus;
}

void Budget::deleteBudget(QString timeBegin,QString timeEnd){
    budget=0;
    timeBegin="";
    timeEnd="";
}
