#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "syshidden.h"
namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr,QWidget* another_parent = nullptr,SysHidden *system = nullptr);
    ~Settings();

private slots:
    void on_toolButton_2_clicked();

    void on_toolButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Settings *ui;
    QWidget *parent2 = nullptr;
    SysHidden *system;
};

#endif // SETTINGS_H
