#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    
    ui->pushButton->setIcon(QIcon(":/images/home.png"));
    
    QLabel* status_label = new QLabel(this);
    status_label->setText("status");
    
    ui->statusBar->addPermanentWidget(status_label);
}

MainWindow::~MainWindow() {
    delete ui;
}
