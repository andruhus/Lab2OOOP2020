#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include <QMainWindow>
#include <QListWidgetItem>
#include "alarmclock.h"
#include "add_a_new_timer_dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_addNewTimer_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    enum Timer_Filters{
        all,
        sport,
        cookery
    };
    Timer_Filters filt_state = all;
    void ComboBoxConfig();
private:
    void UpdateList();
    QString timer_db_name = "C:/Users/aaade/Desktop/programs/OOP/Labus2/Lab2/timers.txt";
private:
    Ui::MainWindow *ui;
    AlarmClock *alarm;
    Settings * setting;
    SysHidden *system;
    Add_a_new_timer_dialog *dialog;
};
#endif // MAINWINDOW_H
