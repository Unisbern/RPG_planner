#ifndef TASKITEM_H
#define TASKITEM_H

#include <QWidget>
#include <QDateTime>
#include <QString>
#include <QDate>
#include <QDebug>
//#include <skillsform.h>

namespace Ui {
class taskItem;
}

class TaskItem : public QWidget
{
    Q_OBJECT

signals:
    void taskdelete_sig(TaskItem *item);

public:
    explicit TaskItem(QWidget *parent = nullptr);
    ~TaskItem();

    QString name;
    int experience;
    bool state;

    QDate date;
    int difficulty;
    int urgency;
    int fear;

    QString skill;

    void update();
    void updatewith(QString lineItemInfo);
    void deleteitem();



    void setTitle(int i);

private slots:
    void on_buttonDelete_clicked();

private:
    Ui::taskItem *ui;

};

#endif // TASKITEM_H
