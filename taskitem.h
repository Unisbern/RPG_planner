#ifndef TASKITEM_H
#define TASKITEM_H

#include <QWidget>

namespace Ui {
class taskItem;
}

class TaskItem : public QWidget
{
    Q_OBJECT

public:
    explicit TaskItem(QWidget *parent = nullptr);
    ~TaskItem();

private:
    Ui::taskItem *ui;
};

#endif // TASKITEM_H
