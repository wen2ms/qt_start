#ifndef DOG_H
#define DOG_H

#include <QObject>

class Dog : public QObject {
    Q_OBJECT
  public:
    explicit Dog(QObject *parent = nullptr);
    
  public slots:
    void stick_out_tough();
    
    void stick_out_tough(QString meat_color);
};

#endif  // DOG_H
