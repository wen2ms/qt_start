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
};

#endif  // PLAY_SCENE_H
