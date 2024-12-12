#ifndef COIN_H
#define COIN_H

#include <QObject>
#include <QPushButton>

class Coin : public QPushButton {
    Q_OBJECT
  public:
    explicit Coin(const QString& coin_image, QWidget *parent = nullptr);
};

#endif  // COIN_H
