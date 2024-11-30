#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QEnterEvent>
#include <QEvent>
#include <QDebug>

class CustomLabel : public QLabel {
    Q_OBJECT
  public:
    explicit CustomLabel(QWidget *parent = nullptr);
    
  protected:
    void enterEvent(QEnterEvent* event) override;
    
    void leaveEvent(QEvent* event) override;
    
    void mouseMoveEvent(QMouseEvent* event) override;
    
    void mousePressEvent(QMouseEvent* event) override;
    
    void mouseReleaseEvent(QMouseEvent* event) override;
};

#endif  // CUSTOMLABEL_H
