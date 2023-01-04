#ifndef TASKITEM_H
#define TASKITEM_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class taskItem;
}

class TaskItem : public QWidget
{
    Q_OBJECT

public:
    explicit TaskItem(QWidget *parent = nullptr);
    ~TaskItem();

    typedef int skill_t;

    QString name;
    int expirience;
    bool state;

    QDateTime date;
    int difficulty;
    int urgency;
    int fear;
    skill_t skill;



private:
    Ui::taskItem *ui;
};

#endif // TASKITEM_H
