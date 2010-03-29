#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionOpenIcon_triggered()
{
    //	Call a file dialog and get name of file open
    QString opening_file = QFileDialog::getOpenFileName(this, tr("Open"),0 ,tr("Source code(*.pde *.h *.c);; All files(*)"));

    //Create new tab and upload file to it
    ui->tabWidget->addTab(0,opening_file);

}
