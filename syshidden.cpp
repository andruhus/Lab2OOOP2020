#include "syshidden.h"
#include <QDebug>
#include <QMessageBox>
SysHidden::SysHidden(QObject *parent)
    : QAbstractItemModel(parent)
{
    time = new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(MyFunc()));
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

void SysHidden::MyFunc(){
    //qDebug() << "tut";

}

void SysHidden::Add_working_alarm(QTime *time)
{
    working_alarms.push_back(time);
}

void SysHidden::Add_working_timer(QTime *time)
{
    working_timers.push_back(time);


}
