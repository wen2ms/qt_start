#ifndef MYPUSH_BUTTON_H
#define MYPUSH_BUTTON_H

#include <QWidget>
#include <QPushButton>

class MyPushButton : public QPushButton {
    Q_OBJECT
  public:
    explicit MyPushButton(QWidget *parent = nullptr);
    
    MyPushButton(QString normal_image, QString pressed_image = "");
    
    void load_icon(const QString& filename);
    
    void mousePressEvent(QMouseEvent* event) override;
    
    void mouseReleaseEvent(QMouseEvent* event) override;
    
  public slots:
    void bounce_out_animation();
    void bounce_in_animation();
    
  private:
    const QString kNormalImage, kPressedImage;
};

#endif  // MYPUSH_BUTTON_H
