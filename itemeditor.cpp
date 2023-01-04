#include "itemeditor.h"
#include "ui_itemeditor.h"

ItemEditor::ItemEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemEditor)
{
    ui->setupUi(this);
}

ItemEditor::~ItemEditor()
{
    delete ui;
}

void ItemEditor::on_buttonConfirm_accepted()
{
    TaskItem *item = new TaskItem();
    item->name = ui->textEdit->toPlainText();
    item->datetime = chooseDate();
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

QDateTime ItemEditor::chooseDate()
{
    return QDateTime();
}

