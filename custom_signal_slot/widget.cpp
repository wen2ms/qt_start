#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent) : QWidget(parent), dog_(new Dog(this)), master_(new Master(this)) {
    function_pointer_connect();
    
    signals2signals_connect();
    
    lambda_connect();
    
    this->resize(600, 400);
    
    setWindowTitle("Custom signal and slot");
}

Widget::~Widget() {}

void Widget::time_6_oclock() {
    emit master_->ring_the_bell();
}

void Widget::time_6_oclock(QString color) {
    emit master_->ring_the_bell(color);
}

void Widget::function_pointer_connect() {
    void (Master::* color_ring)(QString) = &Master::ring_the_bell;
    void (Dog::* color_stick)(QString) = &Dog::stick_out_tough;
    
    connect(master_, color_ring, dog_, color_stick);
    
    time_6_oclock("red");
}

void Widget::signals2signals_connect() {
    QPushButton* two_steps_ring_btn = new QPushButton("two_steps_ring_btn", this);
    
    void (Widget::* color_time)(void) =  &Widget::time_6_oclock;
    
    void (Master::* void_ring)(void) = &Master::ring_the_bell;
    void (Dog::* void_stick)(void) = &Dog::stick_out_tough;
    
    connect(master_, void_ring, dog_, void_stick);
    
    connect(two_steps_ring_btn, &QPushButton::clicked, this, color_time);
    
    QPushButton* one_tap_ring_btn = new QPushButton("one_tap_ring", this);
    
    one_tap_ring_btn->move(200, 200);
    
    connect(one_tap_ring_btn, &QPushButton::clicked, master_, void_ring);
}

void Widget::lambda_connect() {
    QPushButton* lambda_btn = new QPushButton;
    
    lambda_btn->setParent(this);

    lambda_btn->setText("lambda_button");
    
    lambda_btn->move(400, 200);
    
    connect(lambda_btn, &QPushButton::clicked, this, [=]() {
        this->time_6_oclock("green");
    });
}


