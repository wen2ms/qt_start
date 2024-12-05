#include "mypush_button.h"

#include <QDebug>
#include <QPixmap>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton{parent} {}

MyPushButton::MyPushButton(QString normal_image, QString pressed_image)
    : kNormalImage(normal_image), kPressedImage(pressed_image) {
    QPixmap button_pixmap;
    
    if (!button_pixmap.load(kNormalImage)) {
        qDebug() << "Could not open " << kNormalImage << " for button";
    } else {
        this->setFixedSize(button_pixmap.size());
        
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(button_pixmap);
        this->setIconSize(this->size());
    }
    
}
