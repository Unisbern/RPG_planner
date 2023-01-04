#include "tasksform.h"
#include "ui_tasksform.h"

TasksForm::TasksForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tasksform)
{
    ui->setupUi(this);
}

TasksForm::~TasksForm()
{
    qDebug()<<__FUNCTION__;
    int i=0;
    while(i<list.size()){

        delete list[i];
        i++;
    }

    //    for(auto &item : list){
    //        delete item;
    //    }

    delete ui;

}

void TasksForm::on_buttonAdd_clicked()
{
    qDebug()<<__FUNCTION__;
    TaskItem *item_ui = nullptr;
    item_ui= new TaskItem();
    list.append(item_ui);
    ui->scrollLayout->addWidget(item_ui);
    qDebug()<<list;
}


