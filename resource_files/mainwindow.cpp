#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    
    ui->pushButton->setIcon(QIcon(":/images/home.png"));
    
    QLabel* status_label = new QLabel(this);
    status_label->setText("status");
    
    ui->statusBar->addPermanentWidget(status_label);
    
    connect(ui->actionNew_Project, &QAction::triggered, this, [=]() {
        QDialog modal_dialog(this);
        
        modal_dialog.setWindowTitle("Modal Dialog");
        
        modal_dialog.resize(200, 100);
        
        modal_dialog.exec(); 
    });
    
    connect(ui->actionNew_File, &QAction::triggered, this, [=]() {
        QDialog* non_modal_dialog = new QDialog(this);
        
        non_modal_dialog->setWindowTitle("Non-modal Dialog");
        
        non_modal_dialog->resize(200, 100);
        
        non_modal_dialog->setAttribute(Qt::WA_DeleteOnClose);
        
        non_modal_dialog->show();
    });
    
    
}

MainWindow::~MainWindow() {
    delete ui;
}
