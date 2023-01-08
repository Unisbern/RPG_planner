#ifndef SKILLSFORM_H
#define SKILLSFORM_H

#include <QListWidget>
#include <QDialog>
#include <QDebug>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QFile>
#include <QList>

namespace Ui {
class SkillsForm;
}

class SkillsForm : public QWidget
{
    Q_OBJECT

public:
    explicit SkillsForm(QWidget *parent = nullptr);
    ~SkillsForm();

    struct skill_type
    {
        QString skillname;
        int experience;
    };

    QList<skill_type> list;

//signals:
    //void skillListChanched_sig(QList<skill_type> list);


public slots:
    void on_pushButton_clicked();
    void on_deleteButton_clicked();
    void onSkillForm_savedata_get();

private:
    Ui::SkillsForm *ui;
    QString createDialog();

    void savedata();
    void loaddata();
//    void deleteitem();
};

#endif // SKILLSFORM_H
