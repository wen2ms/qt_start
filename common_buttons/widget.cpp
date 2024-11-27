#include "widget.h"

#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    
    ui->checkbox_checkable->setChecked(true);
    
    connect(ui->pushbutton_quit, &QPushButton::clicked, this, &QWidget::close);
    
    connect(ui->enabel_button, &QRadioButton::toggled, this, [=](bool enable_state) {
        qDebug() << "Enable state:" << enable_state;
    });
}

Widget::~Widget() {
    delete ui;
}
