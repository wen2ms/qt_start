#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QDockWidget>
#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>
#include <QTextEdit>
#include <QToolBar>

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif  // MAINWINDOW_H
