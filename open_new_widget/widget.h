#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>
#include <QWidget>

#include "newwidget.h"

class Widget : public QWidget {
    Q_OBJECT

  public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    
    void switch_new_widget(QPushButton* open_new_widget);
    
  private:
    bool switch_status_;
    
    NewWidget* new_widget_;
};
#endif  // WIDGET_H
