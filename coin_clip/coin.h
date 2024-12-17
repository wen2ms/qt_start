#ifndef COIN_H
#define COIN_H

#include <QObject>
#include <QPushButton>
#include <QTimer>

class Coin : public QPushButton {
    Q_OBJECT
  public:
    explicit Coin(const QString& coin_image, QWidget *parent = nullptr);
    
    void load(const QString& filename);
    
    void mousePressEvent(QMouseEvent* event) override;
    
    int index_x_;
    int index_y_;
    bool flipped_;
    
    static bool is_win_;
    static bool is_click_;
    
  public slots:
    void flip();
    
  private:
    QTimer* timer_on_;
    QTimer* timer_off_;
    
    int flipping_max_ = 8;
    int flipping_min_ = 1;
    
    bool is_flipping;
};

#endif  // COIN_H
