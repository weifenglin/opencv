#include "Hi_Opencv.h"
#include <QDebug>
#include <qmessagebox.h>
#include<vector>

Hi_Opencv::Hi_Opencv(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//i = -1;
	ui.label_w->hide();
	ui.label_h->hide();
	ui.label_i->hide();
	ui.lineEdit_w->hide();
	ui.lineEdit_h->hide();
	ui.lineEdit_i->hide();
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
		//String str=filename.toStdString();//QString字符串中有中文转化成String会有乱码
		String str = qstr2str(filename);//写了一个qstr2str函数用于转化
		image = imread(str);
		cvtColor(image, image, COLOR_BGR2RGB);
		cv::resize(image, image, Size(300, 200));
		QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);

		//label_in = new QLabel();
		ui.label_in->setPixmap(QPixmap::fromImage(img));
		ui.label_in->resize(QSize(img.width(), img.height()));
		//ui.label_in->show();
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
				//dialog1.changetext2();
				//dialog1.show();
				//dialog1.exec();
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
				//dialog1.changetext1();
				//dialog1.show();
				//dialog1.exec();
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
				//dialog1.changetext1();
				//dialog1.show();
				//dialog1.exec();
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
				
				//dialog1.changetext2();
				//dialog1.show();
				//dialog1.exec();
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

//边缘检测——BY FENGLIN
void Hi_Opencv::on_byopen()
{

	QString filename;
	filename = QFileDialog::getOpenFileName(this, tr("选择图像"), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF)"));

	if (filename.isEmpty())
	{
		return;
	}
	else
	{
		//String str=filename.toStdString();//QString字符串中有中文转化成String会有乱码
		String str = qstr2str(filename);//写了一个qstr2str函数用于转化
		image = imread(str);
		cvtColor(image, image, COLOR_BGR2RGB);
		cv::resize(image, image, Size(300, 200));
		QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);
		QLabel *label = new QLabel();
		label->setPixmap(QPixmap::fromImage(img));
		label->resize(QSize(img.width(), img.height()));
		ui.scrollArea_open31->setWidget(label);
		
	}
}

