#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet("QDockWidget {margin:10 10 10 10;} QDockWidget::title {text-align: left; /* align the text to the left */background: darkgray; padding-left: 5px; } ");
    MainWindow w;
    w.show();
    return a.exec();
}
