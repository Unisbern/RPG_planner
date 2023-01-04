#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    tasks_ui = new TasksForm();
    skills_ui = new SkillsForm(); //выделение места в памяти

    ui->spaceWidget->addWidget(skills_ui);
    ui->spaceWidget->addWidget(tasks_ui);

    tasks_ui->hide();
    skills_ui->hide();
}

MainWidget::~MainWidget()
{
    delete tasks_ui;
    delete skills_ui;
    delete ui;
}


void MainWidget::on_buttonTasks_clicked()
{
    qDebug() << __FUNCTION__ ; //вызов функции
    setWidget(TASKS_WGT);

}


void MainWidget::on_buttonStatistics_clicked()
{
    qDebug() << __FUNCTION__ ;
    setWidget(SKILLS_WGT);

}

void MainWidget::setWidget(widget_t id)
{

    qDebug()<<__FUNCTION__<<id;
    tasks_ui->hide();
    skills_ui->hide();
    switch (id) {
    case EMPTY_WGT:
        break;
    case TASKS_WGT:
        tasks_ui->show();
        break;
    case SKILLS_WGT:
        skills_ui->show();
        break;
    default:
        break;
    }

}

