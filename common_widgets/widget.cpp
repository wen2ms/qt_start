#include "widget.h"

#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    
    ui->stackedWidget->setCurrentIndex(2);
    
    connect(ui->scroll_area_btn, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    
    connect(ui->tool_box_btn, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    
    connect(ui->tab_widget_btn, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });
    
    QMovie* movie = new QMovie(":/images/meteor-rain.gif");
    
    ui->movie_label->setMovie(movie);
    movie->start();
}

Widget::~Widget() {
    delete ui;
}
