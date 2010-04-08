#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTabWidget>
#include <QFileDialog>

#include "codeditor.h"

namespace Ui {
    class MainWindow;
}



class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void saveCurrentTab();
    QTabWidget* getEditorTabWidget(){ return this->ui->tabW; }
    QList <CodeEditor *> getActiveEditorsList();
    CodeEditor* getCurrentEditor();

protected:
    void changeEvent(QEvent *e);
 //   void resizeEvent(QResizeEvent *e);

private:
    Ui::MainWindow *ui;

private slots:
    void on_actionLine_wrap_triggered(bool checked);
    void on_actionSaveIcon_triggered();
    void on_tabWidget_tabCloseRequested(int index);
    void on_actionOpenIcon_triggered();
    void on_actionExit_triggered();
    void on_modificationChanged();
};

#endif // MAINWINDOW_H
