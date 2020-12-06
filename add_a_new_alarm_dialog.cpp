#include "add_a_new_alarm_dialog.h"
#include "ui_add_a_new_alarm_dialog.h"
#include<QMessageBox>
Add_a_new_alarm_dialog::Add_a_new_alarm_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_a_new_alarm_dialog)
{
    ui->setupUi(this);
}

Add_a_new_alarm_dialog::~Add_a_new_alarm_dialog()
{
    delete ui;
}

bool Add_a_new_alarm_dialog::Check_Input(QString s1, QString s2, QString s3)
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


void Add_a_new_alarm_dialog::on_pushButton_clicked()
{
    QString hours = ui->lineEdit->text();
    QString minutes = ui->lineEdit_2->text();
    QString seconds = ui->lineEdit_3->text();

    if (!Check_Input(hours,minutes,seconds))
        return;

    QMessageBox::information(this,"Successful","A new timer has been added");
    this->~Add_a_new_alarm_dialog();
}
