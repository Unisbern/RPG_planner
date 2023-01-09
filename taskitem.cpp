#include "taskitem.h"
#include "ui_taskitem.h"

TaskItem::TaskItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::taskItem)
{
    ui->setupUi(this);

    //connect(this, &TaskItem::gotExp_sig, ui, &MainWidget::gotExp);
//    connect(this, &TaskItem::gotExp_sig, , &TasksForm::on_check_get);
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
    ui->labelSkill->setText(skill);

}

void TaskItem::updatewith(QString lineItemInfo)
{
     qDebug()<<__FUNCTION__;
     QStringList ItemInfo;
     ItemInfo = lineItemInfo.split(QLatin1Char(','));
     name = ItemInfo[0];
     experience = ItemInfo[1].toInt();
     state = ItemInfo[2].contains('0', Qt::CaseInsensitive);
     date = QDate::fromString(ItemInfo[3], "dd.MM.yyyy");
     difficulty = ItemInfo[4].toInt();
     urgency = ItemInfo[5].toInt();
     fear = ItemInfo[6].toInt();
     qDebug()<<"Записываем скилл"<<ItemInfo[7];
     skill = ItemInfo[7];

     this->update();

}

void TaskItem::on_buttonDelete_clicked()
{
    qDebug()<<__FUNCTION__;
    emit taskdelete_sig(this);

}


void TaskItem::confirmDialog()
{
    qDebug()<<__FUNCTION__;
    QDialog dlg(this);
    dlg.setFixedSize(500,50);
    dlg.setWindowTitle(tr("Вы уверены, что выполнили задание?"));

    QDialogButtonBox *btn_box = new QDialogButtonBox(&dlg);
    btn_box->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    btn_box->setGeometry(60,5,300,40);

    connect(btn_box, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);
    connect(btn_box, &QDialogButtonBox::rejected, &dlg, &QDialog::reject);

//    QFormLayout *layout = new QFormLayout();
//    layout->addRow(tr("Введите навык"), enteredSkill);
//    layout->addWidget(btn_box);
//    dlg.setLayout(layout);

    if(dlg.exec() == QDialog::Accepted) {

        qDebug()<<"check accepted";
        accrueExp();

    }
    else {
        ui->check->setCheckState(Qt::Unchecked);
        qDebug()<<"check rejected";
        //dlg.close();
    }
    dlg.close();

}

void TaskItem::accrueExp()
{
    emit gotExp_sig(this);
    on_buttonDelete_clicked();
    //вызов функции начисления опыта и удаления таска
}

void TaskItem::on_check_stateChanged(int arg1)
{
    confirmDialog();

}

