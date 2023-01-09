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


}

ItemEditor::~ItemEditor()
{
    qDebug()<<__FUNCTION__;
    delete calendar;
    delete ui;
}

void ItemEditor::setDefault()
{
    qDebug()<<__FUNCTION__;
    ui->textEdit->clear();
    ui->buttonDate->setText(QDate::currentDate().toString("dd.MM.yyyy"));

}

void ItemEditor::onEditor_loaddata_get()
{
    qDebug()<<__FUNCTION__;
    ui->comboBox->clear();
    fillupCombobox();

}

void ItemEditor::on_buttonConfirm_accepted()
{
    TaskItem *item = new TaskItem();
    item->name = ui->textEdit->text();
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
    qDebug()<<__FUNCTION__;
    QFile skillsdata("skillsdata.csv");
    skillsdata.open(QIODevice::ReadWrite);

    qDebug()<<"Started using skillfile";
    gotSkills.clear();
    while (!skillsdata.atEnd()) {
            QString dataline = skillsdata.readLine();
            QStringList SkillInfo = dataline.split(QLatin1Char(','));
            gotSkills.append(SkillInfo[0]);
        }
    qDebug()<<"Clear";
    ui->comboBox->clear();
    qDebug()<<"Add";
    ui->comboBox->addItems(gotSkills);

}


void ItemEditor::on_buttonDate_clicked()
{
    qDebug()<<__FUNCTION__;
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

void ItemEditor::on_comboBox_activated()
{
    qDebug()<<__FUNCTION__;
}

