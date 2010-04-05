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
    void saveCurrentTab();

protected:
    void changeEvent(QEvent *e);
 //   void resizeEvent(QResizeEvent *e);

private:
    Ui::MainWindow *ui;

private slots:
    void on_actionSaveIcon_triggered();
    void on_tabWidget_tabCloseRequested(int index);
    void on_actionOpenIcon_triggered();
    void on_actionExit_triggered();
    void on_modificationChanged();
};

#endif // MAINWINDOW_H
