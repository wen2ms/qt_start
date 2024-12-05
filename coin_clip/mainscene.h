#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QPixmap>

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
};
#endif  // MAINSCENE_H
