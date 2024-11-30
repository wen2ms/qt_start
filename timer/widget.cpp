#include "widget.h"

#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    
    ui->timer_1s->setText("1s Timer: 0");
    ui->timer_2s->setText("2s Timer: 0");
    ui->timer_half_sec->setText("0.5s Timer: 0");
    
    timer_1s_id_ = startTimer(1000);
    timer_2s_id_ = startTimer(2000);
    
    QTimer* timer_halfsec = new QTimer(this);
    
    connect(timer_halfsec, &QTimer::timeout, this, [=]() {
        static int half_sec_time = 1;
        
        ui->timer_half_sec->setText("0.5s Timer: " + QString::number(half_sec_time++));
    });
    
    connect(ui->stop_button, &QPushButton::clicked, this, [=]() {
        static bool timer_state = true;
        if (timer_state) {
            timer_halfsec->stop();
            killTimer(timer_1s_id_);
            killTimer(timer_2s_id_);
            
            ui->stop_button->setText("Resume");
            timer_state = false;
        } else {
            timer_halfsec->start();
            timer_1s_id_ = startTimer(1000);
            timer_2s_id_ = startTimer(2000);
            
            ui->stop_button->setText("Stop");
            timer_state = true;
        }
    });
    
    timer_halfsec->start(500);
}

Widget::~Widget() {
    delete ui;
}

void Widget::timerEvent(QTimerEvent* e) {        
    if (e->timerId() == timer_1s_id_) {
        static int timer1 = 1;
        ui->timer_1s->setText("1s Timer: " + QString::number(timer1++));
    } else if (e->timerId() == timer_2s_id_) {
        static int timer2 = 1;
        ui->timer_2s->setText("2s Timer: " + QString::number(timer2++));
    }        
}
