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
