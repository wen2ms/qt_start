#ifndef SELECT_LEVEL_SCENE_H
#define SELECT_LEVEL_SCENE_H

#include <QMainWindow>

class SelectLevelScene : public QMainWindow {
    Q_OBJECT
  public:
    explicit SelectLevelScene(QWidget *parent = nullptr) {};
    
    explicit SelectLevelScene(const QSize& size, QWidget *parent = nullptr);
    
    void paintEvent(QPaintEvent* event) override;
    
  signals:
    void press_back();
    
  private:
    const QSize kSelectLevelSceneSize;
};

#endif  // SELECT_LEVEL_SCENE_H
