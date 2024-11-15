#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), dog_(new Dog(this)), master_(new Master(this)) {
    void (Master::* color_ring)(QString) = &Master::ring_the_bell;
    void (Dog::* color_stick)(QString) = &Dog::stick_out_tough;
    
    connect(master_, color_ring, dog_, color_stick);
    
    time_6_oclock("red");
    
    setWindowTitle("Custom signal and slot");
}

Widget::~Widget() {}

void Widget::time_6_oclock() {
    emit master_->ring_the_bell();
}

void Widget::time_6_oclock(QString color) {
    emit master_->ring_the_bell(color);
}
