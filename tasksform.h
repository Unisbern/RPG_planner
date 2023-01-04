#ifndef TASKSFORM_H
#define TASKSFORM_H

#include <QWidget>
#include <QDebug>
#include <taskitem.h>

namespace Ui {
class tasksform;
}

class TasksForm : public QWidget
{
    Q_OBJECT

public:
    explicit TasksForm(QWidget *parent = nullptr);
    ~TasksForm();

private slots:
    void on_buttonAdd_clicked();

private:
    Ui::tasksform *ui;
    QList<TaskItem *> list;

};

#endif // TASKSFORM_H
