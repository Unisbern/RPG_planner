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

    task_calendar = new QCalendarWidget();
    connect(editorWidget, &ItemEditor::taskitem_sig, this, &TasksForm::on_taskitem_get);
    connect(task_calendar, &QCalendarWidget::selectionChanged, this, &TasksForm::chooseDate_Filter);

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

//        for(auto &item : list){
//            delete item;
//        }
    delete task_calendar;
    delete editorWidget;
    delete ui;

}

void TasksForm::on_taskitem_get(TaskItem *item)
{
    qDebug()<<__FUNCTION__;
    connect(item, &TaskItem::taskdelete_sig, this, &TasksForm::on_taskdelete_get);

    list.append(item);
    ui->scrollLayout->addWidget(item);
    item->setTitle(ui->scrollLayout->count());


}

void TasksForm::on_taskdelete_get(TaskItem *item)
{
    qDebug()<<__FUNCTION__;


    if(list.contains(item)){
        disconnect(item, &TaskItem::taskdelete_sig, this, &TasksForm::on_taskdelete_get);
        item->hide();

        list.removeAt(list.indexOf(item));
        ui->scrollLayout->removeWidget(item);

        for(int q=0;q<ui->scrollLayout->count();q++){
            list[q]->setTitle(q+1);
        }
    }
    else {
        qCritical("Element doesn`t exist");
    }


}

void TasksForm::on_buttonAdd_clicked()
{
    qDebug()<<__FUNCTION__;
    editorWidget->setDefault();
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


    for(auto &item : list){
        stream<< item->name <<','
              << item->experience <<','
              << item->state <<','
              << item->date.toString("dd.MM.yyyy") <<','
              << item->difficulty <<','
              << item->urgency <<','
              << item->fear <<','
              << item->skill.trimmed() <<endl;

    }
    taskdata.close();

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


}

void TasksForm::chooseDate_Filter()
{
    qDebug()<<__FUNCTION__;
    ui->buttonDate->setText(task_calendar->selectedDate().toString("dd.MM.yyyy"));
    task_calendar->hide();
    filterTasks(task_calendar->selectedDate());


}

void TasksForm::filterTasks(QDate f_date)
{
    qDebug()<<__FUNCTION__<< "delete";
    for(auto &item:list){
        item->hide();
    }
    qDebug()<<__FUNCTION__<< "add";
    int number=1;
    for(auto &item:list){
        if(item->date == f_date){
            item->setTitle(number);
            item->show();
            number++;
        }

    }


}

void TasksForm::on_buttonDate_clicked()
{
    qDebug()<<__FUNCTION__;
    task_calendar->show();
}

