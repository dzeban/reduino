#include "asksavedialog.h"
#include "ui_asksavedialog.h"

AskSaveDialog::AskSaveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AskSaveDialog)
{
    ui->setupUi(this);
    connect(this,SIGNAL(yesButtonClicked(int)),parent,SLOT(closetabdialog_actionSaveAndClose(int)));
    connect(this,SIGNAL(noButtonClicked(int)),parent,SLOT(closetabdialog_actionDontSaveAndClose(int)));
    //ui->askSaveDialogButtonBox->
}

AskSaveDialog::~AskSaveDialog()
{
    delete ui;
}

void AskSaveDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type())
    {
	case QEvent::LanguageChange:
	    ui->retranslateUi(this);
	    break;
	default:
	    break;
    }
}

void AskSaveDialog::on_askSaveDialogButtonBox_clicked(QAbstractButton* button)
{


    switch(ui->askSaveDialogButtonBox->standardButton(button))
    {
	case QDialogButtonBox::Yes :
	{
            emit yesButtonClicked(tabIndex);
	    break;
	}

	case QDialogButtonBox::No :
	{
            qDebug() << tabIndex;
            emit noButtonClicked(tabIndex);
	    break;
	}

	case QDialogButtonBox::Cancel :
	{
	    break;
	}
	default:
	{
	    break;
	}

    };
}
