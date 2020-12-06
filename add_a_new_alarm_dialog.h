#ifndef ADD_A_NEW_ALARM_DIALOG_H
#define ADD_A_NEW_ALARM_DIALOG_H

#include <QDialog>

namespace Ui {
class Add_a_new_alarm_dialog;
}

class Add_a_new_alarm_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Add_a_new_alarm_dialog(QWidget *parent = nullptr);
    ~Add_a_new_alarm_dialog();

private:
    Ui::Add_a_new_alarm_dialog *ui;
};

#endif // ADD_A_NEW_ALARM_DIALOG_H
