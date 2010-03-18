#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qsyntaxhighlighter.h"

MyHi::MyHi(QTextEdit *parent)
        : QSyntaxHighlighter(parent)
{
    //Empty constructor
    //Suck it
}

void MyHi::highlightBlock(const QString &text)
{
    QTextCharFormat myClassFormat;
    myClassFormat.setFontWeight(QFont::Bold);
    myClassFormat.setForeground(Qt::darkMagenta);
    QString pattern = "\\bvoid\\b";

    QRegExp expression(pattern);
    int index = text.indexOf(expression);
    while (index >= 0) {
        int length = expression.matchedLength();
        setFormat(index, length, myClassFormat);
        index = text.indexOf(expression, index + length);
    }
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QTextEdit *editor = new QTextEdit;
    MyHi *hi = new MyHi(ui->mainEdit_2);
    // Start application maximized - that's quite useful for IDE
    MainWindow::showMaximized();
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
