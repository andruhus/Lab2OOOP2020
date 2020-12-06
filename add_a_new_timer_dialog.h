#ifndef ADD_A_NEW_TIMER_DIALOG_H
#define ADD_A_NEW_TIMER_DIALOG_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
namespace Ui {
class Add_a_new_timer_dialog;
}

class Add_a_new_timer_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Add_a_new_timer_dialog(QWidget *parent = nullptr);
    ~Add_a_new_timer_dialog();

private slots:
    void on_pushButton_clicked();

private:
    bool Check_Input(QString s1,QString s2,QString s3);
    void Write_a_new_Timer(int h,int m,int s);

private:
    Ui::Add_a_new_timer_dialog *ui;
    QString timer_db_name = "C:/Users/aaade/Desktop/programs/OOP/Labus2/Lab2/timers.txt";
};

#endif // ADD_A_NEW_TIMER_DIALOG_H
