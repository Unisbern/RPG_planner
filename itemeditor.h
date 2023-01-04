#ifndef ITEMEDITOR_H
#define ITEMEDITOR_H

#include <QWidget>

namespace Ui {
class ItemEditor;
}

class ItemEditor : public QWidget
{
    Q_OBJECT

public:
    explicit ItemEditor(QWidget *parent = nullptr);
    ~ItemEditor();

private:
    Ui::ItemEditor *ui;
};

#endif // ITEMEDITOR_H
