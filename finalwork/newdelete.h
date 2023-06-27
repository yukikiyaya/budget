#ifndef NEWDELETE_H
#define NEWDELETE_H

#include <QWidget>

namespace Ui {
class newDelete;
}

class newDelete : public QWidget
{
    Q_OBJECT

public:
    explicit newDelete(QWidget *parent = nullptr);
    ~newDelete();

private slots:
    //按下“是”按钮，预算重置
    void on_pushButton_2_clicked();
signals:
    //创建信号
    void sendDeleteBudget(QString budget);
    void sendDeleteBeginTime(QString bbTime);
    void sendDeleteEndTime(QString eeTime);
    void sendDeleteSurplus(QString surplus);

private:
    Ui::newDelete *ui;
};

#endif // NEWDELETE_H
