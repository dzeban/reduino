#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <QFileDialog>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
 //   void resizeEvent(QResizeEvent *e);

private:
    Ui::MainWindow *ui;

private slots:
    void on_actionOpenIcon_triggered();
    void on_action_exit_triggered();
};

#endif // MAINWINDOW_H
