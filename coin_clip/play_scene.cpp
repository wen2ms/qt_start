#include "play_scene.h"

#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QPropertyAnimation>
#include <QSoundEffect>

#include "mypush_button.h"
#include "coin.h"
#include "level_config.h"

PlayScene::PlayScene(int level, QWidget* parent)
    : QMainWindow{parent}, level_(level), win_label_(new QLabel(this)), win_sound_(new QSoundEffect(this)) {
    this->setFixedSize(350, 600);
    
    this->setWindowTitle("Level " + QString::number(level_));
    
    Coin::is_win_ = false;
    Coin::is_click_ = false;
    
    QPixmap passed_background(":/resource/LevelCompletedDialogBg.png");
    win_label_->setPixmap(passed_background);
    win_label_->setGeometry(this->width() * 0.5 - passed_background.width() * 0.5, -passed_background.height(),
                           passed_background.width(), passed_background.height());
    
    MyPushButton* back_button = new MyPushButton(":/resource/BackButton.png", ":/resource/BackButtonSelected.png");
    
    back_button->move(this->width() - back_button->width(), this->height() * 0.9);
    
    back_button->setParent(this);
    
    QSoundEffect* back_sound = new QSoundEffect(this);
    back_sound->setSource(QUrl::fromLocalFile(":/resource/BackButtonSound.wav"));
    
    connect(back_button, &QPushButton::clicked, this, [=]() {
        back_sound->play();
        
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
    
    LevelConfig level_config;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            level_setting_[i][j] = level_config.level_map_[level_][i][j];
        }
    }
    
    QSoundEffect* flip_sound = new QSoundEffect(this);
    flip_sound->setSource(QUrl::fromLocalFile(":/resource/CoinFlipSound.wav"));
    
    win_sound_->setSource(QUrl::fromLocalFile(":/resource/LevelWinSound.wav"));
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            QLabel* coin_background_label = new QLabel(this);
            
            QPixmap coin_background_pixmap(":/resource/BoardNode.png");
            
            coin_background_label->setPixmap(coin_background_pixmap);

            coin_background_label->setGeometry(
                this->width() * 0.5 - coin_background_pixmap.width() * 4.6 * 0.5 + coin_background_pixmap.width() * i * 1.2,
                this->height() * 0.3 + coin_background_pixmap.height() * j * 1.2, coin_background_pixmap.width(),
                coin_background_pixmap.height());

            QString coin_image;
            if (level_setting_[i][j] == 1) {
                coin_image = ":/resource/Coin0001";    
            } else {
                coin_image = ":/resource/Coin0008";    
            }
            
            Coin* coin = new Coin(coin_image, this);

            coin->move(this->width() * 0.5 - coin_background_pixmap.width() * 4.6 * 0.5 +
                           coin_background_pixmap.width() * i * 1.2 + coin_background_pixmap.width() * 0.5 - coin->width() * 0.5,
                       this->height() * 0.3 + coin_background_pixmap.height() * j * 1.2 + coin_background_pixmap.height() * 0.5 -
                           coin->height() * 0.5);
            coin->index_x_ = i;
            coin->index_y_ = j;
            coin->flipped_ = level_setting_[i][j];
            
            coins_map_[i][j] = coin;
            
            connect(coin, &QPushButton::clicked, coin, [=]() {
                flip_sound->play();
                
                coin->flip();
                this->level_setting_[i][j] = !this->level_setting_[i][j];
                
                Coin::is_click_ = true;
                
                QTimer::singleShot(200, this, [=]() {
                    flip_around(coin->index_x_, coin->index_y_);
                    Coin::is_click_ = false;
                    this->is_win();
                });
            });
        }
    }
}

void PlayScene::flip_around(int x, int y) {
    if (x + 1 <= 3) {
        coins_map_[x + 1][y]->flip();
        this->level_setting_[x + 1][y] = !this->level_setting_[x + 1][y];
    }

    if (x - 1 >= 0) {
        coins_map_[x - 1][y]->flip();
        this->level_setting_[x - 1][y] = !this->level_setting_[x - 1][y];
    }

    if (y + 1 <= 3) {
        coins_map_[x][y + 1]->flip();
        this->level_setting_[x][y + 1] = !this->level_setting_[x][y + 1];
    }

    if (y - 1 >= 0) {
        coins_map_[x][y - 1]->flip();
        this->level_setting_[x][y - 1] = !this->level_setting_[x][y - 1];
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

void PlayScene::is_win() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!this->level_setting_[i][j]) {
                return;
            }
        }
    }
    
    Coin::is_win_ = true;
    
    win_sound_->play();
    
    QPropertyAnimation* pass_animation = new QPropertyAnimation(win_label_, "geometry");
    
    pass_animation->setDuration(1000);
    
    pass_animation->setStartValue(QRect(win_label_->x(), win_label_->y(), win_label_->width(), win_label_->height()));
    
    pass_animation->setEndValue(QRect(win_label_->x(), win_label_->y() + 150, win_label_->width(), win_label_->height()));
    
    pass_animation->setEasingCurve(QEasingCurve::OutBounce);
    
    pass_animation->start();
}

