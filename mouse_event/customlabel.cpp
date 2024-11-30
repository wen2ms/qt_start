#include "customlabel.h"

CustomLabel::CustomLabel(QWidget *parent) : QLabel{parent} {}

bool CustomLabel::event(QEvent* e) {
    if (e->type() == QEvent::MouseButtonPress) {
        qDebug() << "Interception isn't recommended";
        return true;
    } else {
        return QLabel::event(e);
    }
}

void CustomLabel::enterEvent(QEnterEvent* event) {
    qDebug() << "Mouse enter...";
}

void CustomLabel::leaveEvent(QEvent* event) {
    qDebug() << "Mouse leave...";
}

void CustomLabel::mouseMoveEvent(QMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton) {
        qDebug() << "Mouse moving...";   
    }
}

void CustomLabel::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        QString str = QString("Mouse press: pos(%1, %2), global pos(%3, %4)")
                          .arg(event->pos().x())
                          .arg(event->pos().y())
                          .arg(event->globalPosition().x())
                          .arg(event->globalPosition().y());
        qDebug() << str;   
    }
}

void CustomLabel::mouseReleaseEvent(QMouseEvent* event) {
    qDebug() << "Mouse release...";
}
