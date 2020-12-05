#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H
#pragma once
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

private slots:


    void on_toolButton_clicked();

    void on_AlarmClock_destroyed();

private:
    Ui::AlarmClock *ui;

};

#endif // ALARMCLOCK_H
