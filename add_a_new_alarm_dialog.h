#ifndef ADD_A_NEW_ALARM_DIALOG_H
#define ADD_A_NEW_ALARM_DIALOG_H
#pragma once
#include <QDialog>
#include <QFile>
#include <QTextStream>
namespace Ui {
class Add_a_new_alarm_dialog;
}

class Add_a_new_alarm_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Add_a_new_alarm_dialog(QWidget *parent = nullptr);
    ~Add_a_new_alarm_dialog();

private slots:
    void on_pushButton_clicked();

private:
    bool Check_Input(QString s1,QString s2,QString s3);
    void Write_a_new_Alarm(int h,int m,int s);

private:
    Ui::Add_a_new_alarm_dialog *ui;
    QString alarm_db_name = "C:/Users/aaade/Desktop/programs/OOP/Labus2/Lab2/alarms.txt";
};

#endif // ADD_A_NEW_ALARM_DIALOG_H
