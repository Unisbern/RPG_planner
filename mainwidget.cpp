#include "mainwidget.h"
#include "ui_mainwidget.h"


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    tasks_ui = new TasksForm();
    skills_ui = new SkillsForm();
    achievement_ui = new AchievementForm();
    help_ui = new HelpWidget();

    ui->spaceWidget->addWidget(skills_ui);
    ui->spaceWidget->addWidget(tasks_ui);
    ui->spaceWidget->addWidget(help_ui);
    ui->spaceWidget->addWidget(achievement_ui);

    tasks_ui->hide();
    skills_ui->hide();
    achievement_ui->hide();
    help_ui->hide();

    loadAchievments();
    ui->progressBar->setRange(0,500);
    ui->progressBar->setStyleSheet("QProgressBar { border: 1px solid grey; text-align: middle; border-radius: 5px;} QProgressBar::chunk {background-color: #05B8CC; width: 10px;}");
    setlevelinfo();

    ui->timeBar->setRange(0,86400);
    ui->timeBar->setStyleSheet("QProgressBar { border: 1px solid grey; text-align: middle; border-radius: 5px;} QProgressBar::chunk {background-color: #CD96CD; width: 10px;}");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWidget::on_timeout);
    timer->start(1000);

    connect(this, &MainWidget::onSkillForm_savedata, skills_ui, &SkillsForm::onSkillForm_savedata_get);
    connect(this, &MainWidget::onEditor_loaddata, tasks_ui->editorWidget, &ItemEditor::onEditor_loaddata_get);
    connect(tasks_ui, &TasksForm::on_Exp, this, &MainWidget::gotExp);
}

MainWidget::~MainWidget()
{
    saveAchievments();
    delete help_ui;
    delete achievement_ui;
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
        change_AchiveWidget();
        achievement_ui->show();
        break;
    case HELP_WGT:
        help_ui->show();
        break;
    default:
        break;
    }

}

void MainWidget::change_AchiveWidget()
{
    achievement_ui->setLabels(achievement_list[0],achievement_list[1],definelevel(achievement_list[0]));

}

void MainWidget::on_timeout()
{
    qDebug()<<__FUNCTION__;
    ui->timeBar->setValue(QTime::currentTime().msecsSinceStartOfDay() / 1000);
}

void MainWidget::on_buttonAchievments_clicked()
{
    qDebug() << __FUNCTION__ ;
    setWidget(ACHIEVEMENT_WGT);
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
    if(achivedata.size() > 0){
        QString dataline = achivedata.readLine();
        QStringList Achive = dataline.split(QLatin1Char(','));
        if(Achive.size() == 2){
            achievement_list.append(Achive[0].toInt());
            achievement_list.append(Achive[1].toInt());
        } else {
            qWarning("Format corrupt") ;
            achievement_list.append(0);
            achievement_list.append(0);
        }
    } else {
        qWarning("Achive file is empty") ;
        achievement_list.append(0);
        achievement_list.append(0);
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

    stream << achievement_list[0] <<','
           << achievement_list[1]<< Qt::endl;
    achivedata.close();

}

void MainWidget::gotExp(TaskItem *item)
{
    achievement_list[0]+=item->experience;
    achievement_list[1]++;
    setlevelinfo();

}
