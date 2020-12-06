#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent,QWidget* another_parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    parent2 = another_parent;
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_toolButton_2_clicked()
{
    if(!parent2)
    parentWidget()->show();



    this->~Settings();
}

void Settings::on_toolButton_clicked()
{
    if(!parent2)
        parentWidget()->parentWidget()->show();
    else
    {
        parent2->parentWidget()->show();
    }
    this->~Settings();
}
