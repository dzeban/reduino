#ifndef ASKSAVEDIALOG_H
#define ASKSAVEDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
    class AskSaveDialog;
}

class AskSaveDialog : public QDialog {
    Q_OBJECT
public:
    AskSaveDialog(QWidget *parent = 0);
    ~AskSaveDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::AskSaveDialog *ui;



private slots:
    void on_askSaveDialogButtonBox_clicked(QAbstractButton* button);
};

#endif // ASKSAVEDIALOG_H
