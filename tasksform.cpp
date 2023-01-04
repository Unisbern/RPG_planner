#include "tasksform.h"
#include "ui_tasksform.h"

TasksForm::TasksForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tasksform)
{
    ui->setupUi(this);
    editorWidget = new ItemEditor();
    editorWidget->hide();

    connect(editorWidget, &ItemEditor::taskitem_sig, this, &TasksForm::on_taskitem_get);
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
    delete editorWidget;
    delete ui;

}

void TasksForm::on_taskitem_get(TaskItem *item)
{
    qDebug()<<__FUNCTION__;
    list.append(item);
    ui->scrollLayout->addWidget(item);

}

void TasksForm::on_buttonAdd_clicked()
{
    qDebug()<<__FUNCTION__;
    editorWidget->show();
}


