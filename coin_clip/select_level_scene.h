#ifndef SELECT_LEVEL_SCENE_H
#define SELECT_LEVEL_SCENE_H

#include <QMainWindow>
#include "play_scene.h"

class SelectLevelScene : public QMainWindow {
    Q_OBJECT
  public:

    explicit SelectLevelScene(QWidget *parent = nullptr);
    
    void paintEvent(QPaintEvent* event) override;
    
  signals:
    void press_back();
    
  private:
    PlayScene* play_scene_;
};

#endif  // SELECT_LEVEL_SCENE_H
