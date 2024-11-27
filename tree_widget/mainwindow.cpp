#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    
    ui->treeWidget->setHeaderLabels(QStringList() << "Title" << "Information");
    
    QTreeWidgetItem* documentary = new QTreeWidgetItem(QStringList() << "Documentary");
    QTreeWidgetItem* crime = new QTreeWidgetItem(QStringList() << "Breaking Bad");
    QTreeWidgetItem* action = new QTreeWidgetItem(QStringList() << "Band of Brothers");
    
    QStringList planet_earth_info;
    planet_earth_info << "Planet Earth" << "A documentary series on the wildlife found on Earth";
    QTreeWidgetItem* planet_earth = new QTreeWidgetItem(planet_earth_info);    
        
    QStringList planet_earth2_info;
    planet_earth2_info << "Planet Earth II" << "A new wildlife documentary that shows life in a variety of habitats";
    QTreeWidgetItem* planet_earth2 = new QTreeWidgetItem(planet_earth2_info);    
    
    QStringList breaking_bad_info;
    breaking_bad_info << "Breaking Bad" << "A Chemistry teacher diagnosed with inoperable lung cancer";
    QTreeWidgetItem* breaking_bad = new QTreeWidgetItem(breaking_bad_info);    
    
    QStringList band_of_brothers_info;
    band_of_brothers_info << "Band of Brothers" << "The story of Easy Company of the U.S Army";
    QTreeWidgetItem* band_of_brothers = new QTreeWidgetItem(band_of_brothers_info);
    
    documentary->addChildren({planet_earth, planet_earth2});
    crime->addChild(breaking_bad);
    action->addChild(band_of_brothers);
    
    ui->treeWidget->addTopLevelItems({documentary, crime, action});
}

MainWindow::~MainWindow() {
    delete ui;
}
