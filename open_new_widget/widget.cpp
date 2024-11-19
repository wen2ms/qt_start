#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), switch_status_(false), new_widget_(nullptr) {
    QPushButton* open_new_widget = new QPushButton("Open", this); 
    
    open_new_widget->move(200, 200);
    
    connect(open_new_widget, &QPushButton::clicked, this, [=]() {
        this->switch_new_widget(open_new_widget);
    });
    
    this->resize(600, 400);
    this->setWindowTitle("Open new widget");
}

Widget::~Widget() {
    if (new_widget_) {
        delete new_widget_;
        new_widget_ = nullptr;   
    }
}

void Widget::switch_new_widget(QPushButton* open_new_widget) {
    switch_status_ = !switch_status_;
    
    if (switch_status_) {
        open_new_widget->setText("Close");
        
        new_widget_ = new NewWidget;
        
        new_widget_->setWindowTitle("New widget");
        
        new_widget_->show();
    } else {
        open_new_widget->setText("Open");
        
        new_widget_->close();
        
        delete new_widget_;
        
        new_widget_ = nullptr;
    }
    
}
