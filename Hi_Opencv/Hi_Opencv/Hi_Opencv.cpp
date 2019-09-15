#include "Hi_Opencv.h"
#include <QDebug>
#include <qmessagebox.h>

Hi_Opencv::Hi_Opencv(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.label_w->hide();
	ui.label_h->hide();
	ui.label_i->hide();
	ui.lineEdit_w->hide();
	ui.lineEdit_h->hide();
	ui.lineEdit_i->hide();

	ui.widget->hide();
	ui.widget_2->hide();
	ui.widget_3->hide();

	ui.widget_4->hide();
	ui.widget_5->hide();



	ui.pushButton_match->setEnabled(false);
	//边缘检测
	ui.label_31->hide();
	ui.lineEdit31->hide();
}


///QString转String
String qstr2str(QString qstr)
{
	QByteArray cdata = qstr.toLocal8Bit();
	return String(cdata);
}

void Hi_Opencv::on_open()
{
	QString filename;
	filename = QFileDialog::getOpenFileName(this, tr("选择图像"), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF)"));

	if (filename.isEmpty())
	{
		return;
	}
	else
	{

		//String str  filename.toStdString();//QString字符串中有中文转化成String会有乱码
		String str = qstr2str(filename);//写了一个qstr2str函数用于转化
		image = imread(str);
		cvtColor(image, image, COLOR_BGR2RGB);
		cv::resize(image, image, Size(300, 200));
		QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);
		ui.label_in->setPixmap(QPixmap::fromImage(img));
		ui.label_in->resize(QSize(img.width(), img.height()));
		ui.pushButton_start->setEnabled(true);
	}
}

void Hi_Opencv::on_start()
	{
	switch (i) {
	case 1:
			j = atoi(ui.lineEdit_w->text().toStdString().c_str());
			k = atoi(ui.lineEdit_h->text().toStdString().c_str());
			if (j > 0 && k > 0)
			{
				cv::blur(image, image1, Size(j, k));
			}
			else
			{
				QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
				return;
			}
		break;
	case 2:
			m = atoi(ui.lineEdit_i->text().toStdString().c_str());
			if (m > 0 && m % 2 == 1)
			{
				cv::GaussianBlur(image, image1, Size(m, m), 0, 0);
			}
			else
			{
				QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive odd number");
				return;
			}
		break;
	case 3:
			m = atoi(ui.lineEdit_i->text().toStdString().c_str());
			if (m > 0 && m % 2 == 1)
			{
				cv::medianBlur(image, image1, m);
			}
			else
			{
				QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive odd  number");
				return;
			}
		break;
	case 4:
			m = atoi(ui.lineEdit_i->text().toStdString().c_str());
			if (m > 0)
			{
				cv::bilateralFilter(image, image1, m, m * 2, m / 2);
			}
			else
			{
				QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
				return;
			}
		break;
	default:
		break;
	}
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
	ui.label_out->setPixmap(QPixmap::fromImage(img));
	}

int Hi_Opencv::on_blur_show()
{
	i = 1;
	ui.label_3->setText("blur");
	ui.label_i->hide();
	ui.lineEdit_i->hide();
	ui.label_w->show();
	ui.label_h->show();
	ui.lineEdit_h->show();
	ui.lineEdit_w->show();
	return i;
}

int Hi_Opencv::on_gaussian_show()
{
	i = 2;
	ui.label_3->setText("gaussian");
	ui.label_w->hide();
	ui.label_h->hide();
	ui.lineEdit_w->hide();
	ui.lineEdit_h->hide();
	ui.label_i->show();
	ui.lineEdit_i->show();
	return i;
}

int Hi_Opencv::on_median_show()
{
	i = 3;
	ui.label_3->setText("median");
	ui.label_w->hide();
	ui.label_h->hide();
	ui.lineEdit_w->hide();
	ui.lineEdit_h->hide();
	ui.label_i->show();
	ui.lineEdit_i->show();
	return i;
}

