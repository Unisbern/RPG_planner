#include "skillsform.h"
#include "ui_skillsform.h"

SkillsForm::SkillsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SkillsForm)
{

    ui->setupUi(this);
    loaddata();
}

SkillsForm::~SkillsForm()
{
//    for(auto &item : list){
//        delete item;
//    }
    savedata();
    delete ui;
}

void SkillsForm::on_pushButton_clicked()
{
    auto enteredSkill = createDialog();
    skill_type skill;
    skill.skillname=enteredSkill;
    skill.experience=0;

    if(!enteredSkill.isEmpty()){

        ui->listWidget->addItem(enteredSkill);
        list.append(skill);



    }


}

QString SkillsForm::createDialog()
{
    qDebug()<<__FUNCTION__;
    QDialog dlg(this);
    dlg.setFixedSize(300,90);
    dlg.setWindowTitle(tr("Введите навык"));

    QLineEdit *enteredSkill= new QLineEdit(&dlg);

    QDialogButtonBox *btn_box = new QDialogButtonBox(&dlg);
    btn_box->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(btn_box, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);
    connect(btn_box, &QDialogButtonBox::rejected, &dlg, &QDialog::reject);

    QFormLayout *layout = new QFormLayout();
    layout->addRow(tr("Введите навык"), enteredSkill);
    layout->addWidget(btn_box);
    dlg.setLayout(layout);

    if(dlg.exec() == QDialog::Accepted) {

        qDebug()<<"ended positive dialog";
        return enteredSkill->text();
        emit skillListChanched_sig(list);
    }
    else {

        qDebug()<<" Reject button";
        dlg.close();
        qDebug()<<"ended negative dialog";

        return {};
    }

}

void SkillsForm::savedata()
{
    qDebug()<<__FUNCTION__;
    QFile skillsdata;
    QTextStream stream;

    stream.setDevice(&skillsdata);
    skillsdata.setFileName("skillsdata.csv");
    skillsdata.open(QIODevice::ReadWrite);


    for(auto &item : list){
        stream<< item.skillname <<','
              << item.experience  << endl;

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
            QStringList SkillInfo;
            SkillInfo = dataline.split(QLatin1Char(','));

            skill_type skill;
            skill.skillname=SkillInfo[0];
            skill.experience=SkillInfo[1].toInt();

            ui->listWidget->addItem(skill.skillname);
            list.append(skill);

            //qDebug()<<__FUNCTION__<< list; // << line;

            //this->on_taskitem_get(item);
        }

}

void SkillsForm::on_deleteButton_clicked()
{
    list.removeAt(ui->listWidget->currentRow());
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}
