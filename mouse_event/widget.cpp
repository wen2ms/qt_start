#include "widget.h"

#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    
    ui->label->installEventFilter(this);
}

Widget::~Widget() {
    delete ui;
}

bool Widget::eventFilter(QObject *obj, QEvent *ev) {
    if (obj == ui->label && ev->type() == QEvent::MouseButtonPress) {
        qDebug() << "Event filter is running";
        return true;
    } else {
        return QWidget::eventFilter(obj, ev);
    }
}
