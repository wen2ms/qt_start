#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget* central_widget = new QWidget(this);
    
    this->setCentralWidget(central_widget);
    
    QWidget* user_information = new QWidget(central_widget);
    
    QLabel* username_label = new QLabel("Username", user_information);
    QLabel* password_label = new QLabel("Password", user_information);
    
    QLineEdit* username_edit = new QLineEdit(user_information);
    QLineEdit* password_edit = new QLineEdit(user_information);
    
    QSpacerItem* left_spacer_user_info = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Fixed);
    QSpacerItem* right_spacer_user_info = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Fixed);
    
    QGridLayout* grid_layout = new QGridLayout(user_information);
    
    grid_layout->addItem(left_spacer_user_info, 0, 0);
    grid_layout->addWidget(username_label, 0, 1);
    grid_layout->addWidget(username_edit, 0, 2);
    grid_layout->addItem(right_spacer_user_info, 0, 3);
    
    grid_layout->addWidget(password_label, 1, 1);
    grid_layout->addWidget(password_edit, 1, 2);
    
    user_information->setLayout(grid_layout);
    
    QWidget* login = new QWidget(central_widget);
    
    QPushButton* login_btn = new QPushButton("Login", login);
    QPushButton* forget_btn = new QPushButton("Forget password", login);
    
    QSpacerItem* left_spacer_login = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Fixed);
    QSpacerItem* right_spacer_login = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Fixed);
    
    QHBoxLayout* horizontal_layout = new QHBoxLayout(login);
    horizontal_layout->addItem(left_spacer_login);
    horizontal_layout->addWidget(login_btn);
    horizontal_layout->addWidget(forget_btn);
    horizontal_layout->addItem(right_spacer_login);
    
    login->setLayout(horizontal_layout);
    
    QVBoxLayout* vertical_layout = new QVBoxLayout(central_widget);
    vertical_layout->addWidget(user_information);
    vertical_layout->addWidget(login);
    
    central_widget->setLayout(vertical_layout);
    
    this->resize(600, 400);
    this->setWindowTitle("Login");
}

MainWindow::~MainWindow() {}
