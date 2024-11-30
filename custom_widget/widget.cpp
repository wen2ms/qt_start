#include "widget.h"

#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    
    connect(ui->get_value_button, &QPushButton::clicked, ui->custom_slider, &CustomSlider::get_value);
    
    connect(ui->set_value_button, &QPushButton::clicked, ui->custom_slider, [=]() {
        ui->custom_slider->set_value(50);
    });
}

Widget::~Widget() {
    delete ui;
}
