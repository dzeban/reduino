#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "core.h"

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionOpenIcon_triggered()
{
    //	Call a file dialog and get name of file open
    QString opening_file = QFileDialog::getOpenFileName(this, tr("Open"),0 ,tr("Source code(*.pde *.h *.c);; All files(*)"));

    // Create new tab and upload file
    ui->tabWidget->addTab(new QPlainTextEdit(get_file_content(opening_file)), opening_file);






}
