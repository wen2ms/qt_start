#include "widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent) : QWidget(parent) {
    QPushButton* starting_btn = new QPushButton;
    
    starting_btn->setParent(this);
    
    starting_btn->setText("Starting button");
    
    QPushButton* exit_btn = new QPushButton("Exit button", this);
    
    exit_btn->move(200, 200);
    
    connect(exit_btn, &QPushButton::clicked, this, &Widget::close);
    
    resize(600, 400);
    
    setWindowTitle("Widget");
}

Widget::~Widget() {}
