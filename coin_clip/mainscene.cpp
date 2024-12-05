#include "mainscene.h"

#include <QIcon>
#include <QPainter>

#include "./ui_mainscene.h"
#include "mypush_button.h"

MainScene::MainScene(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainScene), kMainsceneSize(350, 600) {
    ui->setupUi(this);
    
    this->setWindowTitle("Coin Filp");
    
    this->setFixedSize(kMainsceneSize);
    
    MyPushButton* start_button = new MyPushButton(":/resource/MenuSceneStartButton.png");
    start_button->setParent(this);
    start_button->move(this->width() * 0.5 - start_button->width() * 0.5, this->height() * 0.7);
}

MainScene::~MainScene() {
    delete ui;
}

void MainScene::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    
    QPixmap mainscene_background(":/resource/MenuSceneBg.png");
    
    painter.drawPixmap(0, 0, this->width(), this->height(), mainscene_background);
}
