#include "timer_end_window.h"
#include "ui_timer_end_window.h"

Timer_end_window::Timer_end_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timer_end_window)
{
    ui->setupUi(this);
}

Timer_end_window::~Timer_end_window()
{
    delete ui;
}
