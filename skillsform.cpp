#include "skillsform.h"
#include "ui_skillsform.h"

SkillsForm::SkillsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SkillsForm)
{
    ui->setupUi(this);
}

SkillsForm::~SkillsForm()
{
    delete ui;
}

void SkillsForm::on_pushButton_clicked()
{
    ui->listWidget->addItem(createDialog());

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
        const QString &str1 = ledit1->text();
        return ledit1->text();
    }
    else if (dlg.exec() == QDialog::Rejected){
        return {};
    }
}

