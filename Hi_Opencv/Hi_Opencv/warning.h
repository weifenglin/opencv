#pragma once

#include <QDialog>
#include "ui_warning.h"

class warning : public QDialog
{
	Q_OBJECT

public:
	warning(QWidget *parent = Q_NULLPTR);
	~warning();

	void changetext1();
	void changetext2();

private:
	Ui::warning ui;
};