int Hi_Opencv::on_Bilateral_show()
{
	i = 4;
	ui.label_3->setText("Bilateral");
	ui.label_w->hide();
	ui.label_h->hide();
	ui.lineEdit_w->hide();
	ui.lineEdit_h->hide();
	ui.label_i->show();
	ui.lineEdit_i->show();
	return i;
}


//形态变换
void Hi_Opencv::on_open_2()
{
	QString filename;
	filename = QFileDialog::getOpenFileName(this, tr("选择图像"), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF)"));

	if (filename.isEmpty())
	{
		return;
	}
	else
	{

		//String str  filename.toStdString();//QString字符串中有中文转化成String会有乱码
		String str = qstr2str(filename);//写了一个qstr2str函数用于转化
		image = imread(str);
		cvtColor(image, image, COLOR_BGR2RGB);
		cv::resize(image, image, Size(300, 200));
		QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);

		ui.label_in_2->setPixmap(QPixmap::fromImage(img));
		ui.label_in_2->resize(QSize(img.width(), img.height()));
		ui.pushButton_start_2->setEnabled(true);
	}
}

int Hi_Opencv::on_erode_show()
{
	i = 1;
	ui.label_title->setText("Erode");
	ui.widget_3->hide();
	ui.radioButton_RECT->setEnabled(true);
	ui.radioButton_CROSS->setEnabled(true);
	ui.radioButton_ELLIPSE->setEnabled(true);
	ui.lineEdit_size->setText("");

	ui.widget->show();
	ui.label_size->setText("erosion_size:");
	ui.widget_2->show();
	return i;
}

int Hi_Opencv::on_dilate_show()
{
	i = 2;
	ui.widget_3->hide();
	ui.label_title->setText("Dilate");
	ui.radioButton_RECT->setEnabled(true);
	ui.radioButton_CROSS->setEnabled(true);
	ui.radioButton_ELLIPSE->setEnabled(true);
	ui.lineEdit_size->setText("");
	ui.widget->show();

	ui.label_size->setText("dilate_size:");
	ui.widget_2->show();
	return i;
}

int Hi_Opencv::on_morphologyEX_show()
{
	ui.label_title->setText("MorphologyEX");
	i = 3;
	ui.radioButton_RECT->setEnabled(true);
	ui.radioButton_CROSS->setEnabled(true);
	ui.radioButton_ELLIPSE->setEnabled(true);
	ui.radioButton_opening->setEnabled(true);
	ui.radioButton_closing->setEnabled(true);
	ui.radioButton_gradient->setEnabled(true);
	ui.radioButton_top->setEnabled(true);
	ui.radioButton_black->setEnabled(true);

	ui.lineEdit_size->setText("");
	ui.widget->show();
	ui.widget_3->show();
	ui.label_size->setText("morph_size:");
	ui.widget_2->show();
	return i;
}
void Hi_Opencv::on_form_RECT()
{
	ui.radioButton_CROSS->setEnabled(false);
	ui.radioButton_ELLIPSE->setEnabled(false);
	j = MORPH_RECT;
}

void Hi_Opencv::on_form_CROSS()
{
	ui.radioButton_RECT->setEnabled(false);
	ui.radioButton_ELLIPSE->setEnabled(false);
	j = MORPH_CROSS;
}

void Hi_Opencv::on_form_ELLIPSE()
{
	ui.radioButton_CROSS->setEnabled(false);
	ui.radioButton_RECT->setEnabled(false);
	j = MORPH_ELLIPSE;

}

void Hi_Opencv::on_opening()
{
	ui.radioButton_closing->setEnabled(false);
	ui.radioButton_gradient->setEnabled(false);
	ui.radioButton_top->setEnabled(false);
	ui.radioButton_black->setEnabled(false);
	m = MORPH_OPEN;
}

