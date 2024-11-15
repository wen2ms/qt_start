#include "dog.h"

#include <QDebug>

Dog::Dog(QObject *parent) : QObject{parent} {}

void Dog::stick_out_tough(void) {
    qDebug() << "I am hungry";
}
