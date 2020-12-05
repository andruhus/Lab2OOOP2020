#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H

#include <QWidget>

namespace Ui {
class AlarmClock;
}

class AlarmClock : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmClock(QWidget *parent = nullptr);
    ~AlarmClock();

private:
    Ui::AlarmClock *ui;
};

#endif // ALARMCLOCK_H
