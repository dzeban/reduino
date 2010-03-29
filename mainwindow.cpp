#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qsyntaxhighlighter.h"
#include "highlighter.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QCppHighlighter *hi = new QCppHighlighter(ui->mainEdit_2->document());

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

