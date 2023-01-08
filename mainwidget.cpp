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

    general_experience=1400;

    ui->progressBar->setRange(0,500);
    setlevelinfo();

    connect(this, &MainWidget::onSkillForm_savedata, skills_ui, &SkillsForm::onSkillForm_savedata_get);

    connect(this, &MainWidget::onEditor_loaddata, tasks_ui->editorWidget, &ItemEditor::onEditor_loaddata_get);
    //connect(skills_ui, &SkillsForm::skillListChanched_sig, tasks_ui->editorWidget, &ItemEditor::on_Editor_getSkills);
}

MainWidget::~MainWidget()
{
    delete tasks_ui;
    delete skills_ui;
    delete ui;
}

void MainWidget::setlevelinfo()
{
    int level=definelevel(general_experience);
    ui->progressBar->setValue(general_experience % 500);
    //ui->numLevel->settext(string(level));
    qDebug()<< __FUNCTION__ << "level" << level;


}

int MainWidget::definelevel(int general_experience)
{
    qDebug()<<__FUNCTION__;
    if(general_experience<500)
        return 1;
    else{
        int level=2;
        while(general_experience > 500*level){
            level++;
            qDebug()<<"iteration";
        }

        return level-1;

    }

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

    emit onSkillForm_savedata();

    switch (id) {
    case EMPTY_WGT:
        break;
    case TASKS_WGT:
        tasks_ui->show();
        qDebug()<<"Сработал emit" << "onEditor_loaddata";
        emit onEditor_loaddata();
        break;
    case SKILLS_WGT:
        skills_ui->show();

        break;
    default:
        break;
    }

}


void MainWidget::on_progressBar_valueChanged(int value)
{

}

