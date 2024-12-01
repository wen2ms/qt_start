#include "widget.h"

#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget), zoom_factor_(1.0) {
    ui->setupUi(this);
}

Widget::~Widget() {
    delete ui;
}

void Widget::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    
    painter.save();
    
    QPen pen(Qt::magenta);
    
    pen.setWidth(2);
    pen.setStyle(Qt::DotLine);
    
    painter.setPen(pen);
    
    QBrush brush(QColorConstants::Cyan);
    
    brush.setStyle(Qt::Dense6Pattern);
    
    painter.setBrush(brush);
    
    QPointF polygon_points[3] = {QPointF(100, 100), QPointF(200, 200), QPointF(300, 100)};
                                
    painter.drawPolygon(polygon_points, 3);
    
    painter.drawRect(QRect(100, 100, 200, 100));
    
    painter.drawText(QPointF(150, 120), "I Love You Baby");
    
    painter.drawEllipse(400, 400, 100, 50);
    
    painter.translate(200, 0);
    
    painter.drawEllipse(400, 400, 100, 50);
    
    painter.restore();
    
    painter.drawEllipse(300, 300, 100, 50);
    
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(500, 300, 100, 50);
}
