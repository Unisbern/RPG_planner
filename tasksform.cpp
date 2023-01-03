#include "tasksform.h"
#include "ui_tasksform.h"

tasksform::tasksform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tasksform)
{
    ui->setupUi(this);
}

tasksform::~tasksform()
{
    delete ui;
}
