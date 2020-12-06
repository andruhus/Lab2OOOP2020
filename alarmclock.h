#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H
#pragma once
#include <QWidget>
#include <QListWidgetItem>
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

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    enum Alarm_Filters{
        all,
        am,
        pm
    };
    Alarm_Filters filt_state = all;
    void ComboBoxConfig();
private:
    void UpdateList();
    QString alarm_db_name = "C:/Users/aaade/Desktop/programs/OOP/Labus2/Lab2/alarms.txt";

private:
    Ui::AlarmClock *ui;
    Settings *setting;
    SysHidden *system;
    Add_a_new_alarm_dialog *dialog;
};

#endif // ALARMCLOCK_H
