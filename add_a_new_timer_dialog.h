#ifndef ADD_A_NEW_TIMER_DIALOG_H
#define ADD_A_NEW_TIMER_DIALOG_H

#include <QDialog>

namespace Ui {
class Add_a_new_timer_dialog;
}

class Add_a_new_timer_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Add_a_new_timer_dialog(QWidget *parent = nullptr);
    ~Add_a_new_timer_dialog();

private:
    Ui::Add_a_new_timer_dialog *ui;
};

#endif // ADD_A_NEW_TIMER_DIALOG_H
