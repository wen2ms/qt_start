#include "widget.h"

#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent) : QWidget(parent) {
    this->resize(800, 600);
    
    QPixmap input_pix(300, 300);
    
    input_pix.fill(QColorConstants::White);
    
    QPainter pix_painter(&input_pix);
    pix_painter.setPen(QPen(QColorConstants::Green));
    
    pix_painter.setRenderHint(QPainter::Antialiasing);
    pix_painter.drawEllipse(QPoint(150, 150), 50, 50);
    
    input_pix.save(kPaintingDir + "/circle.png");

    QImage input_image(300, 300, QImage::Format_RGB32);
    input_image.fill(QColorConstants::White);
    
    QPainter image_painter(&input_image);
    
    image_painter.setPen(QPen(QColorConstants::Gray));
    
    image_painter.drawRect(QRect(QPoint(100, 100), QPoint(200, 200)));
    
    input_image.save(kPaintingDir + "/rect.png");
    
    QPicture input_picture;
    QPainter picture_painter;
    
    picture_painter.begin(&input_picture);
    
    picture_painter.setPen(QPen(QColorConstants::Yellow));
    
    picture_painter.drawEllipse(QPoint(200, 200), 100, 100);

    picture_painter.end();
    
    input_picture.save(kPaintingDir + "/picture.pic");
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent* event) {
    QImage football_image(":/images/football.png");
    
    QPainter test_painter(this);
    
    for (int i = 0; i < 200; ++i) {
        football_image.setPixel(i, 200, QColorConstants::Red.rgb());
    }
    
    test_painter.drawImage(0, 0, football_image);
    
    QPicture test_picture;
    test_picture.load(kPaintingDir + "/picture.pic");
    
    test_painter.drawPicture(200, 200, test_picture);
}
