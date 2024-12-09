#include "mainscene.h"

#include <QIcon>
#include <QPainter>
#include <QDebug>
#include <QTimer>

#include "./ui_mainscene.h"
#include "mypush_button.h"

MainScene::MainScene(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainScene), kMainsceneSize(350, 600), select_level_scene_(nullptr) {
    ui->setupUi(this);
    
    this->setWindowTitle("Coin Filp");
    
    this->setFixedSize(kMainsceneSize);
    
    MyPushButton* start_button = new MyPushButton(":/resource/MenuSceneStartButton.png");
    start_button->setParent(this);
    start_button->move(this->width() * 0.5 - start_button->width() * 0.5, this->height() * 0.7);
    
    select_level_scene_ = new SelectLevelScene(this->size());
    
    connect(select_level_scene_, &SelectLevelScene::press_back, this, [=]() {
        QTimer::singleShot(500, this, [=]() {
            select_level_scene_->hide();
            this->show();
        });
    });
    
    connect(start_button, &QPushButton::clicked, this, [=]() {
        start_button->bounce_out_animation();
        
        start_button->bounce_in_animation();
        
        QTimer::singleShot(400, this, [=]() {
            this->hide();
            select_level_scene_->show();
        });

    });
}

MainScene::~MainScene() {
    delete ui;
    
    delete select_level_scene_;
}

void MainScene::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    
    QPixmap mainscene_background(":/resource/MenuSceneBg.png");
    
    painter.drawPixmap(0, 0, this->width(), this->height(), mainscene_background);
}
