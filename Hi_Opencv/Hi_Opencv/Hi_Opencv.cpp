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

