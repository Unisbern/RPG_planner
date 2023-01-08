#ifndef TASKSFORM_H
#define TASKSFORM_H

#include <QWidget>
#include <QFile>
#include <QDebug>
#include <taskitem.h>
#include <itemeditor.h>
#include <QCalendarWidget>


namespace Ui {
class tasksform;
}

class TasksForm : public QWidget
{
    Q_OBJECT


public:
    explicit TasksForm(QWidget *parent = nullptr);
    ~TasksForm();
    ItemEditor *editorWidget;


public slots:
    void on_taskitem_get(TaskItem *item);
    void on_taskdelete_get(TaskItem *item);

private slots:
    void on_buttonAdd_clicked();

    void on_buttonDate_clicked();

private:
    QCalendarWidget *task_calendar;
    Ui::tasksform *ui;
    QList<TaskItem *> list;



    void savedata(QList<TaskItem *> list);
    void loaddata();
    void deleteitem();

    void chooseDate_Filter();
    void filterTasks(QDate f_date);




};

#endif // TASKSFORM_H
