#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

  public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    
  protected:
    void paintEvent(QPaintEvent*) override;

  private:
    Ui::Widget *ui;
    
    int pixmap_x_offset_;
};
#endif  // WIDGET_H
