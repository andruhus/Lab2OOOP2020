#include "syshidden.h"

SysHidden::SysHidden(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant SysHidden::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    return NULL;
}

QModelIndex SysHidden::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
    return NULL;
}

QModelIndex SysHidden::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
    return NULL;
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
