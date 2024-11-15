#include "widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent) : QWidget(parent) {
    QPushButton* starting_btn = new QPushButton;
    
    starting_btn->setParent(this);
    
    starting_btn->setText("Starting button");
    
    QPushButton* end_btn = new QPushButton("End button", this);
    
    end_btn->move(200, 200);
    
    resize(600, 400);
    
    setWindowTitle("Widget");
}

Widget::~Widget() {}
