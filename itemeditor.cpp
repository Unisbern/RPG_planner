#include "itemeditor.h"
#include "ui_itemeditor.h"

ItemEditor::ItemEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemEditor)
{
    ui->setupUi(this);

    calendar = new QCalendarWidget();
    ui->buttonDate->setText(QDate::currentDate().toString("dd.MM.yyyy"));
    connect(calendar, &QCalendarWidget::selectionChanged, this, &ItemEditor::on_calendar);



    //QList<QString> gotSkills = {"Karfagen","should","be destroed"};
    fillupCombobox();
    //метод заполнения листа из блокнота


    //on_Editor_getSkills(QList<SkillsForm::skill_type> list);
    //connect(&SkillsForm, &SkillsForm::skillListChanched_sig, this, &ItemEditor::on_comboBox_activated);// Отправитель коннекта не работает

    //void addSkillstoForm();
}

ItemEditor::~ItemEditor()
{

    delete calendar;
    delete ui;
}

void ItemEditor::setDefault()
{
    ui->textEdit->clear();
    ui->buttonDate->setText(QDate::currentDate().toString("dd.MM.yyyy"));

}

void ItemEditor::on_buttonConfirm_accepted()
{
    TaskItem *item = new TaskItem();
    item->name = ui->textEdit->toPlainText();
    item->date = chooseDate();
    item->state = false;

    item->difficulty = ui->sliderDifficulty->value();
    item->fear = ui->sliderFear->value();
    item->urgency = ui->sliderUrgency->value();
    item->skill = ui->comboBox->currentText();
    item->experience = calculateExp(item->difficulty,item->fear,item->urgency);

    item->update();
    emit taskitem_sig(item);
    this->hide();
//    setOverwriteMode(bool overwrite)
}

int ItemEditor::calculateExp(int fear, int urgency, int difficulty)
{
    return 10*difficulty + 20*fear - urgency*5;
}

QDate ItemEditor::chooseDate()
{
    return calendar->selectedDate();
}

void ItemEditor::fillupCombobox()
{
//    qDebug()<<__FUNCTION__;
//    QFile skillsdata("skillsdata.csv");
//    //if(skillsdata) not empty
//    skillsdata.open(QIODevice::ReadWrite);

//    qDebug()<<"Started using skillfile";

//    while (!skillsdata.atEnd()) {
//            QString dataline = skillsdata.readLine();
//            QStringList SkillInfo;
//            SkillInfo = dataline.split(QLatin1Char(','));

//            Skills_inCombobox[indexSkillname]=SkillInfo[0];
//            indexSkillname++;
//        }
//    qDebug()<<"Clear";
//    ui->comboBox->clear();
//    qDebug()<<"Add";
//    ui->comboBox->addItems(Skills_inCombobox);


}



void ItemEditor::chooseSkill()
{
    ui->comboBox->hidePopup();

}


void ItemEditor::on_buttonDate_clicked()
{

    calendar->show();
}


void ItemEditor::on_buttonConfirm_rejected()
{
    this->hide();
}

void ItemEditor::on_calendar()
{
    qDebug()<<__FUNCTION__;
    ui->buttonDate->setText(calendar->selectedDate().toString("dd.MM.yyyy"));
    calendar->hide();

}

void ItemEditor::on_Editor_getSkills(QList<SkillsForm::skill_type> list)
{
    qDebug() << __FUNCTION__<<list.length();
    gotSkills.clear();
    ui->comboBox->clear();

    for(int i=0; list.length();i++){
        gotSkills[i]=list[i].skillname;
    }
    ui->comboBox->addItems(gotSkills);

    //ui->comboBox->insertItems(skillname_list)
    //ui->comboBox->addItems(skillname_list);

}


void ItemEditor::on_comboBox_activated()
{
    qDebug()<<__FUNCTION__;


    //ui->comboBox->showPopup();
    //QMessageBoxPrivate.information

    //chooseSkill();

}

