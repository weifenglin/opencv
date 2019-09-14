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
using namespace std;

class Hi_Opencv : public QMainWindow
{
	Q_OBJECT

public:
	Hi_Opencv(QWidget *parent = Q_NULLPTR);
	int i = -1;
	int j, k, m, top, bottom, left, right;
	int r = 100;
	int thresh = 100;
	int match_method;

	Scalar value;
	RNG rng;
	QString str;

private slots:
	void on_open();
	void on_start();
	int on_blur_show();
	int on_gaussian_show();
	int on_median_show();
	int on_Bilateral_show();

	//形态变换槽函数
	void on_open_2();
	void on_start_2();

	int on_erode_show();
	int on_dilate_show();
	int on_morphologyEX_show();

	void on_form_RECT();
	void on_form_CROSS();
	void on_form_ELLIPSE();
	void on_opening();
	void on_closing();
	void on_gradient();
	void on_top();
	void on_black();


	//目标变换
	void on_open_5();
	void on_convexHull();
	void on_rectcircle();
	void on_fitEllipse();

	//目标变换-模板匹配
	void on_open1();
	void on_open2();
	void on_match();
	void on_method1();
	void on_method2();
	void on_method3();
	void on_method4();
	void on_method5();
	void on_method6();

	//其他
	void on_open_7();
	void on_spinBox_value();
	void on_threshold();
	void on_type();
	void on_value();
	void on_bordertype1();
	void on_bordertype2();
	void on_makeborder();
	void on_start_7();
	void on_Point();

	//bianyuanjiance
	int on_sobel_show();//进行sebel操作
	void on_bystart();//开始边缘检测操作

	//图像变形
	void w3openPic();
	void w3up();
	void w3down();
	void w3LeftRight();
	void w3UpDown();

private:
	Ui::Hi_OpencvClass ui;
	Mat image;
	Mat image1, image2, image3, image4;
	Mat result;
};
