#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <skillsform.h>
#include <tasksform.h>
#include <QDebug>
#include <QList>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void setlevelinfo();
    int definelevel(int general_experience);

private slots:
    void on_buttonTasks_clicked();
    void on_buttonStatistics_clicked();


    void on_progressBar_valueChanged(int value);

private:
    Ui::MainWidget *ui;
    SkillsForm *skills_ui; //экземпляр смотри main
    TasksForm *tasks_ui;
    typedef enum {EMPTY_WGT, TASKS_WGT, SKILLS_WGT} widget_t;
    void setWidget(widget_t id);

    bool shouldSaveSkills;
    int general_experience;


};
#endif // MAINWIDGET_H
