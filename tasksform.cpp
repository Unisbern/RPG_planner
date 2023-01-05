#include "tasksform.h"
#include "ui_tasksform.h"

TasksForm::TasksForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tasksform)
{
    ui->setupUi(this);
    editorWidget = new ItemEditor();
    editorWidget->hide();
    this->loaddata();

    connect(editorWidget, &ItemEditor::taskitem_sig, this, &TasksForm::on_taskitem_get);
}

TasksForm::~TasksForm()
{
    qDebug()<<__FUNCTION__;
    savedata(list);
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

void TasksForm::savedata(QList<TaskItem *> list)
{
    qDebug()<<__FUNCTION__;
    QFile taskdata;
    QTextStream stream;

    stream.setDevice(&taskdata);
    taskdata.setFileName("taskdata.csv");
    taskdata.open(QIODevice::ReadWrite);



    //for(int q=0 ; q < list.length(); q++)
    for(auto &item : list){
        stream<< item->name.toLocal8Bit() <<','
              << item->expirience <<','
              << item->state <<','
              << item->date.toString("dd.MM.yyyy") <<','
              << item->difficulty <<','
              << item->urgency <<','
              << item->fear <<','
              << item->skill <<endl;

    }
    taskdata.close();
    qDebug() << "Сохранил данные";
}

void TasksForm::loaddata()
{

    qDebug()<<__FUNCTION__;
    QFile taskdata("taskdata.csv");
    taskdata.open(QIODevice::ReadWrite);

    while (!taskdata.atEnd()) {
            QString line = taskdata.readLine();
            TaskItem *item = new TaskItem;
            item->updatewith(line);

            qDebug()<<__FUNCTION__<<list<<line;

            this->on_taskitem_get(item);
        }

    qDebug() << "Загрузил данные";
}
