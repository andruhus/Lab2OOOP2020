#include "add_a_new_alarm_dialog.h"
#include "ui_add_a_new_alarm_dialog.h"

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
