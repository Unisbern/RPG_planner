#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    tasks_ui = new TasksForm();
    skills_ui = new SkillsForm(); //выделение места в памяти


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

    tasks_ui->show();

}


void MainWidget::on_buttonStatistics_clicked()
{
    qDebug() << __FUNCTION__ ;
    skills_ui->show();

}

