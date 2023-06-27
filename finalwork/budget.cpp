#include "budget.h"
#include "newdesign.h"

#include<iostream>

using namespace std;
Budget::Budget(double budgetPriece,QString timeBegin,QString timeEnd)
{
    budgetPriece=0;
    budget=budgetPriece;

}
void Budget::setBudget(double budgetPriece,QString timeBegin,QString timeEnd){
   budget=budgetPriece;

}
double Budget::showSurplus(QString timeBegin,QString timeEnd){
    double surplus=0;

    //surplus=budget-Operation::showOut(timeBegin,timeEnd);
    surplus=100;
    return surplus;
}

void Budget::deleteBudget(QString timeBegin,QString timeEnd){
    budget=0;
    timeBegin="";
    timeEnd="";
}
