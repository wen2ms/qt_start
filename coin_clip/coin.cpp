#include "coin.h"

#include <QPixmap>
#include <QDebug>

Coin::Coin(const QString& coin_image, QWidget* parent)
    : QPushButton{parent}, timer_on_(new QTimer(this)), timer_off_(new QTimer(this)) {
    load(coin_image);
    
    connect(timer_on_, &QTimer::timeout, this, [=]() {
        QString flipping_image = QString(":/resource/Coin000%1.png").arg(flipping_min_++);
        this->load(flipping_image);
        
        if (this->flipping_min_ > this->flipping_max_) {
            this->flipping_min_ = 1;
            timer_on_->stop();
        }
    });
    
    connect(timer_off_, &QTimer::timeout, this, [=]() {
        QString flipping_image = QString(":/resource/Coin000%8.png").arg(flipping_max_--);
        this->load(flipping_image);
        
        if (this->flipping_max_ < this->flipping_min_) {
            this->flipping_max_ = 8;
            timer_off_->stop();
        }
    });
}

void Coin::load(const QString& filename) {
    QPixmap icon_pixmap;
    
    if (!icon_pixmap.load(filename)) {
        qDebug() << "Could not open " << filename;
        return;
    }
    
    this->setFixedSize(icon_pixmap.size());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(icon_pixmap);
    this->setIconSize(this->size());
}

void Coin::flip() {
    if (flipped_) {
        flipped_ = false;
        timer_on_->start(30);
        
    } else {
        flipped_ = true;
        timer_off_->start(30);   
    }
}
