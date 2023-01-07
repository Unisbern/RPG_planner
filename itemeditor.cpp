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
    //connect(&SkillsForm, &SkillsForm::skillListChanched_sig, this, &ItemEditor::on_comboBox_activated); Отправитель коннекта не работает

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

void ItemEditor::addSkillstoForm()
{

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


void ItemEditor::on_comboBox_activated()
{
//    QList<list.lenght(list) namelist = QList<skill_type> list
//    insertItems(int, list) // из листа
    ui->comboBox->showPopup();
    //ui->comboBox->hidePopup();
}