void Hi_Opencv::on_closing()
{
	ui.radioButton_opening->setEnabled(false);
	ui.radioButton_gradient->setEnabled(false);
	ui.radioButton_top->setEnabled(false);
	ui.radioButton_black->setEnabled(false);
	m = MORPH_CLOSE;
}

void Hi_Opencv::on_gradient()
{
	ui.radioButton_closing->setEnabled(false);
	ui.radioButton_opening->setEnabled(false);
	ui.radioButton_top->setEnabled(false);
	ui.radioButton_black->setEnabled(false);
	m = MORPH_GRADIENT;
}

void Hi_Opencv::on_top()
{
	ui.radioButton_closing->setEnabled(false);
	ui.radioButton_gradient->setEnabled(false);
	ui.radioButton_opening->setEnabled(false);
	ui.radioButton_black->setEnabled(false);
	m = MORPH_TOPHAT;
}

void Hi_Opencv::on_black()
{
	ui.radioButton_closing->setEnabled(false);
	ui.radioButton_gradient->setEnabled(false);
	ui.radioButton_top->setEnabled(false);
	ui.radioButton_opening->setEnabled(false);
	m = MORPH_BLACKHAT;
}

void Hi_Opencv::on_start_2()
{
	switch (i)
	{
	case 1:
	{k = atoi(ui.lineEdit_size->text().toStdString().c_str());
	if (k > 0)
	{
		Mat element = getStructuringElement(j, Size(2 * k + 1, 2 * k + 1), Point(k, k));
		cv::erode(image, image1, element);
		QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
		ui.label_out_2->setPixmap(QPixmap::fromImage(img));
		ui.label_out_2->resize(QSize(img.width(), img.height()));
		ui.radioButton_RECT->setEnabled(true);
		ui.radioButton_CROSS->setEnabled(true);
		ui.radioButton_ELLIPSE->setEnabled(true);
		ui.lineEdit_size->setText("");
	}
	else
	{
		QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
		ui.lineEdit_size->setText("");
		return;
	}
	break;
	}
	case 2:
	{
		k = atoi(ui.lineEdit_size->text().toStdString().c_str());
		if (k > 0)
		{
			Mat element = getStructuringElement(j, Size(2 * k + 1, 2 * k + 1), Point(k, k));
			cv::dilate(image, image1, element);

			QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
			ui.label_out_2->setPixmap(QPixmap::fromImage(img));
			ui.label_out_2->resize(QSize(img.width(), img.height()));

			ui.radioButton_RECT->setEnabled(true);
			ui.radioButton_CROSS->setEnabled(true);
			ui.radioButton_ELLIPSE->setEnabled(true);
			ui.lineEdit_size->setText("");
		}
		else
		{
			QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
			ui.lineEdit_size->setText("");
			return;
		}
		break;
	}
	case 3:
	{
		k = atoi(ui.lineEdit_size->text().toStdString().c_str());
		if (k > 0)
		{
			Mat element = getStructuringElement(j, Size(2 * k + 1, 2 * k + 1), Point(k, k));
			cv::morphologyEx(image, image1, m, element);

			QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
			ui.label_out_2->setPixmap(QPixmap::fromImage(img));
			ui.label_out_2->resize(QSize(img.width(), img.height()));
			ui.radioButton_RECT->setEnabled(true);
			ui.radioButton_CROSS->setEnabled(true);
			ui.radioButton_ELLIPSE->setEnabled(true);
			ui.radioButton_opening->setEnabled(true);
			ui.radioButton_closing->setEnabled(true);
			ui.radioButton_gradient->setEnabled(true);
			ui.radioButton_top->setEnabled(true);
			ui.radioButton_black->setEnabled(true);
			ui.lineEdit_size->setText("");
		}
		else
		{
			QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
			ui.lineEdit_size->setText("");
			return;
		}
		break;
	}
	default:
		break;
	}

}

