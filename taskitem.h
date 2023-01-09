#ifndef TASKITEM_H
#define TASKITEM_H

#include <QWidget>
#include <QDateTime>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QDialog>
#include <QDialogButtonBox>

namespace Ui {
class taskItem;
}

class TaskItem : public QWidget
{
    Q_OBJECT

signals:
    void taskdelete_sig(TaskItem *item);
    void gotExp_sig(int experience);


private slots:
    void on_buttonDelete_clicked();
    void on_check_stateChanged(int arg1);

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
    void setTitle(int i);

    Ui::taskItem *ui;


private:

    void confirmDialog();
    void accrueExp();

};

#endif // TASKITEM_H
