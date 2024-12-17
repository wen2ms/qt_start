#ifndef PLAY_SCENE_H
#define PLAY_SCENE_H

#include <QMainWindow>
#include <QLabel>

#include "coin.h"

class PlayScene : public QMainWindow {
    Q_OBJECT
  public:
    explicit PlayScene(int level, QWidget *parent = nullptr);
    
    void paintEvent(QPaintEvent* event) override;
    
    void flip_around(int x, int y);
    
    void is_win();
    
  signals:
    void press_back();
    
  private:
    int level_;
    
    int level_setting_[4][4];
    
    Coin* coins_map_[4][4];
    
    QLabel* win_label_;
};

#endif  // PLAY_SCENE_H
