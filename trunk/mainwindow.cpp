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

    switch (e->type())
    {
	case QEvent::LanguageChange:
	    ui->retranslateUi(this);
	    break;
	default:
	    break;
    }
}

void MainWindow::saveCurrentTab()
{
    // Get current QPlainTextEdit with saving text
    QPlainTextEdit *w = (QPlainTextEdit*)ui->tabWidget->widget(ui->tabWidget->currentIndex());

    // Get full path to file
    QString filename = w->documentTitle();

    // Create file handle
    QFile save_file(filename);

    // Open file
    if (save_file.open(QFile::ReadWrite))
    {
	//Write to file
	qint64 ff = save_file.write(w->toPlainText().toUtf8());
	QString s;
	s.setNum(ff);
	ui->logArea->append(s);
    }
    else
    {
	// TODO: Do something. Like throw exception
	ui->logArea->append("Failed on opening file");
    }

    save_file.close();
}

