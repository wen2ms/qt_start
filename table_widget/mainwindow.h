#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QFile>
#include <QTextStream>
#include <QList>

#include "tvshow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    void read_tvshows();

  private:
    Ui::MainWindow *ui;
    
    QList<TVShow> tvshows_list_;
};
#endif  // MAINWINDOW_H
