#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "dog.h"
#include "master.h"

class Widget : public QWidget {
    Q_OBJECT

  public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    
    void time_6_oclock();
    
    void time_6_oclock(QString color);
    
  private:
    Dog* dog_;
    Master* master_;
};
#endif  // WIDGET_H
