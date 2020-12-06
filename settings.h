#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr,QWidget* another_parent = nullptr);
    ~Settings();

private slots:
    void on_toolButton_2_clicked();

    void on_toolButton_clicked();

private:
    Ui::Settings *ui;
    QWidget *parent2 = nullptr;
};

#endif // SETTINGS_H
