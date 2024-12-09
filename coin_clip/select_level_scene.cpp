#include "select_level_scene.h"

#include <QPainter>

#include "mypush_button.h"

SelectLevelScene::SelectLevelScene(QWidget *parent) : QMainWindow{parent}, kSelectLevelSceneSize(350, 600) {
    this->setFixedSize(kSelectLevelSceneSize);
    
    this->setWindowTitle("Select Level");
    
    MyPushButton* back_button = new MyPushButton(":/resource/BackButton.png", ":/resource/BackButtonSelected.png");
    
    back_button->setParent(this);
    
    back_button->move(this->width() - back_button->width(), this->height() * 0.8);
    
    connect(back_button, &QPushButton::clicked, this, [=]() {
        emit this->press_back();
    });
}

void SelectLevelScene::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    
    QPixmap select_scene_background(":/resource/OtherSceneBg.png");
    
    painter.drawPixmap(0, 0, this->width(), this->height(), select_scene_background);
    
    select_scene_background.load(":/resource/Title.png");

    painter.drawPixmap(this->width() * 0.5 - select_scene_background.width() * 0.5, select_scene_background.height() * 0.1,
                       select_scene_background.width(), select_scene_background.height(), select_scene_background);
}
