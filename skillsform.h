#ifndef SKILLSFORM_H
#define SKILLSFORM_H

#include <QListWidget>
#include <QDialog>
#include <QDebug>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QFile>

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

private slots:
    void on_pushButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::SkillsForm *ui;
    QString createDialog();



    QList<skill_type> list;




    void savedata(QList<skill_type> list);
    void loaddata();
//    void deleteitem();
};

#endif // SKILLSFORM_H
