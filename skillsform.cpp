#include "skillsform.h"
#include "ui_skillsform.h"

SkillsForm::SkillsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SkillsForm)
{
    ui->setupUi(this);
}

SkillsForm::~SkillsForm()
{
    delete ui;
}
