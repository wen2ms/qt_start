#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTimerEvent>

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
    
    void timerEvent(QTimerEvent* e) override;

  private:
    Ui::Widget *ui;
    
    int timer_1s_id_;
    int timer_2s_id_;
};
#endif  // WIDGET_H
