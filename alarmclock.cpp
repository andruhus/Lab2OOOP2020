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
    setting = new Settings(this,nullptr);
    setting->setWindowFlags( Qt::Window );
    setting->setAttribute( Qt::WA_DeleteOnClose );
    setting->show();
}
