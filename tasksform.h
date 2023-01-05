#ifndef TASKSFORM_H
#define TASKSFORM_H

#include <QWidget>
#include <QFile>
#include <QDebug>
#include <taskitem.h>
#include <itemeditor.h>

namespace Ui {
class tasksform;
}

class TasksForm : public QWidget
{
    Q_OBJECT


public:
    explicit TasksForm(QWidget *parent = nullptr);
    ~TasksForm();

public slots:
    void on_taskitem_get(TaskItem *item);

private slots:
    void on_buttonAdd_clicked();

private:
    Ui::tasksform *ui;
    QList<TaskItem *> list;



    void savedata(QList<TaskItem *> list);
    void loaddata();

    ItemEditor *editorWidget;

};

#endif // TASKSFORM_H
