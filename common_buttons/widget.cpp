#include "widget.h"

#include "./ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    
    ui->checkbox_checkable->setChecked(true);
    
    connect(ui->pushbutton_quit, &QPushButton::clicked, this, &QWidget::close);
    
    connect(ui->enabel_button, &QRadioButton::toggled, this, [=](bool enable_state) {
        qDebug() << "Enable state:" << enable_state;
    });
    
    QListWidgetItem* list_item = new QListWidgetItem("First Line", ui->listWidget);
    list_item->setTextAlignment(Qt::AlignHCenter);
    
    ui->listWidget->addItem(list_item);
}

Widget::~Widget() {
    delete ui;
}
