#ifndef SKILLSFORM_H
#define SKILLSFORM_H

#include <QtableWidget>
#include <QDialog>
#include <QDebug>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>

namespace Ui {
class SkillsForm;
}

class SkillsForm : public QWidget
{
    Q_OBJECT

public:
    explicit SkillsForm(QWidget *parent = nullptr);
    ~SkillsForm();

private slots:
    void on_pushButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::SkillsForm *ui;
    QString createDialog();

    struct skill_t
    {
        skill_t() {
            QString skillname;
            int experience;
        }
    };

    QList<skill_t> list;
    QTableWidget *tableSkill;




//    void savedata(QList<TaskItem *> list);
//    void loaddata();
//    void deleteitem();
};

#endif // SKILLSFORM_H
