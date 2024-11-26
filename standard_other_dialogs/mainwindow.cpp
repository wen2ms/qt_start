#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    
    connect(ui->actionColor, &QAction::triggered, this, [=]() {
        QColor selected_color = QColorDialog::getColor(Qt::white, this, "Color Dialog");
        qDebug() << "R:" << selected_color.red() << "G:" << selected_color.green() << "B:" << selected_color.blue();
    });
    
    connect(ui->actionExplorer, &QAction::triggered, this, [=]() {
        QString selected_filename = QFileDialog::getOpenFileName(this, "Open File...", "./", "(*.cpp)");        
        qDebug() << selected_filename;
    });
    
    connect(ui->actionFont, &QAction::triggered, this, [=]() {
        bool ok;
        QFont selected_font = QFontDialog::getFont(&ok, QFont("Times New Roman", 12), this);
        if (ok) {
            qDebug() << selected_font.family() << "Bold:" << selected_font.bold() << "Italic:" << selected_font.italic();
        }
    });
    
}

MainWindow::~MainWindow() {
    delete ui;
}