//bianyuanjiance
Mat img1;
int i31;
void Hi_Opencv::on_bystart()
{
	switch (i)
	{
	case 1:
		//i31 = atoi(ui.lineEdit31->text().toStdString().c_str());
		if (i31 > 0)
		{
			GaussianBlur(img1, image, Size(i31, i31), 0, 0, BORDER_DEFAULT);//对原图像进行降噪；

		}
		else
		{
			QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
			return;
		}
		break;
	default:
		break;
	}

}

int Hi_Opencv::on_sobel_show()
{
	i = 31;
	ui.label_by1->setText("sobel");
	return i;

}


//图像变形
void Hi_Opencv::w3openPic()
{
	QString filename;
	filename = QFileDialog::getOpenFileName(this, tr("选择图像"), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF)"));

	if (filename.isEmpty())
	{
		return;
	}
	else
	{

		//String str  filename.toStdString();//QString字符串中有中文转化成String会有乱码
		String str = qstr2str(filename);//写了一个qstr2str函数用于转化
		image = imread(str);
		cvtColor(image, image, COLOR_BGR2RGB);
		cv::resize(image, image, Size(256, 256));
		QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);


		//label_in = new QLabel();
		ui.w3Label->setPixmap(QPixmap::fromImage(img));
		ui.w3Label->setAlignment(Qt::AlignCenter);
		//ui.w3Label->resize(QSize(img.width(), img.height()));
		//ui.label_in->show();
		//ui.pushButton_start->setEnabled(true);
	}
}

void Hi_Opencv::w3up()
{
	pyrUp(image, image, Size(image.cols * 2, image.rows * 2));
	//cv::resize(image, image, Size(300, 200));
	QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);


	//label_in = new QLabel();
	ui.w3Label->setPixmap(QPixmap::fromImage(img));
	ui.w3Label->setAlignment(Qt::AlignCenter);

	//ui.radioButton->setCheckable(true);

}

void Hi_Opencv::w3down()
{
	pyrDown(image, image, Size(image.cols / 2, image.rows / 2));
	//cv::resize(image, image, Size(300, 200));
	QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);


	//label_in = new QLabel();
	ui.w3Label->setPixmap(QPixmap::fromImage(img));
	ui.w3Label->setAlignment(Qt::AlignCenter);

	//ui.radioButton.setChecked(true);
}

void Hi_Opencv::w3LeftRight()
{
	Mat map1, map2;
	///dst.create(image.size(), image.type());
	map1.create(image.size(), CV_32FC1);
	map2.create(image.size(), CV_32FC1);


	int rows = image.rows;
	int cols = image.cols;
	//图像遍历
	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < cols; i++)
		{
			map1.at<float>(j, i) = cols - i;
			map2.at<float>(j, i) = j;
		}
	}

	remap(image, image, map1, map2, INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));


	QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);


	//label_in = new QLabel();
	ui.w3Label->setPixmap(QPixmap::fromImage(img));
	ui.w3Label->setAlignment(Qt::AlignCenter);

}

void Hi_Opencv::w3UpDown()
{
	Mat map1, map2;
	///dst.create(image.size(), image.type());
	map1.create(image.size(), CV_32FC1);
	map2.create(image.size(), CV_32FC1);

	int rows = image.rows;
	int cols = image.cols;
	//图像遍历
	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < cols; i++)
		{
			map1.at<float>(j, i) = i;
			map2.at<float>(j, i) = rows - j;
		}
	}

	remap(image, image, map1, map2, INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));

	QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);


	//label_in = new QLabel();
	ui.w3Label->setPixmap(QPixmap::fromImage(img));
	ui.w3Label->setAlignment(Qt::AlignCenter);
}

