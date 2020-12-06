#ifndef SYSHIDDEN_H
#define SYSHIDDEN_H
#include <QTimer>
#include <QAbstractItemModel>

class SysHidden : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit SysHidden(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    // My functionality
    bool Get_Disturb();
    void Set_Disturb(bool dis);
public slot:
     void MyFunc()

private:
    bool isDisturbed = false;
    QTimer* time;

};

#endif // SYSHIDDEN_H
