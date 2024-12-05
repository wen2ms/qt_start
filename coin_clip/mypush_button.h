#ifndef MYPUSH_BUTTON_H
#define MYPUSH_BUTTON_H

#include <QWidget>
#include <QPushButton>

class MyPushButton : public QPushButton {
    Q_OBJECT
  public:
    explicit MyPushButton(QWidget *parent = nullptr);
    
    MyPushButton(QString normal_image, QString pressed_image = "");
    
  private:
    const QString kNormalImage, kPressedImage;
};

#endif  // MYPUSH_BUTTON_H
