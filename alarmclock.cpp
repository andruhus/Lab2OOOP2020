#include "alarmclock.h"
#include "ui_alarmclock.h"

AlarmClock::AlarmClock(QWidget *parent,SysHidden *sys) :
    QWidget(parent),
    ui(new Ui::AlarmClock)
{
    ui->setupUi(this);
    system = sys;
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

void AlarmClock::on_toolButton_3_clicked()
{
    hide();
    setting = new Settings(this,nullptr,system);
    setting->setWindowFlags( Qt::Window );
    setting->setAttribute( Qt::WA_DeleteOnClose );
    setting->show();
}

void AlarmClock::on_pushButton_clicked()
{
    dialog = new Add_a_new_alarm_dialog(this);
    dialog->show();
}
