#include "play_scene.h"

#include <QPainter>
#include <QTimer>
#include <QLabel>

#include "mypush_button.h"

PlayScene::PlayScene(int level, QWidget *parent) : QMainWindow{parent}, level_(level) {
    this->setFixedSize(350, 600);
    
    this->setWindowTitle("Level " + QString::number(level_));
    
    MyPushButton* back_button = new MyPushButton(":/resource/BackButton.png", ":/resource/BackButtonSelected.png");
    
    back_button->move(this->width() - back_button->width(), this->height() * 0.9);
    
    back_button->setParent(this);
    
    connect(back_button, &QPushButton::clicked, this, [=]() {
        emit press_back();
    });
    
    QLabel* level_label = new QLabel(this);
    
    QFont level_label_font;
    level_label_font.setFamily("Times New Roman");
    level_label_font.setPointSize(30);
    
    level_label->setFont(level_label_font);
    level_label->setStyleSheet("QLabel{color:black;}");
    
    level_label->setText(QString("Level: %1").arg(level_));
    
    level_label->setGeometry(0, this->height() * 0.88, this->width() * 0.4, this->height() * 0.1);
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            QLabel* coin_label = new QLabel(this);
            
            QPixmap coin_pixmap(":/resource/BoardNode.png");
            
            coin_label->setPixmap(coin_pixmap);
            
            coin_label->setGeometry(this->width() * 0.5 - coin_pixmap.width() * 4.6 * 0.5 + coin_pixmap.width() * i * 1.2,
                                    this->height() * 0.3 + coin_pixmap.height() * j * 1.2, coin_pixmap.width(), coin_pixmap.height());
        }
    }
}

void PlayScene::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    
    QPixmap scene_background(":/resource/PlayLevelSceneBg.png");
    
    painter.drawPixmap(0, 0, this->width(), this->height(), scene_background);
    
    scene_background.load(":/resource/Title.png");
    
    scene_background = scene_background.scaled(scene_background.size() * 0.7);
    
    painter.drawPixmap(this->width() * 0.1, scene_background.height() * 0.1,
                       scene_background.width(), scene_background.height(), scene_background);
}
