#include "alarmclock.h"
#include "ui_alarmclock.h"

AlarmClock::AlarmClock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmClock)
{
    ui->setupUi(this);

}

AlarmClock::~AlarmClock()
{
    delete ui;
}



void AlarmClock::on_toolButton_clicked()
{

    parentWidget()->show();
    this->~AlarmClock();
}

void AlarmClock::on_AlarmClock_destroyed()
{

}
