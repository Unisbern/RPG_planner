#ifndef SKILLSFORM_H
#define SKILLSFORM_H

#include <QWidget>

namespace Ui {
class SkillsForm;
}

class SkillsForm : public QWidget
{
    Q_OBJECT

public:
    explicit SkillsForm(QWidget *parent = nullptr);
    ~SkillsForm();

private:
    Ui::SkillsForm *ui;
};

#endif // SKILLSFORM_H