//目标变换
void Hi_Opencv::on_open_5()
{
	QString filename;
	filename = QFileDialog::getOpenFileName(this, tr("选择图像"), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF)"));

	if (filename.isEmpty())
	{
		return;
	}
	else
	{

		//String str  filename.toStdString();//QString字符串中有中文转化成String会有乱码
		String str = qstr2str(filename);//写了一个qstr2str函数用于转化
		image = imread(str);
		cvtColor(image, image3, COLOR_BGR2RGB);
		cvtColor(image, image2, COLOR_BGR2GRAY);
		cv::resize(image2, image2, Size(300, 200));
		cv::resize(image3, image3, Size(300, 200));
		QImage img = QImage((const unsigned char*)(image3.data), image3.cols, image3.rows, QImage::Format_RGB888);

		ui.label_in_5->setPixmap(QPixmap::fromImage(img));
		ui.label_in_5->resize(QSize(img.width(), img.height()));

	}
}

void Hi_Opencv::on_convexHull()
{
	Mat src_copy = image.clone();
	Mat threshold_output;
	vector<Mat> contours;
	vector<Vec4i> hierarchy;


	threshold(image2, threshold_output, thresh, 255, THRESH_BINARY);
	findContours(threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	vector<vector<Point> >hull(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		convexHull(Mat(contours[i]), hull[i], false);
	}

	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		drawContours(drawing, hull, i, color, 1, 8, vector<Vec4i>(), 0, Point());
	}

	QImage img1 = QImage((const unsigned char*)(drawing.data), drawing.cols, drawing.rows, QImage::Format_RGB888);
	ui.label_out_5->setPixmap(QPixmap::fromImage(img1));
	ui.label_out_5->resize(QSize(img1.width(), img1.height()));

}

void Hi_Opencv::on_rectcircle()
{
	Mat threshold_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	/// 使用Threshold检测边缘
	threshold(image2, threshold_output, thresh, 255, THRESH_BINARY);
	/// 找到轮廓
	findContours(threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// 多边形逼近轮廓 + 获取矩形和圆形边界框
	vector<vector<Point> > contours_poly(contours.size());
	vector<Rect> boundRect(contours.size());
	vector<Point2f>center(contours.size());
	vector<float>radius(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
		boundRect[i] = boundingRect(Mat(contours_poly[i]));
		minEnclosingCircle(contours_poly[i], center[i], radius[i]);
	}


	/// 画多边形轮廓 + 包围的矩形框 + 圆形框
	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0);
		circle(drawing, center[i], (int)radius[i], color, 2, 8, 0);
	}
	QImage img1 = QImage((const unsigned char*)(drawing.data), drawing.cols, drawing.rows, QImage::Format_RGB888);
	ui.label_out_5->setPixmap(QPixmap::fromImage(img1));
	ui.label_out_5->resize(QSize(img1.width(), img1.height()));

}

