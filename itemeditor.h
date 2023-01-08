#ifndef ITEMEDITOR_H
#define ITEMEDITOR_H

#include <QWidget>
#include <taskitem.h>
#include <QCalendarWidget>
#include <QDebug>
#include <skillsform.h>
#include <QDialog>
#include <QList>
#include <QComboBox>

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
    void setDefault();

private slots:
    void on_buttonConfirm_accepted();
    void on_buttonConfirm_rejected();

    void on_buttonDate_clicked();
    void on_calendar();

    void on_comboBox_activated();

private:
    Ui::ItemEditor *ui;
    QCalendarWidget *calendar;
    int calculateExp(int fear, int urgency, int difficulty);
    QDate chooseDate();

    void fillupCombobox();
    QList<QString> gotSkills;

};

#endif // ITEMEDITOR_H
