#ifndef SKILLSFORM_H
#define SKILLSFORM_H

#include <QWidget>
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

private:
    Ui::SkillsForm *ui;
    QString createDialog();
};

#endif // SKILLSFORM_H
