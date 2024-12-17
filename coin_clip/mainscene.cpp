#include "mainscene.h"

#include <QIcon>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QSoundEffect>

#include "./ui_mainscene.h"
#include "mypush_button.h"

MainScene::MainScene(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainScene), select_level_scene_(nullptr) {
    ui->setupUi(this);
    
    this->setWindowTitle("Coin Filp");
    
    this->setFixedSize(350, 600);
    
    MyPushButton* start_button = new MyPushButton(":/resource/MenuSceneStartButton.png");
    start_button->setParent(this);
    start_button->move(this->width() * 0.5 - start_button->width() * 0.5, this->height() * 0.7);
    
    select_level_scene_ = new SelectLevelScene;
    
    QSoundEffect* back_sound = new QSoundEffect(this);
    back_sound->setSource(QUrl::fromLocalFile(":/resource/BackButtonSound.wav"));
    
    connect(select_level_scene_, &SelectLevelScene::press_back, this, [=]() {
        QTimer::singleShot(500, this, [=]() {
            select_level_scene_->hide();
            this->setGeometry(select_level_scene_->geometry());
            this->show();
        });
    });
    
    QSoundEffect* start_sound = new QSoundEffect(this);
    start_sound->setSource(QUrl::fromLocalFile(":/resource/TapButtonSound.wav"));
    
    connect(start_button, &QPushButton::clicked, this, [=]() {
        start_sound->play();
        
        start_button->bounce_out_animation();
        
        start_button->bounce_in_animation();
        
        QTimer::singleShot(400, this, [=]() {
            this->hide();
            select_level_scene_->setGeometry(this->geometry());
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
