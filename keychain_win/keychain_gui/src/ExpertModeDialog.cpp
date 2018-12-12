#include "ExpertModeDialog.h"

ExpertModeDialog::ExpertModeDialog(QWidget * parent)
	: QDialog(parent)
{
	QMetaObject::connectSlotsByName(this);
	setFixedSize(600, 400);
	setWindowFlags(Qt::FramelessWindowHint);
	setStyleSheet("background-color:rgb(227,232,248);border-style:outset;border-width:0px;border-radius:5px");
	transactionDescription = new QPlainTextEdit(this);
	transactionDescription->setStyleSheet("color:rgb(70,134,255);background:transparent;border-style:outset;border-width:0px;border-radius:5px;font:15px \"Segoe UI\"");
	transactionDescription->setFixedSize(580, 340);
	transactionDescription->move(5,5);
	OKButton = new QPushButton(this);
	OKButton->setFixedSize(100,25);
	OKButton->move(250, 350);
	OKButton->setCursor(Qt::PointingHandCursor);
	OKButton->setText("OK");
	OKButton->setStyleSheet("color:white;background-color:rgb(70,134,255);border-style:outset;border-width:0px;border-radius:5px;font:16px \"Segoe UI\"");
	connect(OKButton, &QPushButton::pressed, this, &ExpertModeDialog::closeExpertMode);
}


ExpertModeDialog::~ExpertModeDialog()
{

}

void ExpertModeDialog::SetExpertModeText(QString string)
{
	transactionDescription->setPlainText(string);
}

void ExpertModeDialog::closeExpertMode()
{
	close();
}
