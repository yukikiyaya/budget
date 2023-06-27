#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class myMainWindow; }
QT_END_NAMESPACE

class myMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    myMainWindow(QWidget *parent = nullptr);
    ~myMainWindow();

private slots:

    //按下删除跳出新的窗口
    void on_pushButton_2_clicked();
    //按下设计预算跳出新的窗口
    void on_pushButton_clicked();
    //按下修改跳出新的窗口
    void on_pushButton_3_clicked();

    //void receiveBudget(double budget);
    //接受newdesign传递过来的数据
    void receiveBudget(QString budget);
    void receiveBeginTime(QString bTime);
    void receiveEndTime(QString eTime);
    //接受newDesign传递过来的结余
    void receiveSurplus(double  surplus);
    //接受newdelete传递过来的信息
    void receiveDeleteBudget(QString budget="0");
    void receiveDeleteBeginTime(QString bbTime="请设置时间");
    void receiveDeleteEndTime(QString eeTime="请设置时间");
    void receiveDeleteSurplus(QString surplus="0");
private:
    Ui::myMainWindow *ui;
};
#endif // MYMAINWINDOW_H
