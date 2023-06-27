#ifndef NEWDESIGN_H
#define NEWDESIGN_H

#include <QWidget>

namespace Ui {
class newDesign;
}

class newDesign : public QWidget
{
    Q_OBJECT

public:
    explicit newDesign(QWidget *parent = nullptr);
    ~newDesign();
private slots:
    //创建一个槽，按下按钮传递数据信号
    void on_pushButton_clicked();

signals:
    //创建一个有参数的信号，预算
    //void sendBudget(double budget);
     void sendBudget(QString budget);
   //创建一个有参数的信号，起始时间
     void sendBeginTime(QString bTime);
     //创建一个有参数的信号，终止时间
     void sendEndTime(QString eTime);
     //创建一个有参数的信号，结余
     void sendSurplus(double surplus);
private:
    Ui::newDesign *ui;
};

#endif // NEWDESIGN_H
