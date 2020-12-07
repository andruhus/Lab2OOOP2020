#include "alarm_end_window.h"
#include "ui_alarm_end_window.h"
#include <QtMultimedia/QSound>
#include <QMediaPlayer>
Alarm_end_window::Alarm_end_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alarm_end_window)
{
    ui->setupUi(this);
    QMediaPlayer* music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/rooster.mp3"));
    music->play();

}

Alarm_end_window::~Alarm_end_window()
{
    delete ui;
}

void Alarm_end_window::on_pushButton_clicked()
{
    this->~Alarm_end_window();
}
