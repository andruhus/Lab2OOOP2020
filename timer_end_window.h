#ifndef TIMER_END_WINDOW_H
#define TIMER_END_WINDOW_H

#include <QDialog>

namespace Ui {
class Timer_end_window;
}

class Timer_end_window : public QDialog
{
    Q_OBJECT

public:
    explicit Timer_end_window(QWidget *parent = nullptr);
    ~Timer_end_window();

private:
    Ui::Timer_end_window *ui;
};

#endif // TIMER_END_WINDOW_H
