#include "alarmclock.h"
#include "ui_alarmclock.h"
#include <QTime>
#include <QMessageBox>
AlarmClock::AlarmClock(QWidget *parent,SysHidden *sys) :
    QWidget(parent),
    ui(new Ui::AlarmClock)
{
    ui->setupUi(this);
    system = sys;
    ComboBoxConfig();
    UpdateList();
}

AlarmClock::~AlarmClock()
{
    delete ui;
}



void AlarmClock::on_toolButton_clicked()
{

    parentWidget()->show();
    this->~AlarmClock();
}

void AlarmClock::on_AlarmClock_destroyed()
{

}

void AlarmClock::on_toolButton_3_clicked()
{
    hide();
    setting = new Settings(this,nullptr,system);
    setting->setWindowFlags( Qt::Window );
    setting->setAttribute( Qt::WA_DeleteOnClose );
    setting->show();
}

void AlarmClock::on_pushButton_clicked()
{
    dialog = new Add_a_new_alarm_dialog(this);
    dialog->show();
}

void AlarmClock::ComboBoxConfig()
{
    ui->comboBox->addItem("All");
    ui->comboBox->addItem("AM only");
    ui->comboBox->addItem("PM only");
}

void AlarmClock::UpdateList()
{
    ui->listWidget->clear();
    QTime devider(12,0,0);
    QFile file(alarm_db_name);
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
    if(filt_state == am)
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
    if(filt_state == pm)
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

void AlarmClock::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "All")
        filt_state = all;
    if(arg1 == "AM only")
        filt_state = am;
    if(arg1 == "PM only")
        filt_state = pm;
    UpdateList();
}

void AlarmClock::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString line = item->text();
    QString line_h = line.left(2);
    QString line_m = line.mid(5,2);
    QString line_s = line.right(2);
    int h = line_h.toInt();
    int m = line_m.toInt();
    int s = line_s.toInt();
    QTime *temp = new QTime(h,m,s);
    system->Add_working_alarm(temp);
    QMessageBox::information(this,"Switched on","The alarm has been turned on.");
}
