#ifndef ITEMEDITOR_H
#define ITEMEDITOR_H

#include <QWidget>
#include <taskitem.h>

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

private:
    Ui::ItemEditor *ui;
    int calculateExp(int fear, int urgency, int difficulty);
    QDateTime chooseDate();
};

#endif // ITEMEDITOR_H
