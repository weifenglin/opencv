#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_hi_opencv.h"

class hi_opencv : public QMainWindow
{
	Q_OBJECT

public:
	hi_opencv(QWidget *parent = Q_NULLPTR);

private:
	Ui::hi_opencvClass ui;
};
