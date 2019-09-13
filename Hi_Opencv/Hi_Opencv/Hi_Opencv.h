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
using namespace std;

class Hi_Opencv : public QMainWindow
{
	Q_OBJECT

public:
	Hi_Opencv(QWidget *parent = Q_NULLPTR);
	int i = -1;
	int j, k, m, top, bottom, left, right;
	int r = 100;
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

	//��̬�任�ۺ���
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

	//����
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
	int on_sobel_show();//����sebel����
	void on_bystart();//��ʼ��Ե������

	//ͼ�����
	void w3openPic();
	void w3up();
	void w3down();
	void w3LeftRight();
	void w3UpDown();

private:
	Ui::Hi_OpencvClass ui;
	Mat image;
	Mat image1, image2;
};
