#include "taskitem.h"
#include "ui_taskitem.h"

TaskItem::TaskItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::taskItem)
{
    ui->setupUi(this);
}

TaskItem::~TaskItem()
{
    delete ui;
}

void TaskItem::update()
{
    static int i=0;
    ui->name->setText(name);
    ui->experience->setText(QString("Опыт: %1").arg(expirience));
    ui->groupBox->setTitle(QString("Миссия: %1").arg(++i));

}
