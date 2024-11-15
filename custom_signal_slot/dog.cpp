#include "dog.h"

#include <QDebug>

Dog::Dog(QObject *parent) : QObject{parent} {}

void Dog::stick_out_tough(void) {
    qDebug() << "I am hungry";
}

void Dog::stick_out_tough(QString meat_color) {
    qDebug() << "I want to eat" << meat_color.toUtf8().data() << "meat";
}
