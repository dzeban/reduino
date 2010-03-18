#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSyntaxHighlighter>

namespace Ui {
    class MainWindow;
}
class MyHi : public QSyntaxHighlighter
{
Q_OBJECT
    public:
    MyHi(QTextEdit *parent = 0);

    protected:
        void highlightBlock(const QString &text);
};

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
};

#endif // MAINWINDOW_H
