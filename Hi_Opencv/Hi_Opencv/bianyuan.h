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

class bianyuan : public QMainWindow
{
	Q_OBJECT

public:
    bianyuan(QWidget *parent = Q_NULLPTR);
	int i = -1;
	int j, k, m;
	QString str;

private slots:
	void on_byopen();
	//void on_bystart();
	int on_sobel_show();//����sebel����


	/*
	int on_gaussian_show();
	int on_median_show();
	int on_Bilateral_show();
	*/


private:
	Ui::Hi_OpencvClass ui;
	Mat image;
	Mat image1;
};
