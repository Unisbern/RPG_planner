#include "mainwidget.h"
#include "ui_mainwidget.h"


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    tasks_ui = new TasksForm();
    skills_ui = new SkillsForm(); //выделение места в памяти
    user_ui = new UserWidget();
    achievement_ui = new AchievementForm();
    help_ui = new HelpWidget();

    ui->spaceWidget->addWidget(skills_ui);
    ui->spaceWidget->addWidget(tasks_ui);
    ui->spaceWidget->addWidget(user_ui);
    ui->spaceWidget->addWidget(help_ui);
    ui->spaceWidget->addWidget(achievement_ui);

    tasks_ui->hide();
    skills_ui->hide();
    user_ui->hide();
    achievement_ui->hide();
    help_ui->hide();

    //general_experience=1400;
    loadAchievments();
    ui->progressBar->setRange(0,500);
    setlevelinfo();


    connect(this, &MainWidget::onSkillForm_savedata, skills_ui, &SkillsForm::onSkillForm_savedata_get);
    connect(this, &MainWidget::onEditor_loaddata, tasks_ui->editorWidget, &ItemEditor::onEditor_loaddata_get);
    //connect(skills_ui, &SkillsForm::skillListChanched_sig, tasks_ui->editorWidget, &ItemEditor::on_Editor_getSkills);


    //Не работает по неизвестной причине
    //эмит отправлет чекбокс в айтеме
    connect(tasks_ui, &TasksForm::on_check_get, this, &MainWidget::gotExp); //Не работает по неизвестной причине
}

MainWidget::~MainWidget()
{
    saveAchievments();
    delete help_ui;
    delete achievement_ui;
    delete user_ui;
    delete tasks_ui;
    delete skills_ui;
    delete ui;
}

void MainWidget::setlevelinfo()
{
    int level=definelevel(achievement_list[0]);
    ui->progressBar->setValue(achievement_list[0] % 500);

    ui->numLevel->setText(QString("Ваш уровень: %1").arg(level));
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
    user_ui->hide();
    achievement_ui->hide();
    help_ui->hide();

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
    case ACHIEVEMENT_WGT:
        achievement_ui->show();
        break;
    case USER_WGT:
        user_ui->show();
        break;
    case HELP_WGT:
        help_ui->show();
        break;
    default:
        break;
    }

}


void MainWidget::on_progressBar_valueChanged(int value)
{

}


void MainWidget::on_buttonAchievments_clicked()
{
    qDebug() << __FUNCTION__ ;
    setWidget(ACHIEVEMENT_WGT);
}


void MainWidget::on_buttonProflie_clicked()
{
    qDebug() << __FUNCTION__ ;
    setWidget(USER_WGT);
}


void MainWidget::on_buttonHelp_clicked()
{
    qDebug() << __FUNCTION__ ;
    setWidget(HELP_WGT);
}

void MainWidget::loadAchievments()
{
    qDebug()<<__FUNCTION__;
    QFile achivedata("achivedata.csv");
    achivedata.open(QIODevice::ReadWrite);

    if(!achivedata.atEnd()){
        QString dataline = achivedata.readLine();
        QStringList Achive;
        Achive = dataline.split(QLatin1Char(','));
        achievement_list[0] = Achive[0].toInt(); //общий опыт
        achievement_list[1] = Achive[1].toInt(); //количество выполненных тасков
    }
    else {
        achievement_list[0] = 0;
        achievement_list[1] = 0;
    }
    achivedata.close();
}

void MainWidget::saveAchievments()
{
    qDebug()<<__FUNCTION__;
    QFile achivedata("achivedata.csv");
    achivedata.open(QIODevice::ReadWrite);

    QTextStream stream;
    stream.setDevice(&achivedata);

    stream << achievement_list[0] << ','
           << achievement_list[1];
    achivedata.close();

}

void MainWidget::gotExp(TaskItem *item)
{
    achievement_list[0]+=item->experience;
    setlevelinfo();

}
