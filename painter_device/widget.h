#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>

#include "painter_device_config.h"

class Widget : public QWidget {
    Q_OBJECT

  public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    
    void paintEvent(QPaintEvent* event) override;
    
  private:
    const QString kPaintingDir = QString::fromStdString(PAINTER_DEVICE_PAINTINGS_DIR);
};
#endif  // WIDGET_H
