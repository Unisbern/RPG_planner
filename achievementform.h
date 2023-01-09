#ifndef ACHIEVEMENTFORM_H
#define ACHIEVEMENTFORM_H
#include <QWidget>

namespace Ui {
class AchievementForm;
}

class AchievementForm : public QWidget
{
    Q_OBJECT

public:
    explicit AchievementForm(QWidget *parent = nullptr);
    ~AchievementForm();
    void setLabels(int exp, int tasks, int lvl);

private:
    Ui::AchievementForm *ui;
};

#endif // ACHIEVEMENTFORM_H
