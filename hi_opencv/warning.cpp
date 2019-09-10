#include "warning.h"

warning::warning(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

warning::~warning()
{
}

void warning::changetext1() 
{
	ui.label->setText("Incorrect input,Please enter positive odd number");
}

void warning::changetext2()
{
	ui.label->setText("Incorrect input,Please enter positive  number");
}
