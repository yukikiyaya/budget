#ifndef DELETE_H
#define DELETE_H

#include <QWidget>

namespace Ui {
class Delete;
}

class Delete : public QWidget
{
    Q_OBJECT

public:
    explicit Delete(QWidget *parent = nullptr);
    ~Delete();

private:
    Ui::Delete *ui;
};

#endif // DELETE_H
