#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), dog_(new Dog(this)), master_(new Master(this)) {
    connect(master_, &Master::ring_the_bell, dog_, &Dog::stick_out_tough);
    
    time_6_oclock();
    
    setWindowTitle("Custom signal and slot");
}

Widget::~Widget() {}

void Widget::time_6_oclock() {
    emit master_->ring_the_bell();
}
