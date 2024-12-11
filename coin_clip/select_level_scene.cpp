#include "select_level_scene.h"

#include <QPainter>
#include <QLabel>

#include "mypush_button.h"

SelectLevelScene::SelectLevelScene(const QSize& size, QWidget *parent) : QMainWindow{parent}, kSelectLevelSceneSize(size) {
    this->setFixedSize(kSelectLevelSceneSize);
    
    this->setWindowTitle("Select Level");
    
    MyPushButton* back_button = new MyPushButton(":/resource/BackButton.png", ":/resource/BackButtonSelected.png");
    
    back_button->setParent(this);
    
    back_button->move(this->width() - back_button->width(), this->height() * 0.9);
    
    connect(back_button, &QPushButton::clicked, this, [=]() {
        emit this->press_back();
    });
    
    for (int i = 0; i < 20; ++i) {
        MyPushButton* select_button = new MyPushButton(":/resource/LevelIcon.png");
        
        select_button->setParent(this);

        select_button->move(this->width() * 0.5 - select_button->width() * 4.6 * 0.5 + select_button->width() * (i % 4) * 1.2,
                            this->height() * 0.2 + select_button->height() * (i / 4) * 1.3);
        
        connect(select_button, &QPushButton::clicked, this, [=]() {
            qDebug() << QString("%1 Level clicked").arg(i + 1);
        });
        
        QLabel* level_label = new QLabel(QString::number(i + 1), this);
        
        level_label->setFixedSize(select_button->size());
        
        level_label->move(this->width() * 0.5 - select_button->width() * 4.6 * 0.5 + select_button->width() * (i % 4) * 1.2,
                           this->height() * 0.2 + select_button->height() * (i / 4) * 1.3);
        
        level_label->setAlignment(Qt::AlignCenter);
        
        level_label->setStyleSheet("QLabel{color:black;}");
        
        level_label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void SelectLevelScene::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    
    QPixmap select_scene_background(":/resource/OtherSceneBg.png");
    
    painter.drawPixmap(0, 0, this->width(), this->height(), select_scene_background);
    
    select_scene_background.load(":/resource/Title.png");

    painter.drawPixmap(this->width() * 0.5 - select_scene_background.width() * 0.5, select_scene_background.height() * 0.1,
                       select_scene_background.width(), select_scene_background.height(), select_scene_background);
}
