#ifndef MASTER_H
#define MASTER_H

#include <QObject>

class Master : public QObject {
    Q_OBJECT
  public:
    explicit Master(QObject *parent = nullptr);

  signals:
    void ring_the_bell();
    
    void ring_the_bell(QString color);
};

#endif  // MASTER_H
