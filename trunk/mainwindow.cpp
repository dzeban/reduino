#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qsyntaxhighlighter.h"
#include "highlighter.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QTextEdit *editor = new QTextEdit;
   // MyHi *hi = new MyHi(ui->mainEdit_2);
    //ui->mainEdit_2->setFontFamily("Arial");
   // qDebug("%s",ui->mainEdit_2->fontFamily());
   // qDebug() << ui->mainEdit_2->fontFamily();
    ui->mainEdit_2->setFontPointSize(50);
    qDebug() << ui->mainEdit_2->fontPointSize();
    QCppHighlighter *hi = new QCppHighlighter(ui->mainEdit_2);

    // Start application maximized - that's quite useful for IDE
    //MainWindow::showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

