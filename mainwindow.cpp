#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    system = new SysHidden();
    ComboBoxConfig();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_toolButton_2_clicked()
{
    hide();
    alarm = new AlarmClock(this,system);
    alarm->setWindowFlags( Qt::Window );
    alarm->setAttribute( Qt::WA_DeleteOnClose );
    alarm->show();
}

void MainWindow::on_toolButton_3_clicked()
{
    hide();
    alarm = new AlarmClock(this,system);
    alarm->setWindowFlags( Qt::Window );
    alarm->setAttribute( Qt::WA_DeleteOnClose );
    alarm->show();
    alarm->setVisible(false);
    setting = new Settings(this,alarm,system);
    setting->setWindowFlags( Qt::Window );
    setting->setAttribute( Qt::WA_DeleteOnClose );
    setting->show();
}

void MainWindow::on_addNewTimer_clicked()
{
    dialog = new Add_a_new_timer_dialog(this);
    dialog->show();
}

void MainWindow::ComboBoxConfig()
{
    ui->comboBox->addItem("All");
    ui->comboBox->addItem("Sport only");
    ui->comboBox->addItem("Cookery only");
}
