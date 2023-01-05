#include "taskitem.h"
#include "ui_taskitem.h"

TaskItem::TaskItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::taskItem)
{
    ui->setupUi(this);
}

TaskItem::~TaskItem()
{
    delete ui;
}

void TaskItem::update()
{
    static int i=0;
    ui->name->setText(name);
    ui->experience->setText(QString("Опыт: %1").arg(expirience));
    ui->groupBox->setTitle(QString("Миссия: %1").arg(++i));

}

void TaskItem::updatewith(QString lineItemInfo)
{
     QStringList ItemInfo;
     ItemInfo = lineItemInfo.split(QLatin1Char(','));
     name = ItemInfo[0];
     expirience = ItemInfo[1].toInt();
     state = ItemInfo[2].contains('1', Qt::CaseInsensitive);
     date = QDate::fromString(ItemInfo[3], "ddd MMM d yyyy");
     difficulty = ItemInfo[4].toInt();
     urgency = ItemInfo[5].toInt();
     fear = ItemInfo[6].toInt();
     skill = ItemInfo[7].toInt();

     this->update();



}
