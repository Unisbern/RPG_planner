#ifndef ITEMEDITOR_H
#define ITEMEDITOR_H

#include <QWidget>
#include <taskitem.h>
#include <QCalendarWidget>
#include <QDebug>

namespace Ui {
class ItemEditor;
}

class ItemEditor : public QWidget
{
    Q_OBJECT
signals:
    void taskitem_sig(TaskItem *item);

public:
    explicit ItemEditor(QWidget *parent = nullptr);
    ~ItemEditor();

private slots:
    void on_buttonConfirm_accepted();

    void on_buttonDate_clicked();

    void on_buttonConfirm_rejected();

    void on_calendar();
private:
    Ui::ItemEditor *ui;
    QCalendarWidget *calendar;
    int calculateExp(int fear, int urgency, int difficulty);
    QDate chooseDate();
};

#endif // ITEMEDITOR_H
