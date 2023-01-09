#include "achievementform.h"
#include "ui_achievementform.h"

AchievementForm::AchievementForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AchievementForm)
{
    ui->setupUi(this);
}

AchievementForm::~AchievementForm()
{
    delete ui;
}

void AchievementForm::setLabels(int exp, int tasks, int lvl)
{
    ui->labelExp->setText(QString("Достигнутый опыт: %1").arg(exp));
    ui->labelTasks->setText(QString("Выполнено задач: %1").arg(tasks));
    ui->labelLevel->setText(QString("Достигнутый уровень: %1").arg(lvl));
}
