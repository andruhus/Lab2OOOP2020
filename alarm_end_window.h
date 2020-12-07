#ifndef ALARM_END_WINDOW_H
#define ALARM_END_WINDOW_H
#pragma once
#include <QtMultimedia/QSound>
#include <QDialog>

namespace Ui {
class Alarm_end_window;
}

class Alarm_end_window : public QDialog
{
    Q_OBJECT

public:
    explicit Alarm_end_window(QWidget *parent = nullptr);
    ~Alarm_end_window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Alarm_end_window *ui;

};

#endif // ALARM_END_WINDOW_H
