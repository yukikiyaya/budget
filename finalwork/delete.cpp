#include "delete.h"
#include "ui_delete.h"

Delete::Delete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}

Delete::~Delete()
{
delete ui;
}
