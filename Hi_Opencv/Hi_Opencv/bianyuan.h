#pragma once
#pragma once

#include <QtWidgets/QMainWindow>
#include <qlineedit.h>
#include "ui_Hi_Opencv.h"
#include <warning.h>
#include<QGraphicsScene>  
#include<QGraphicsView>                 //graphicsview��
#include<opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>  //opencv����
#include <qfiledialog.h>                //getopenfilename ������
#include <qlabel.h>  //label��
using namespace cv;

class Hi_Opencv : public QMainWindow
{
	Q_OBJECT

public:
	Hi_Opencv(QWidget *parent = Q_NULLPTR);
	int i = -1;
	int j, k, m;
	QString str;

private slots:
	void on_open();
	void on_start();
	int on_blur_show();
	int on_gaussian_show();
	int on_median_show();
	int on_Bilateral_show();


private:
	Ui::Hi_OpencvClass ui;
	Mat image;
	Mat image1;
};