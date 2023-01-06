#include "skillsform.h"
#include "ui_skillsform.h"

SkillsForm::SkillsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SkillsForm)
{

    ui->setupUi(this);
    //tableWidget->setRowCount(10);
    //ui->tableSkill->setCurrentIndex()
}

SkillsForm::~SkillsForm()
{
    delete ui;
}

void SkillsForm::on_pushButton_clicked()
{
    auto a = createDialog();

    if(!a.isEmpty()){
        ui->listWidget->addItem(a);
    }


}

QString SkillsForm::createDialog()
{
    qDebug()<<__FUNCTION__;
    QDialog dlg(this);
    dlg.setFixedSize(300,90);
    dlg.setWindowTitle(tr("Введите навык"));

    QLineEdit *ledit1 = new QLineEdit(&dlg);

    QDialogButtonBox *btn_box = new QDialogButtonBox(&dlg);
    btn_box->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(btn_box, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);
    connect(btn_box, &QDialogButtonBox::rejected, &dlg, &QDialog::reject);

    QFormLayout *layout = new QFormLayout();
    layout->addRow(tr("Введите навык"), ledit1);
    layout->addWidget(btn_box);
    dlg.setLayout(layout);

    if(dlg.exec() == QDialog::Accepted) {

        qDebug()<<"ended positive dialog";

        return ledit1->text();
    }
    else {

        qDebug()<<" Reject button";
        dlg.close();
        qDebug()<<"ended negative dialog";

        return {};
    }

}

void SkillsForm::savedata(QList<skill_type> list)
{
    qDebug()<<__FUNCTION__;
    QFile skillsdata;
    QTextStream stream;

    stream.setDevice(&skillsdata);
    skillsdata.setFileName("skillsdata.csv");
    skillsdata.open(QIODevice::ReadWrite);


    for(auto &item : list){
        stream<< item.skillname <<','
              << item.experience << endl;

    }
    skillsdata.close();

}

void SkillsForm::loaddata()
{
    qDebug()<<__FUNCTION__;
    QFile skillsdata("skillsdata.csv");
    skillsdata.open(QIODevice::ReadWrite);

    while (!skillsdata.atEnd()) {
            QString dataline = skillsdata.readLine();
           // TaskItem *item = new TaskItem;
            //item->updatewith(line);

            qDebug()<<__FUNCTION__<< list;// << line;

            //this->on_taskitem_get(item);
        }

}

void SkillsForm::on_deleteButton_clicked()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}
