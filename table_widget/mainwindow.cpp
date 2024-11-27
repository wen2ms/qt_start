#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    
    read_tvshows();
    
    ui->tableWidget->setColumnCount(3);
    
    QList<QString> titles_list;
    QList<QString> rating_list;
    QList<QString> release_year_list;
    for (QList<TVShow>::iterator it = tvshows_list_.begin(); it != tvshows_list_.end(); it++) {
        titles_list.push_back(it->title_);
        rating_list.push_back(QString::number(it->rating_));
        release_year_list.push_back(QString::number(it->release_year_));
    }
    
    ui->tableWidget->setHorizontalHeaderLabels({"Title", "Rating", "Release Year"});
    
    ui->tableWidget->setRowCount(tvshows_list_.size());
    for (int i = 0; i < tvshows_list_.size(); i++) {
        int cols = 0;
        
        ui->tableWidget->setItem(i, cols++, new QTableWidgetItem(titles_list[i]));
        ui->tableWidget->setItem(i, cols++, new QTableWidgetItem(rating_list[i]));
        ui->tableWidget->setItem(i, cols++, new QTableWidgetItem(release_year_list[i]));
    }
    
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::read_tvshows() {
    const QString tvshows_info = ":/tvshows.txt";
    
    QFile in_file(tvshows_info);
    
    if (!in_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Can not open the file for reading";
        return;
    }
    
    QTextStream stringstream(&in_file);
    
    while (!stringstream.atEnd()) {
        QString line = stringstream.readLine();
        
        QStringList attributes_list = line.split(',');
        
        QString title = attributes_list[0];
        float rating = attributes_list[1].toFloat();
        int release_year = attributes_list[2].toInt();
        
        tvshows_list_.push_back(TVShow(title, rating, release_year));
    }
    
    in_file.close();
}
