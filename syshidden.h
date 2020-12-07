#ifndef SYSHIDDEN_H
#define SYSHIDDEN_H
#include <QTimer>
#include <QAbstractItemModel>
#include <vector>
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
public slots:
     void UpdateSystem();
public:
     void Add_working_alarm(QTime* time);
     void Add_working_timer(QTime* time);
private:
     void UpdateAlarms();
     void UpdateTimers();
private:
     void ReportAlarm();
     void ReportTimer();
private:
    bool isDisturbed = false;
    QTimer* time;
    std::vector<QTime*> working_alarms;
    std::vector<QTime*> working_timers;
};

#endif // SYSHIDDEN_H
