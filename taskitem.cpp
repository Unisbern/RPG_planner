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
    delete ui; //delete taskitem
}

void TaskItem::setTitle(int i)
{
    ui->groupBox->setTitle(QString("Миссия: %1").arg(i));
}

void TaskItem::update()
{

    ui->name->setText(name);
    ui->experience->setText(QString("Опыт: %1").arg(experience));

}

void TaskItem::updatewith(QString lineItemInfo)
{
     QStringList ItemInfo;
     ItemInfo = lineItemInfo.split(QLatin1Char(','));
     name = ItemInfo[0];
     experience = ItemInfo[1].toInt();
     state = ItemInfo[2].contains('1', Qt::CaseInsensitive);
     date = QDate::fromString(ItemInfo[3], "dd.MM.yyyy");
     difficulty = ItemInfo[4].toInt();
     urgency = ItemInfo[5].toInt();
     fear = ItemInfo[6].toInt();
     skill = ItemInfo[7].toInt();

     this->update();



}

void TaskItem::on_buttonDelete_clicked()
{
    qDebug()<<__FUNCTION__;
    emit taskdelete_sig(this);

}

