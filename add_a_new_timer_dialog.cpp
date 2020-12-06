#include "add_a_new_timer_dialog.h"
#include "ui_add_a_new_timer_dialog.h"

Add_a_new_timer_dialog::Add_a_new_timer_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_a_new_timer_dialog)
{
    ui->setupUi(this);
}

Add_a_new_timer_dialog::~Add_a_new_timer_dialog()
{
    delete ui;
}
