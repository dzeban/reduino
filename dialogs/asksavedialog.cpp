#include "asksavedialog.h"
#include "ui_asksavedialog.h"
#include "mainwindow.h"

AskSaveDialog::AskSaveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AskSaveDialog)
{
    ui->setupUi(this);
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


	    break;
	}

	case QDialogButtonBox::No :
	{
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
