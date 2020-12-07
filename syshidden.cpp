#include "syshidden.h"
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
SysHidden::SysHidden(QObject *parent)
    : QAbstractItemModel(parent)
{
    time = new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(UpdateSystem()));
    time->start(1000);
}

QVariant SysHidden::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    return NULL;
}

QModelIndex SysHidden::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
    return parent;
}

QModelIndex SysHidden::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
    return index;
}

int SysHidden::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int SysHidden::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant SysHidden::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}

bool SysHidden::Get_Disturb()
{
    return isDisturbed;
}

void SysHidden::Set_Disturb(bool dis)
{
    isDisturbed = dis;
}

void SysHidden::UpdateSystem(){

    UpdateAlarms();
    UpdateTimers();
}

void SysHidden::Add_working_alarm(QTime *time)
{
    working_alarms.push_back(time);
}

void SysHidden::Add_working_timer(QTime *time)
{
    working_timers.push_back(time);


}

void SysHidden::UpdateAlarms()
{
    QTime now = QTime::currentTime();
    for(int x = 0;x<working_alarms.size();x++)
        if(*working_alarms[x] == now)
        {
            ReportAlarm();
            working_alarms.erase(working_alarms.begin()+x);
            x--;
        }
}

void SysHidden::UpdateTimers()
{
    QTime end(0,0,0);
    for(int x = 0;x<working_timers.size();x++)
    {
        working_timers[x]->addSecs(-1);
        if(*working_timers[x] == end){
            ReportTimer();
            working_timers.erase(working_timers.begin()+x);
            x--;
        }
    }
}

void SysHidden::ReportAlarm()
{

    win1 = new Alarm_end_window();
    win1->show();
}

void SysHidden::ReportTimer()
{
    win2 = new Timer_end_window();
    win2->show();
}
