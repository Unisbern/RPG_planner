#ifndef TASKSFORM_H
#define TASKSFORM_H

#include <QWidget>

namespace Ui {
class tasksform;
}

class TasksForm : public QWidget
{
    Q_OBJECT

public:
    explicit TasksForm(QWidget *parent = nullptr);
    ~TasksForm();

private:
    Ui::tasksform *ui;
};

#endif // TASKSFORM_H
