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

	//bianyuanjiance
	int on_sobel_show();//����sebel����
	int on_laplace_show();//����laplace����
	int on_canny_show();//����canny����
	int on_HoughLine_show();//����hough���Բ���
	int on_HoughCircle_show();//���л�����Բ�任
	int on_findContours_show();//ɨ��ͼ���е�����
	int on_findContoursLength_show();//ɨ��ͼ���е����
	void on_bystart();//��ʼ��Ե������
	void on_byopen();

	//ͼ�����
	//void w3openPic();
	//void w3up();
	//void w3down();
	//void w3LeftRight();
	//void w3UpDown();
	//123

private:
	Ui::Hi_OpencvClass ui;
	//mydialog dialog1;
	warning  dialog1;
	Mat image;
	Mat image1;
	QLabel *label;
};
