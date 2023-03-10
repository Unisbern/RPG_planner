#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <skillsform.h>
#include <tasksform.h>
#include <itemeditor.h>
#include <achievementform.h>
#include <helpwidget.h>
#include <QWidget>
#include <QDebug>
#include <QList>
#include <QFile>
#include <QTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT


signals:
    void onSkillForm_savedata();
    void onEditor_loaddata();

public slots:
    void gotExp(TaskItem *item);

private slots:
    void on_buttonTasks_clicked();
    void on_buttonStatistics_clicked();
    void on_buttonAchievments_clicked();
    void on_buttonHelp_clicked();
    void on_timeout();

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void setlevelinfo();
    QList<int> achievement_list;
    int definelevel(int general_experience);
    int general_experience;

private:
    Ui::MainWidget *ui;
    SkillsForm *skills_ui;
    TasksForm *tasks_ui;
    AchievementForm *achievement_ui;
    HelpWidget *help_ui;
    QTimer *timer;

    void loadAchievments();
    void saveAchievments();
    typedef enum {EMPTY_WGT, TASKS_WGT, SKILLS_WGT, ACHIEVEMENT_WGT, HELP_WGT} widget_t;
    void setWidget(widget_t id);
    void change_AchiveWidget();
    int time_tillEnd();

};
#endif // MAINWIDGET_H
