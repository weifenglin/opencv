#pragma once

#include <QtWidgets/QMainWindow>
#include <qlineedit.h>
#include "ui_Hi_Opencv.h"
#include <warning.h>
#include<QGraphicsScene>  
#include<QGraphicsView>                 //graphicsview类
#include<opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>  //opencv申明
#include <qfiledialog.h>                //getopenfilename 类申明
#include <qlabel.h>  //label类
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

	//bianyuanjiance
	int on_sobel_show();//进行sebel操作
	void on_bystart();//开始边缘检测操作

private:
	Ui::Hi_OpencvClass ui;
	//mydialog dialog1;
	warning  dialog1;
	Mat image;
	Mat image1;
};
