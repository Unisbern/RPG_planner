#ifndef TASKSFORM_H
#define TASKSFORM_H

#include <QWidget>

namespace Ui {
class tasksform;
}

class tasksform : public QWidget
{
    Q_OBJECT

public:
    explicit tasksform(QWidget *parent = nullptr);
    ~tasksform();

private:
    Ui::tasksform *ui;
};

#endif // TASKSFORM_H