void Hi_Opencv::on_fitEllipse()
{
	Mat threshold_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	/// 阈值化检测边界
	threshold(image2, threshold_output, thresh, 255, THRESH_BINARY);
	/// 寻找轮廓
	findContours(threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// 对每个找到的轮廓创建可倾斜的边界框和椭圆
	vector<RotatedRect> minRect(contours.size());
	vector<RotatedRect> minEllipse(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		minRect[i] = minAreaRect(Mat(contours[i]));
		if (contours[i].size() > 5)
		{
			minEllipse[i] = fitEllipse(Mat(contours[i]));
		}
	}

	/// 绘出轮廓及其可倾斜的边界框和边界椭圆
	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		// contour
		drawContours(drawing, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		// ellipse
		ellipse(drawing, minEllipse[i], color, 2, 8);
		// rotated rectangle
		Point2f rect_points[4]; minRect[i].points(rect_points);
		for (int j = 0; j < 4; j++)
			line(drawing, rect_points[j], rect_points[(j + 1) % 4], color, 1, 8);
	}

	QImage img1 = QImage((const unsigned char*)(drawing.data), drawing.cols, drawing.rows, QImage::Format_RGB888);
	ui.label_out_5->setPixmap(QPixmap::fromImage(img1));
	ui.label_out_5->resize(QSize(img1.width(), img1.height()));

}



//目标定位-模板匹配
void Hi_Opencv::on_open1()
{
	QString filename;
	filename = QFileDialog::getOpenFileName(this, tr("选择图像"), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF)"));

	if (filename.isEmpty())
	{
		return;
	}
	else
	{
		String str = qstr2str(filename);
		image = imread(str);
		cvtColor(image, image2, COLOR_BGR2RGB);
		cv::resize(image2, image2, Size(300, 200));
		QImage img = QImage((const unsigned char*)(image2.data), image2.cols, image2.rows, QImage::Format_RGB888);
		ui.label_in_original->setPixmap(QPixmap::fromImage(img));
		ui.label_in_original->resize(QSize(img.width(), img.height()));
	}
}

void Hi_Opencv::on_open2()
{
	QString filename;
	filename = QFileDialog::getOpenFileName(this, tr("选择图像"), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF)"));

	if (filename.isEmpty())
	{
		return;
	}
	else
	{
		String str = qstr2str(filename);
		image1 = imread(str);
		cvtColor(image1, image3, COLOR_BGR2RGB);
		cv::resize(image3, image3, Size(100, 75));
		QImage img = QImage((const unsigned char*)(image3.data), image3.cols, image3.rows, QImage::Format_RGB888);
		ui.label_in_templat->setPixmap(QPixmap::fromImage(img));
		ui.label_in_templat->resize(QSize(img.width(), img.height()));
	}
}

void Hi_Opencv::on_method1()
{
	ui.pushButton_match->setEnabled(true);
	match_method = TM_SQDIFF;
	ui.radioButton_method2->setEnabled(false);
	ui.radioButton_method3->setEnabled(false);
	ui.radioButton_method4->setEnabled(false);
	ui.radioButton_method5->setEnabled(false);
	ui.radioButton_method6->setEnabled(false);
}

void Hi_Opencv::on_method2()
{
	ui.pushButton_match->setEnabled(true);
	match_method = TM_SQDIFF_NORMED;
	ui.radioButton_method1->setEnabled(false);
	ui.radioButton_method3->setEnabled(false);
	ui.radioButton_method4->setEnabled(false);
	ui.radioButton_method5->setEnabled(false);
	ui.radioButton_method6->setEnabled(false);
}

void Hi_Opencv::on_method3()
{
	ui.pushButton_match->setEnabled(true);
	match_method = TM_CCORR;
	ui.radioButton_method2->setEnabled(false);
	ui.radioButton_method1->setEnabled(false);
	ui.radioButton_method4->setEnabled(false);
	ui.radioButton_method5->setEnabled(false);
	ui.radioButton_method6->setEnabled(false);
}

void Hi_Opencv::on_method4()
{
	ui.pushButton_match->setEnabled(true);
	match_method = TM_CCORR_NORMED;
	ui.radioButton_method2->setEnabled(false);
	ui.radioButton_method3->setEnabled(false);
	ui.radioButton_method1->setEnabled(false);
	ui.radioButton_method5->setEnabled(false);
	ui.radioButton_method6->setEnabled(false);
}

void Hi_Opencv::on_method5()
{
	ui.pushButton_match->setEnabled(true);
	match_method = TM_CCOEFF;
	ui.radioButton_method2->setEnabled(false);
	ui.radioButton_method3->setEnabled(false);
	ui.radioButton_method4->setEnabled(false);
	ui.radioButton_method1->setEnabled(false);
	ui.radioButton_method6->setEnabled(false);
}

void Hi_Opencv::on_method6()
{
	ui.pushButton_match->setEnabled(true);
	match_method = TM_CCOEFF_NORMED;
	ui.radioButton_method2->setEnabled(false);
	ui.radioButton_method3->setEnabled(false);
	ui.radioButton_method4->setEnabled(false);
	ui.radioButton_method5->setEnabled(false);
	ui.radioButton_method1->setEnabled(false);
}


void Hi_Opencv::on_match()
{
	ui.radioButton_method1->setEnabled(true);
	ui.radioButton_method2->setEnabled(true);
	ui.radioButton_method3->setEnabled(true);
	ui.radioButton_method4->setEnabled(true);
	ui.radioButton_method5->setEnabled(true);
	ui.radioButton_method6->setEnabled(true);
	
	cv::resize(image3, image4, Size(25, 22));
	Mat image_display;
	image2.copyTo(image_display);

	//int result_cols = image5.cols - image6.cols + 1;
	//int result_rows = image5.rows - image6.rows + 1;
	int result_cols = image2.cols - image4.cols + 1;
	int result_rows = image2.rows - image4.rows + 1;

	result.create(result_cols, result_rows, CV_32FC1);
	//matchTemplate(image5, image6, result, match_method);
	matchTemplate(image2, image4, result, match_method);
	normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

	double minVal; double maxVal; Point minLoc; Point maxLoc;
	Point matchLoc;

	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

	if (match_method == TM_SQDIFF || match_method == TM_SQDIFF_NORMED)
	{
		matchLoc = minLoc;
	}
	else
	{
		matchLoc = maxLoc;
	}

	rectangle(image_display, matchLoc, Point(matchLoc.x + image4.cols, matchLoc.y + image4.rows), Scalar::all(0), 2, 8, 0);
	rectangle(result, matchLoc, Point(matchLoc.x + image4.cols, matchLoc.y + image4.rows), Scalar::all(0), 2, 8, 0);

	QImage img3 = QImage((const unsigned char*)(image_display.data), image_display.cols, image_display.rows, QImage::Format_RGB888);
	ui.label_out_result->setPixmap(QPixmap::fromImage(img3));
	ui.label_out_result->resize(QSize(img3.width(), img3.height()));

	ui.pushButton_match->setEnabled(false);
}


//其他
void Hi_Opencv::on_open_7()
{
	QString filename;
	filename = QFileDialog::getOpenFileName(this, tr("选择图像"), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF)"));

	if (filename.isEmpty())
	{
		return;
	}
	else
	{

		//String str  filename.toStdString();//QString字符串中有中文转化成String会有乱码
		String str = qstr2str(filename);//写了一个qstr2str函数用于转化
		image = imread(str);
		cvtColor(image, image2, COLOR_BGR2RGB);
		cv::resize(image2, image2, Size(300, 200));
		QImage img = QImage((const unsigned char*)(image2.data), image2.cols, image2.rows, QImage::Format_RGB888);

		ui.label_in_3->setPixmap(QPixmap::fromImage(img));
		ui.label_in_3->resize(QSize(img.width(), img.height()));

	}
}

void Hi_Opencv::on_threshold()
{
	ui.pushButton_open_7->show();
	ui.widget_5->hide();
	ui.widget_4->show();
	ui.spinBox_type->setValue(0);
	ui.horizontalSlider_value->setValue(0);

}

void Hi_Opencv::on_type()
{
	//ui.horizontalSlider_value->setValue(0);
	j = ui.spinBox_type->value();
}

void Hi_Opencv::on_spinBox_value()
{
	ui.horizontalSlider_value->setValue(ui.spinBox_value->value());

}

void Hi_Opencv::on_value()
{
	on_type();
	ui.spinBox_value->setValue(ui.horizontalSlider_value->value());
	k = ui.horizontalSlider_value->value();

	threshold(image2, image1, k, 255, j);
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
	ui.label_out_3->setPixmap(QPixmap::fromImage(img));
	ui.label_out_3->resize(QSize(img.width(), img.height()));
}

void Hi_Opencv::on_makeborder()
{
	ui.pushButton_open_7->show();
	ui.widget_4->hide();
	ui.widget_5->show();
	ui.radioButton->setEnabled(true);
	ui.radioButton_2->setEnabled(true);
}

void Hi_Opencv::on_bordertype1()
{
	j = BORDER_CONSTANT;

}

void Hi_Opencv::on_bordertype2()
{
	j = BORDER_REPLICATE;

}

void Hi_Opencv::on_start_7()
{
	top = int(0.05*image.rows);
	bottom = int(0.05*image.rows);
	left = int(0.05*image.cols);
	right = int(0.05*image.cols);

	value = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));

	copyMakeBorder(image, image1, top, bottom, left, right, j, value);

	cvtColor(image1, image1, COLOR_BGR2RGB);
	cv::resize(image1, image1, Size(300, 200));
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
	ui.label_out_3->setPixmap(QPixmap::fromImage(img));
	ui.label_out_3->resize(QSize(img.width(), img.height()));
}



