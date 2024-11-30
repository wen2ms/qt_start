#include "customslider.h"

#include "ui_customslider.h"

CustomSlider::CustomSlider(QWidget *parent) : QWidget(parent), ui(new Ui::CustomSlider) {
    ui->setupUi(this);
    
    connect(ui->spinBox, &QSpinBox::valueChanged, ui->horizontalSlider, &QSlider::setValue);
    
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

CustomSlider::~CustomSlider() {
    delete ui;
}

void CustomSlider::set_value(int value) {
    ui->spinBox->setValue(value);
}

void CustomSlider::get_value() const {
    qDebug() << "The Current Value:" << ui->spinBox->value();
}
