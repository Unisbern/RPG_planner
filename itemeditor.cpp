#include "itemeditor.h"
#include "ui_itemeditor.h"

ItemEditor::ItemEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemEditor)
{
    ui->setupUi(this);
    calendar = new QCalendarWidget();
    connect(calendar, &QCalendarWidget::selectionChanged, this, &ItemEditor::on_calendar);
    ui->buttonDate->setText(QDate::currentDate().toString("ddd MMM d yyyy"));
}

ItemEditor::~ItemEditor()
{

    delete calendar;
    delete ui;
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
    item->skill = TaskItem::skill_t(); //здесь присваивается рандомный скилл
    item->expirience = calculateExp(item->difficulty,item->fear,item->urgency);

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
    ui->buttonDate->setText(calendar->selectedDate().toString());
    calendar->hide();

}