Mat img1,src_gray,grad;
int i_by;
void Hi_Opencv::on_bystart()
{
	switch (i)
	{
	case 31:
		i_by = atoi(ui.lineEdit31->text().toStdString().c_str());
		if (i_by > 0)
		{
			GaussianBlur(image, img1, Size(i_by, i_by), 0, 0, BORDER_DEFAULT);//对原图像进行降噪；
			cvtColor(img1, src_gray, COLOR_BGR2GRAY);
			Mat grad_x, grad_y;
			int scale = 1;
			int delta = 0;
			int ddepth = CV_16S;
			Mat abs_grad_x, abs_grad_y;
			/// 求 X方向梯度
			Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
			/// 求 Y方向梯度
			Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
			convertScaleAbs(grad_x, abs_grad_x);
			convertScaleAbs(grad_y, abs_grad_y);
			addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
			image1 = grad;
			QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
			label = new QLabel();
			label->setPixmap(QPixmap::fromImage(img));
			label->resize(QSize(img.width(), img.height()));
			ui.scrollArea_open32->setWidget(label);
			
		}
		else
		{
			QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
			//dialog1.changetext2();
			//dialog1.show();
			//dialog1.exec();
			return;
		}



		break;

	case 32:
		i_by = atoi(ui.lineEdit31->text().toStdString().c_str());
		if (i_by > 0)
		{
			Mat src, src_gray, dst;
			int kernel_size = 3;
			int scale = 1;
			int delta = 0;
			int ddepth = CV_16S;
			int c;
			src = image;
			/// 使用高斯滤波消除噪声
			GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
			/// 转换为灰度图
			cvtColor(src, src_gray, COLOR_BGR2GRAY);
			/// 使用Laplace函数
			Mat abs_dst;
			Laplacian(src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
			convertScaleAbs(dst, abs_dst);
			image1 = abs_dst;
			QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
			label = new QLabel();
			label->setPixmap(QPixmap::fromImage(img));
			label->resize(QSize(img.width(), img.height()));
			ui.scrollArea_open32->setWidget(label);

		}
		else
		{
			QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
			//dialog1.changetext2();
			//dialog1.show();
			//dialog1.exec();
			return;
		}
		break;

	case 33:
		i_by = atoi(ui.lineEdit31->text().toStdString().c_str());
		if (i_by > 0)
		{
			Mat src, src_gray;
			Mat dst, detected_edges;

			int edgeThresh = 1;
			int lowThreshold;
			int const max_lowThreshold = 100;
			int ratio = 3;
			int kernel_size = 3;
			src = image;
			dst.create(src.size(), src.type());

				/// 原图像转换为灰度图像
			cvtColor(src, src_gray, COLOR_BGR2GRAY);
			blur(src_gray, detected_edges, Size(3, 3));
			lowThreshold = i_by;
			/// 运行Canny算子
			Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);

			/// 使用 Canny算子输出边缘作为掩码显示原图像
			dst = Scalar::all(0);

			src.copyTo(dst, detected_edges);
			image1 = dst;
			QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
			label = new QLabel();
			label->setPixmap(QPixmap::fromImage(img));
			label->resize(QSize(img.width(), img.height()));
			ui.scrollArea_open32->setWidget(label);

		}
		else
		{
			QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
			//dialog1.changetext2();
			//dialog1.show();
			//dialog1.exec();
			return;
		}
		break;
	case 34:
		i_by = atoi(ui.lineEdit31->text().toStdString().c_str());
		if (i_by > 0)
		{
			Mat src, src_gray;
			Mat dst, detected_edges,cdst;


			int edgeThresh = 1;
			int lowThreshold;
			int const max_lowThreshold = 100;
			int ratio = 3;
			int kernel_size = 3;
			src = image;
			dst.create(src.size(), src.type());

			/// 原图像转换为灰度图像
			cvtColor(src, src_gray, COLOR_BGR2GRAY);
			blur(src_gray, detected_edges, Size(3, 3));
			lowThreshold = i_by;
			/// 运行Canny算子
			Canny(detected_edges, detected_edges, 50, 200, 3);

			/// 使用 Canny算子输出边缘作为掩码显示原图像
			dst = Scalar::all(0);

			src.copyTo(dst, detected_edges);
			//以上过程完成边缘检测
			cvtColor(dst, cdst, COLOR_BGR2GRAY);

			std::vector<Vec2f> lines;
			/*
			HoughLines(dst, lines, 1, 3.14 / 180, 100, 0, 0);

			for (size_t i = 0; i < lines.size(); i++)
			{
				float rho = lines[i][0], theta = lines[i][1];
				Point pt1, pt2;
				double a = cos(theta), b = sin(theta);
				double x0 = a * rho, y0 = b * rho;
				pt1.x = cvRound(x0 + 1000 * (-b));
				pt1.y = cvRound(y0 + 1000 * (a));
				pt2.x = cvRound(x0 - 1000 * (-b));
				pt2.y = cvRound(y0 - 1000 * (a));
				line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, LINE_AA);
			}

			*/
			image1 = dst;
			QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
			label = new QLabel();
			label->setPixmap(QPixmap::fromImage(img));
			label->resize(QSize(img.width(), img.height()));
			ui.scrollArea_open32->setWidget(label);

		}
		else
		{
			QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
			//dialog1.changetext2();
			//dialog1.show();
			//dialog1.exec();
			return;
		}
		break;
	case 36:
		i_by = atoi(ui.lineEdit31->text().toStdString().c_str());
		if (1)
		{
			Mat src, src_gray;
			Mat dst, detected_edges, cdst,canny_output;
			int edgeThresh = 1;
			int lowThreshold;
			int const max_lowThreshold = 100;
			int ratio = 3;
			int kernel_size = 3;
			RNG rng(12345);
			src = image;
			dst.create(src.size(), src.type());

			/// 原图像转换为灰度图像
			cvtColor(src, src_gray, COLOR_BGR2GRAY);
			blur(src_gray, detected_edges, Size(3, 3));
			lowThreshold = i_by;
			/// 运行Canny算子
			Canny(src_gray, canny_output, 100, 200, 3);

			/// 使用 Canny算子输出边缘作为掩码显示原图像
			//Mat canny_output;
			std::vector<std::vector<Point> > contours;
			std::vector<Vec4i> hierarchy;
			findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

			/// 绘出轮廓
			Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
			for (int i = 0; i < contours.size(); i++)
			{
				Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
				drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
			}

			image1 = drawing;
			QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
			label = new QLabel();
			label->setPixmap(QPixmap::fromImage(img));
			label->resize(QSize(img.width(), img.height()));
			ui.scrollArea_open32->setWidget(label);

		}
		else
		{
			QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
			//dialog1.changetext2();
			//dialog1.show();
			//dialog1.exec();
			return;
		}
		break;
	default:
		break;
	}

}
int Hi_Opencv::on_sobel_show()
{
	//改功能可能存在的bug输入的数值范围可能会引起内存溢出；
	i = 31;
	ui.label_by1->setText("sobel");
	ui.label_31->show();
	ui.lineEdit31->show();
	return i;
}
int Hi_Opencv::on_laplace_show()
{
	i = 32;
	ui.label_by1->setText("Laplace");
	ui.label_31->show();
	ui.lineEdit31->show();
	return i;
}
int Hi_Opencv::on_canny_show()
{
	i = 33;
	ui.label_by1->setText("Canny");
	ui.label_31->show();
	ui.lineEdit31->show();


	return i;
}
int Hi_Opencv::on_HoughLine_show()
{
	i = 34;
	ui.label_by1->setText("HoughLine");
	ui.label_31->show();
	ui.lineEdit31->show();


	return i;
}
int Hi_Opencv::on_HoughCircle_show()
{
	i = 33;
	ui.label_by1->setText("Canny operation");
	ui.label_31->show();
	ui.lineEdit31->show();


	return i;
}
int Hi_Opencv::on_findContours_show()
{
	i = 36;
	ui.label_by1->setText("findContour");
	//ui.label_31->show();
	//ui.lineEdit31->show();


	return i;
}
int Hi_Opencv::on_findContoursLength_show()
{
	i = 33;
	ui.label_by1->setText("Canny operation");
	ui.label_31->show();
	ui.lineEdit31->show();


	return i;
}