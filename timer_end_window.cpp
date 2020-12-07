#include "timer_end_window.h"
#include "ui_timer_end_window.h"
#include <QMediaPlayer>
Timer_end_window::Timer_end_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timer_end_window)
{
    ui->setupUi(this);

    //QSound::play("sounds/military-trumpet.mp3");
    QMediaPlayer* music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/military-trumpet.mp3"));
    music->play();
}

Timer_end_window::~Timer_end_window()
{
    delete ui;
}

void Timer_end_window::on_pushButton_2_clicked()
{
    this->~Timer_end_window();
}
