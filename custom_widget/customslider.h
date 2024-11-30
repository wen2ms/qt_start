#ifndef CUSTOMSLIDER_H
#define CUSTOMSLIDER_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class CustomSlider;
}

class CustomSlider : public QWidget {
    Q_OBJECT

  public:
    explicit CustomSlider(QWidget *parent = nullptr);
    ~CustomSlider();
    
  public slots:
    void set_value(int value);
    
    void get_value() const;

  private:
    Ui::CustomSlider *ui;
};

#endif  // CUSTOMSLIDER_H
