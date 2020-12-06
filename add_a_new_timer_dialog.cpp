#include "add_a_new_timer_dialog.h"
#include "ui_add_a_new_timer_dialog.h"
#include <QMessageBox>
#include <QTime>
Add_a_new_timer_dialog::Add_a_new_timer_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_a_new_timer_dialog)
{
    ui->setupUi(this);
}

Add_a_new_timer_dialog::~Add_a_new_timer_dialog()
{
    delete ui;
}

void Add_a_new_timer_dialog::on_pushButton_clicked()
{
    QString hours = ui->lineEdit->text();
    QString minutes = ui->lineEdit_2->text();
    QString seconds = ui->lineEdit_3->text();

    if (!Check_Input(hours,minutes,seconds))
        return;

    int h = hours.toInt();
    int m = minutes.toInt();
    int s = seconds.toInt();
    Write_a_new_Timer(h,m,s);
    QMessageBox::information(this,"Successful","A new timer has been added. Restart the app to see it");
    this->~Add_a_new_timer_dialog();
}

bool Add_a_new_timer_dialog::Check_Input(QString s1, QString s2, QString s3)
{
    bool Is_Fine = true;
    int temp = s1.toInt(&Is_Fine);
    if(!Is_Fine)
    {
        QMessageBox::critical(this,"Error in Hours field","Hours should be an integer");
        return false;
    }
    else if(temp < 0 || temp > 23){
        QMessageBox::critical(this,"Error in Hours field","Hours should be between 0 and 23");
        return false;
    }

    temp = s2.toInt(&Is_Fine);
        if(!Is_Fine)
        {
            QMessageBox::critical(this,"Error in Minutes field","Minutes should be an integer");
            return false;
        }
        else if(temp < 0 || temp > 59){
            QMessageBox::critical(this,"Error in Minutes field","Minutes should be between 0 and 59");
            return false;
        }

    temp = s3.toInt(&Is_Fine);
        if(!Is_Fine)
        {
            QMessageBox::critical(this,"Error in Seconds field","Seconds should be an integer");
            return false;
        }
        else if(temp < 0 || temp > 59){
            QMessageBox::critical(this,"Error in Seconds field","Seconds should be between 0 and 59");
            return false;
        }
        return true;
}

void Add_a_new_timer_dialog::Write_a_new_Timer(int h, int m, int s)
{
    QTime value(h,m,s);
    QString value_str = value.toString();

    QFile file(timer_db_name);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::critical(this,"File error","It is something wrong with your file");
    }
    QTextStream out(&file);
    out << value_str;
    file.flush();
    file.close();
}
