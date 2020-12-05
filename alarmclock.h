#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H
#pragma once
#include <QWidget>
#include "settings.h"
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

    void on_toolButton_3_clicked();

private:
    Ui::AlarmClock *ui;
    Settings *setting;

};

#endif // ALARMCLOCK_H
