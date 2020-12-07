#include "alarm_end_window.h"
#include "ui_alarm_end_window.h"

Alarm_end_window::Alarm_end_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alarm_end_window)
{
    ui->setupUi(this);
}

Alarm_end_window::~Alarm_end_window()
{
    delete ui;
}