void Hi_Opencv::on_Point()
{
	ui.pushButton_open_7->hide();
	ui.widget_4->hide();
	ui.widget_5->hide();
	
	Mat src = Mat::zeros(Size(4 * r, 4 * r), CV_8UC1);

	/// 绘制一系列点创建一个轮廓:
	vector<Point2f> vert(6);

	vert[0] = Point(1.5*r, 1.34*r);
	vert[1] = Point(1 * r, 2 * r);
	vert[2] = Point(1.5*r, 2.866*r);
	vert[3] = Point(2.5*r, 2.866*r);
	vert[4] = Point(3 * r, 2 * r);
	vert[5] = Point(2.5*r, 1.34*r);

	/// 在src内部绘制
	for (int j = 0; j < 6; j++)
	{
		line(src, vert[j], vert[(j + 1) % 6], Scalar(255), 3, 8);
	}

	/// 得到轮廓
	vector<vector<Point> > contours; vector<Vec4i> hierarchy;
	Mat src_copy = src.clone();

	findContours(src_copy, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

	/// 计算到轮廓的距离
	Mat raw_dist(src.size(), CV_32FC1);

	for (int j = 0; j < src.rows; j++)
	{
		for (int i = 0; i < src.cols; i++)
		{
			raw_dist.at<float>(j, i) = pointPolygonTest(contours[0], Point2f(i, j), true);
		}
	}

	double minVal; double maxVal;
	minMaxLoc(raw_dist, &minVal, &maxVal, 0, 0, Mat());
	minVal = abs(minVal); maxVal = abs(maxVal);

	/// 图形化的显示距离
	Mat drawing = Mat::zeros(src.size(), CV_8UC3);

	for (int j = 0; j < src.rows; j++)
	{
		for (int i = 0; i < src.cols; i++)
		{
			if (raw_dist.at<float>(j, i) < 0)
			{
				drawing.at<Vec3b>(j, i)[0] = 255 - (int)abs(raw_dist.at<float>(j, i)) * 255 / minVal;
			}
			else if (raw_dist.at<float>(j, i) > 0)
			{
				drawing.at<Vec3b>(j, i)[2] = 255 - (int)raw_dist.at<float>(j, i) * 255 / maxVal;
			}
			else
			{
				drawing.at<Vec3b>(j, i)[0] = 255; drawing.at<Vec3b>(j, i)[1] = 255; drawing.at<Vec3b>(j, i)[2] = 255;
			}
		}
	}
	cvtColor(src, src, COLOR_BGR2RGB);
	cv::resize(src, src, Size(300, 200));
	QImage img = QImage((const unsigned char*)(src.data), src.cols, src.rows, QImage::Format_RGB888);
	ui.label_in_3->setPixmap(QPixmap::fromImage(img));
	ui.label_in_3->resize(QSize(img.width(), img.height()));

	QImage img1 = QImage((const unsigned char*)(drawing.data), drawing.cols, drawing.rows, QImage::Format_RGB888);
	ui.label_out_3->setPixmap(QPixmap::fromImage(img1));
	ui.label_out_3->resize(QSize(img1.width(), img1.height()));
}


