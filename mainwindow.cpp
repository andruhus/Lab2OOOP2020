#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include<QMessageBox>
#include<QTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    system = new SysHidden();
    ComboBoxConfig();
    UpdateList();
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

void MainWindow::UpdateList()
{
    ui->listWidget->clear();
    QTime devider(0,10,0);
    QFile file(timer_db_name);
    if(!file.open(QFile::ReadOnly | QFile::Text))
        QMessageBox::critical(this,"File error","It is something wrong with your file");

    QTextStream in(&file);

    if(filt_state == all)
    {
        while(!in.atEnd())
        {
            QString temp = in.readLine();
            QTime item = QTime::fromString(temp);
            QString to_write = item.toString("hh : mm : ss");
            ui->listWidget->addItem(to_write);
        }
    }
    if(filt_state == sport)
    {
        while(!in.atEnd())
        {
            QString temp = in.readLine();
            QTime item = QTime::fromString(temp);
            if(item >= devider)
                continue;
            QString to_write = item.toString("hh : mm : ss");
            ui->listWidget->addItem(to_write);
        }
    }
    if(filt_state == cookery)
    {
        while(!in.atEnd())
        {
            QString temp = in.readLine();
            QTime item = QTime::fromString(temp);
            if(item < devider)
                continue;
            QString to_write = item.toString("hh : mm : ss");
            ui->listWidget->addItem(to_write);
        }
    }
    file.close();
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "All")
        filt_state = all;
    if(arg1 == "Sport only")
        filt_state = sport;
    if(arg1 == "Cookery only")
        filt_state = cookery;
    UpdateList();
}



void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString line = item->text();
    QString line_h = line.left(2);
    QString line_m = line.mid(5,2);
    QString line_s = line.right(2);
    int h = line_h.toInt();
    int m = line_m.toInt();
    int s = line_s.toInt();
    QTime *temp = new QTime(h,m,s);
    system->Add_working_timer(temp);

    //qDebug << temp;
}
