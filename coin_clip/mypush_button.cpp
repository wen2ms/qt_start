#include "mypush_button.h"

#include <QDebug>
#include <QPixmap>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton{parent} {}

MyPushButton::MyPushButton(QString normal_image, QString pressed_image)
    : kNormalImage(normal_image), kPressedImage(pressed_image) {
    
    load_icon(kNormalImage);
}

void MyPushButton::load_icon(const QString& filename) {
    QPixmap button_pixmap;
    
    if (!button_pixmap.load(filename)) {
        qDebug() << "Could not open " << filename << " for button";
    } else {
        this->setFixedSize(button_pixmap.size());
        
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(button_pixmap);
        this->setIconSize(this->size());
    }   
}

void MyPushButton::mousePressEvent(QMouseEvent* event) {
    if (kPressedImage != "") {
        load_icon(kPressedImage);
    }
    
    return QPushButton::mousePressEvent(event);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent* event) {
    load_icon(kNormalImage);
    
    return QPushButton::mouseReleaseEvent(event);
}

void MyPushButton::bounce_out_animation() {
    QPropertyAnimation* bounce = new QPropertyAnimation(this, "geometry");
    
    bounce->setDuration(200);
    
    bounce->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    
    bounce->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    
    bounce->setEasingCurve(QEasingCurve::OutBounce);
    
    bounce->start();
}

void MyPushButton::bounce_in_animation() {
    QPropertyAnimation* bounce = new QPropertyAnimation(this, "geometry");
    
    bounce->setDuration(200);
    
    bounce->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    
    bounce->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    
    bounce->setEasingCurve(QEasingCurve::OutBounce);
    
    bounce->start();
}

