#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qdebug.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "tut";
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_toolButton_2_clicked()
{
    hide();
    alarm = new AlarmClock(this);
    alarm->setWindowFlags( Qt::Window );
    alarm->setAttribute( Qt::WA_DeleteOnClose );
    alarm->show();
}

void MainWindow::on_toolButton_3_clicked()
{
    hide();
    alarm = new AlarmClock(this);
    alarm->setWindowFlags( Qt::Window );
    alarm->setAttribute( Qt::WA_DeleteOnClose );
    alarm->show();
    alarm->setVisible(false);
    setting = new Settings(this,alarm);
    setting->setWindowFlags( Qt::Window );
    setting->setAttribute( Qt::WA_DeleteOnClose );
    setting->show();
}
