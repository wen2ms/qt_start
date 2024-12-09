#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QPixmap>

#include "select_level_scene.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainScene;
}
QT_END_NAMESPACE

class MainScene : public QMainWindow {
    Q_OBJECT

  public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    
    void paintEvent(QPaintEvent* event) override;

  private:
    Ui::MainScene *ui;
    
    const QSize kMainsceneSize;
    
    SelectLevelScene* select_level_scene_;
};
#endif  // MAINSCENE_H
