#ifndef PLAY_SCENE_H
#define PLAY_SCENE_H

#include <QMainWindow>

class PlayScene : public QMainWindow {
    Q_OBJECT
  public:
    explicit PlayScene(int level, QWidget *parent = nullptr);
    
    void paintEvent(QPaintEvent* event) override;
    
  signals:
    void press_back();
    
  private:
    int level_;
    
    int level_setting_[4][4];
};

#endif  // PLAY_SCENE_H
