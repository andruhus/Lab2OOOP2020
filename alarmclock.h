#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H
#pragma once
#include <QWidget>
#include "settings.h"
#include "add_a_new_alarm_dialog.h"
namespace Ui {
class AlarmClock;
}

class AlarmClock : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmClock(QWidget *parent = nullptr,SysHidden *sys = nullptr);
    ~AlarmClock();

private slots:


    void on_toolButton_clicked();

    void on_AlarmClock_destroyed();

    void on_toolButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::AlarmClock *ui;
    Settings *setting;
    SysHidden *system;
    Add_a_new_alarm_dialog *dialog;
};

#endif // ALARMCLOCK_H
