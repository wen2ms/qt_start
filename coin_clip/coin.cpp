#include "coin.h"

#include <QPixmap>
#include <QDebug>

Coin::Coin(const QString& coin_image, QWidget *parent) : QPushButton{parent} {
    QPixmap coin_pixmap;
    
    if (!coin_pixmap.load(coin_image)) {
        qDebug() << "Could not open " << coin_image << " for coin";
    } else {
        this->setFixedSize(coin_pixmap.size());
        
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(coin_pixmap);
        this->setIconSize(this->size());
    }   
}
