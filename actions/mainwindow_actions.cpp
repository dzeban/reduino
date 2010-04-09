#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "core.h"
#include "highlighter.h"
#include "dialogs/asksavedialog.h"

QString truncate_path(QString full_path)
{
    QStringList list = full_path.split("/");
    return list.last();
}

void MainWindow::on_modificationChanged()
{
    //TODO: Asterisk should be removed on undo
    int current_index = ui->tabWidget->currentIndex();
    QString new_label = ui->tabWidget->tabText(current_index);
    new_label.append("*");
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), new_label);

}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionOpenIcon_triggered()
{
    //	Index of current tab in TabWidget
    int current_index = 0;

    //	Call a file dialog and get name of file open
    QString opening_file = QFileDialog::getOpenFileName(this, tr("Open"),0 ,tr("Source code(*.pde *.h *.c);; All files(*)"));

    //	Create new tab and upload file
    QWidget *newtab = new QWidget();
    QGridLayout *layout = new QGridLayout(newtab);
    layout->setSpacing(0);
    layout->setMargin(0);

    CodeEditor *edit = new CodeEditor(get_file_content(opening_file), newtab);

    layout->addWidget(edit,0,0,1,1);

    edit->setDocumentTitle(opening_file);

    QFont editfont;
    editfont.setStyleStrategy(QFont::PreferAntialias);
    editfont.setFamily("Arial");
    editfont.setPointSize(9);

    edit->setFont(editfont);
    current_index = ui->tabWidget->addTab(newtab, truncate_path(opening_file) );

    QWidget *w = ui->tabWidget->widget(current_index);

    //	Enable syntax highlight
    //QCppHighlighter *tab_highlight = new QCppHighlighter( ( (QPlainTextEdit*)w)->document() );

    //	Switch to opened file
    ui->tabWidget->setCurrentIndex(current_index);
    QObject::connect(w, SIGNAL(modificationChanged(bool)), this, SLOT( on_modificationChanged() ) );
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
//   QObjectList list = ui->tabWidget->widget(index)->children();
//    CodeEditor *w = (CodeEditor*)ui->tabWidget->widget(index)->children().last();
    CodeEditor *w = this->getEditorByTabIndex(index);
  //  ui->tabWidget->setCurrentIndex(index);
    if(w->document()->isModified())
    {
        AskSaveDialog *save_dialog = new AskSaveDialog(this);
        save_dialog->tabIndex=index;
	save_dialog->exec();
    }
    else
    {
	ui->tabWidget->removeTab(index);
    }
}

void MainWindow::closetabdialog_actionDontSaveAndClose(int index)
{
        ui->tabWidget->removeTab(index);
}

void MainWindow::closetabdialog_actionSaveAndClose(int index)
{
     //   this->getEditorByTabIndex(index)->document()->setModified(false);
        this->on_actionSaveIcon_triggered();
        this->closetabdialog_actionDontSaveAndClose(index);
}


void MainWindow::on_actionSaveIcon_triggered()
{
    //saveCurrentTab();
    // Get current QPlainTextEdit with saving text
    CodeEditor *w = this->getCurrentEditor();

    // Get full path to file
    QString filename = w->documentTitle();

    // Create file handle
    QFile save_file(filename);

    // Open file
    if (save_file.open(QFile::ReadWrite))
    {
	//Write to file
	//QDataStream stream(&save_file);
	//stream << w->toPlainText().toUtf8();
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


void MainWindow::on_actionLine_wrap_triggered(bool checked)
{
    CodeEditor *e;
    foreach (e,this->getActiveEditorsList()){
        switch (checked){
            case 0: e->setLineWrapMode(QPlainTextEdit::NoWrap); break;
            case 1: e->setLineWrapMode(QPlainTextEdit::WidgetWidth);  break;
        }

    }
}
