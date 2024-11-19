#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QMenuBar* menu_bar = menuBar();
    setMenuBar(menu_bar);
    
    QMenu* file_action = menu_bar->addMenu("File");
    QMenu* edit_action = menu_bar->addMenu("Edit");
    
    file_action->addAction("New Project...");
    file_action->addSeparator();
    file_action->addAction("New File...");
    
    QToolBar* tool_bar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, tool_bar);
    
    tool_bar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    tool_bar->setFloatable(false);
    
    QPushButton* edit_button = new QPushButton("Edit", this);
    tool_bar->addWidget(edit_button);
    
    QStatusBar* status_bar = statusBar();
    setStatusBar(status_bar);
    
    QLabel* status_label = new QLabel("Issues", this);
    status_bar->addPermanentWidget(status_label);
    
    QDockWidget* dock_widget = new QDockWidget("Projects", this);
    addDockWidget(Qt::TopDockWidgetArea, dock_widget);
    
    QTextEdit* text_edit = new QTextEdit(this);
    setCentralWidget(text_edit);
    
    this->resize(600, 400);
    this->setWindowTitle("Custom MainWindow");
}

MainWindow::~MainWindow() {}
