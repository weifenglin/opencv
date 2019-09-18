#include "Hi_Opencv.h"
#include <QDebug>
#include <qmessagebox.h>

Hi_Opencv::Hi_Opencv(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.label_in->setStyleSheet("border:2px solid black;");
	ui.label_out->setStyleSheet("border:2px solid black;");
	ui.label_in_2->setStyleSheet("border:2px solid black;");
	ui.label_out_2->setStyleSheet("border:2px solid black;");
	ui.label_in_5->setStyleSheet("border:2px solid black;");
	ui.label_out_5->setStyleSheet("border:2px solid black;");
	ui.label_in_original->setStyleSheet("border:2px solid black;");
	ui.label_in_templat->setStyleSheet("border:2px solid black;");
	ui.label_out_result->setStyleSheet("border:2px solid black;");
	ui.label_in_3->setStyleSheet("border:2px solid black;");
	ui.label_out_3->setStyleSheet("border:2px solid black;");

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
	//边缘检测
	ui.label_31->hide();
	ui.lineEdit31->hide();

	w3Initial();

}

int Hi_Opencv::image_fit(Mat a, double m, double n)
{
	double h = a.rows;
	double w = a.cols;
	double p = h / w;
	double q = m / n;
	if (p > q)
	{
		t = m / h;
	}
	else
	{
		t = n / w;
	}
	return t;
}


///QString转String
String qstr2str(QString qstr)
{
	QByteArray cdata = qstr.toLocal8Bit();
	return String(cdata);
}

void Hi_Opencv::on_open()
{
	ui.label_in->setStyleSheet("border:2px solid black;");
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
		
		double m = ui.label_in->height();
		double n = ui.label_in->width();
		image_fit(image, m, n);
		h1 = image.rows * t;
		w1 = image.cols* t;
		cv::resize(image, image, Size(w1, h1));
	
	}
		//cvtColor(image, image, COLOR_BGR2RGB);
		//cv::resize(image, image, Size(300, 200));
		QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows,image.cols*image.channels(), QImage::Format_RGB888);
		ui.label_in->setPixmap(QPixmap::fromImage(img));
		ui.label_in->resize(QSize(img.width(), img.height()));
		ui.pushButton_start->setEnabled(true);
		ui.label_out->clear();
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
	ui.lineEdit_w->clear();
	ui.lineEdit_h->clear();
	ui.lineEdit_i->clear();
	//cv::resize(image1, image1, Size(w1, h1));
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image.channels(), QImage::Format_RGB888);
	ui.label_out->setPixmap(QPixmap::fromImage(img));
	ui.label_out->resize(QSize(img.width(), img.height()));
	}

int Hi_Opencv::on_blur_show()
{
	i = 1;
	ui.label_out->clear();
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
	ui.label_out->clear();
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
	ui.label_out->clear();
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
	ui.label_out->clear();
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
		//cv::resize(image, image, Size(300, 200));
		double m = ui.label_in_2->height();
		double n = ui.label_in_2->width();
		image_fit(image, m, n);
		h1 = image.rows * t;
		w1 = image.cols* t;
		cv::resize(image, image, Size(w1, h1));
		QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, image.cols*image.channels(), QImage::Format_RGB888);
		ui.label_in_2->setPixmap(QPixmap::fromImage(img));
		ui.label_in_2->resize(QSize(img.width(), img.height()));
		ui.pushButton_start_2->setEnabled(true);
		ui.label_out_2->clear();
	}
}

int Hi_Opencv::on_erode_show()
{
	i = 1;
	ui.label_out_2->clear();
	ui.label_title->setText("Erode");
	ui.widget_3->hide();
	/*ui.radioButton_RECT->setEnabled(true);
	ui.radioButton_CROSS->setEnabled(true);
	ui.radioButton_ELLIPSE->setEnabled(true);*/
	ui.lineEdit_size->setText("");
	ui.widget->show();
	ui.label_size->setText("erosion_size:");
	ui.widget_2->show();
	return i;
}

int Hi_Opencv::on_dilate_show()
{
	i = 2;
	ui.label_out_2->clear();
	ui.widget_3->hide();
	ui.label_title->setText("Dilate");
	/*ui.radioButton_RECT->setEnabled(true);
	ui.radioButton_CROSS->setEnabled(true);
	ui.radioButton_ELLIPSE->setEnabled(true);*/
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
	ui.label_out_2->clear();
	/*ui.radioButton_RECT->setEnabled(true);
	ui.radioButton_CROSS->setEnabled(true);
	ui.radioButton_ELLIPSE->setEnabled(true);
	ui.radioButton_opening->setEnabled(true);
	ui.radioButton_closing->setEnabled(true);
	ui.radioButton_gradient->setEnabled(true);
	ui.radioButton_top->setEnabled(true);
	ui.radioButton_black->setEnabled(true);*/

	ui.lineEdit_size->setText("");
	ui.widget->show();
	ui.widget_3->show();
	ui.label_size->setText("morph_size:");
	ui.widget_2->show();
	return i;
}

void Hi_Opencv::on_form_RECT()
{
	/*ui.radioButton_CROSS->setEnabled(false);
	ui.radioButton_ELLIPSE->setEnabled(false);*/
	j = MORPH_RECT;
}

void Hi_Opencv::on_form_CROSS()
{
	/*ui.radioButton_RECT->setEnabled(false);
	ui.radioButton_ELLIPSE->setEnabled(false);*/
	j = MORPH_CROSS;
}

void Hi_Opencv::on_form_ELLIPSE()
{
	/*ui.radioButton_CROSS->setEnabled(false);
	ui.radioButton_RECT->setEnabled(false);*/
	j = MORPH_ELLIPSE;

}

void Hi_Opencv::on_opening()
{
	/*ui.radioButton_closing->setEnabled(false);
	ui.radioButton_gradient->setEnabled(false);
	ui.radioButton_top->setEnabled(false);
	ui.radioButton_black->setEnabled(false);*/
	m = MORPH_OPEN;
}

void Hi_Opencv::on_closing()
{
	/*ui.radioButton_opening->setEnabled(false);
	ui.radioButton_gradient->setEnabled(false);
	ui.radioButton_top->setEnabled(false);
	ui.radioButton_black->setEnabled(false);*/
	m = MORPH_CLOSE;
}

void Hi_Opencv::on_gradient()
{
	/*ui.radioButton_closing->setEnabled(false);
	ui.radioButton_opening->setEnabled(false);
	ui.radioButton_top->setEnabled(false);
	ui.radioButton_black->setEnabled(false);*/
	m = MORPH_GRADIENT;
}

void Hi_Opencv::on_top()
{
	/*ui.radioButton_closing->setEnabled(false);
	ui.radioButton_gradient->setEnabled(false);
	ui.radioButton_opening->setEnabled(false);
	ui.radioButton_black->setEnabled(false);*/
	m = MORPH_TOPHAT;
}

void Hi_Opencv::on_black()
{
	/*ui.radioButton_closing->setEnabled(false);
	ui.radioButton_gradient->setEnabled(false);
	ui.radioButton_top->setEnabled(false);
	ui.radioButton_opening->setEnabled(false);*/
	m = MORPH_BLACKHAT;
}

void Hi_Opencv::on_start_2()
{
	switch (i)
	{
	case 1:
	{
		k = atoi(ui.lineEdit_size->text().toStdString().c_str());
		if (k > 0)
		{
		Mat element = getStructuringElement(j, Size(2 * k + 1, 2 * k + 1), Point(k, k));
		cv::erode(image, image1, element);
		/*QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
		ui.label_out_2->setPixmap(QPixmap::fromImage(img));
		ui.label_out_2->resize(QSize(img.width(), img.height()));*/
		/*ui.radioButton_RECT->setEnabled(true);
		ui.radioButton_CROSS->setEnabled(true);
		ui.radioButton_ELLIPSE->setEnabled(true);*/
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

			/*QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
			ui.label_out_2->setPixmap(QPixmap::fromImage(img));
			ui.label_out_2->resize(QSize(img.width(), img.height()));*/

			/*ui.radioButton_RECT->setEnabled(true);
			ui.radioButton_CROSS->setEnabled(true);
			ui.radioButton_ELLIPSE->setEnabled(true);*/
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

			/*QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
			ui.label_out_2->setPixmap(QPixmap::fromImage(img));
			ui.label_out_2->resize(QSize(img.width(), img.height()));*/
			/*ui.radioButton_RECT->setEnabled(true);
			ui.radioButton_CROSS->setEnabled(true);
			ui.radioButton_ELLIPSE->setEnabled(true);
			ui.radioButton_opening->setEnabled(true);
			ui.radioButton_closing->setEnabled(true);
			ui.radioButton_gradient->setEnabled(true);
			ui.radioButton_top->setEnabled(true);
			ui.radioButton_black->setEnabled(true);*/
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
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image.channels(), QImage::Format_RGB888);
	ui.label_out_2->setPixmap(QPixmap::fromImage(img));
	ui.label_out_2->resize(QSize(img.width(), img.height()));

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


		double labelWidth, labelHeight, imageWidth, imageHeight;
		labelWidth = ui.w3Label->width();
		labelHeight = ui.w3Label->height();
		imageWidth = image.cols;
		imageHeight = image.rows;


		//图片适应label方法
		int newWidth, newHeight;
		double proportionL, proportionI;
		proportionL = labelWidth / labelHeight;
		proportionI = imageWidth / imageHeight;
		if (proportionI > proportionL)      //image的宽高比比较大，按照宽度伸缩
		{
			double proportion = labelWidth / imageWidth;
			newWidth = image.cols * proportion;
			newHeight = image.rows * proportion;
		}
		else
		{
			double proportion = labelHeight / imageHeight;
			newWidth = image.cols * proportion;
			newHeight = image.rows * proportion;
		}

		cv::resize(image, image, Size(newWidth, newHeight));

		QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);

		//label_in = new QLabel();
		ui.w3Label->setPixmap(QPixmap::fromImage(img));
		ui.w3Label->setAlignment(Qt::AlignCenter);
		//ui.w3Label->resize(QSize(img.width(), img.height()));
		//ui.label_in->show();
		//ui.pushButton_start->setEnabled(true);
		ui.w3btnDown->setEnabled(true);
		ui.w3btnUp->setEnabled(true);
		ui.pushButton_2->setEnabled(true);
		ui.pushButton_6->setEnabled(true);
		ui.w3btnFS->setEnabled(true);
		ui.w3btnTS->setEnabled(true);
		ui.w3btnRotate->setEnabled(true);
		//w3Initial();
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

void  Hi_Opencv::w3Initial()
{
	//ui.label_i->hide();
	ui.w3lbl1->hide();
	ui.w3lbl2->hide();
	ui.w3lbl3->hide();
	ui.w3lblP1->hide();
	ui.w3lblP2->hide();
	ui.w3lblP3->hide();
	ui.w3lblP4->hide();
	ui.w3Linex1->hide();
	ui.w3Linex2->hide();
	ui.w3Linex3->hide();
	ui.w3Linex4->hide();
	ui.w3Liney1->hide();
	ui.w3Liney2->hide();
	ui.w3Liney3->hide();
	ui.w3Liney4->hide();
	ui.w3lblRotate->hide();
	ui.w3lblSize->hide();
	ui.w3Line1->hide();
	ui.w3Line2->hide();
}

int Hi_Opencv::w3btnFSClicked()
{
	i = 1;
	w3Initial();
	ui.w3lbl1->show();
	ui.w3lbl2->show();
	ui.w3lbl3->show();
	ui.w3lblP1->show();
	ui.w3lblP2->show();
	ui.w3lblP3->show();

	ui.w3Linex1->show();
	ui.w3Linex2->show();
	ui.w3Linex3->show();

	ui.w3Liney1->show();
	ui.w3Liney2->show();
	ui.w3Liney3->show();

	string temp, temp1, temp2;
	temp1 = to_string(image.cols - 1);
	temp2 = to_string(image.rows - 1);

	temp = "(0,0)";
	ui.w3lblP1->setText(QString::fromStdString(temp));
	temp = "(0," + temp1 + ")";
	ui.w3lblP2->setText(QString::fromStdString(temp));
	temp = "(" + temp2 + ",0)";
	ui.w3lblP3->setText(QString::fromStdString(temp));
	
	ui.w3btnStart->setEnabled(true);
	return i;
}

int Hi_Opencv::w3btnRotateClicked()
{
	i = 2;
	w3Initial();

	ui.w3lblRotate->show();
	ui.w3lblSize->show();
	ui.w3Line1->show();
	ui.w3Line2->show();

	ui.w3btnStart->setEnabled(true);
	return i;
}

int Hi_Opencv::w3btnTSClicked()
{
	i = 3;
	i = 1;
	w3Initial();
	ui.w3lbl1->show();
	ui.w3lbl2->show();
	ui.w3lbl3->show();
	ui.w3lblP1->show();
	ui.w3lblP2->show();
	ui.w3lblP3->show();
	ui.w3lblP4->show();

	ui.w3Linex1->show();
	ui.w3Linex2->show();
	ui.w3Linex3->show();
	ui.w3Linex4->show();

	ui.w3Liney1->show();
	ui.w3Liney2->show();
	ui.w3Liney3->show();
	ui.w3Liney4->show();

	string temp, temp1, temp2;
	temp1 = to_string(image.rows - 1);
	temp2 = to_string(image.rows - 1);

	temp = "(0,0)";
	ui.w3lblP1->setText(QString::fromStdString(temp));
	temp = "(0," + temp1 + ")";
	ui.w3lblP2->setText(QString::fromStdString(temp));
	temp = "(" + temp2 + ",0)";
	ui.w3lblP3->setText(QString::fromStdString(temp));
	//temp1 = to_string(image.cols / 2);
	temp = "(" + temp2 + "," + temp1 + ")";
	ui.w3lblP4->setText(QString::fromStdString(temp));

	ui.w3btnStart->setEnabled(true);
	return i;
}

void Hi_Opencv::w3btnStartClicked()
{
	try
	{
		switch(i) 
		{
			case 1:
			{
				Point2f srcTri[3];
				Point2f dstTri[3];

				//Mat rot_mat(2, 3, CV_32FC1);
				Mat warp_mat(2, 3, CV_32FC1);
				//Mat warp_rotate_dst;

				/// 设置目标图像的大小和类型与源图像一致
				//warp_dst = Mat::zeros(src.rows, src.cols, src.type());

				/// 设置源图像和目标图像上的三组点以计算仿射变换
				srcTri[0] = Point2f(0, 0);
				srcTri[1] = Point2f(0, image.cols - 1);
				srcTri[2] = Point2f(image.rows - 1, 0);

				dstTri[0] = Point2f(ui.w3Linex1->text().toFloat(), ui.w3Liney1->text().toFloat());
				dstTri[1] = Point2f(ui.w3Linex2->text().toFloat(), ui.w3Liney2->text().toFloat());
				dstTri[2] = Point2f(ui.w3Linex3->text().toFloat(), ui.w3Liney3->text().toFloat());

				/// 求得仿射变换
				warp_mat = getAffineTransform(srcTri, dstTri);

				/// 对源图像应用上面求得的仿射变换
				warpAffine(image, image, warp_mat, image.size());

				QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);


				//label_in = new QLabel();
				ui.w3Label->setPixmap(QPixmap::fromImage(img));
				ui.w3Label->setAlignment(Qt::AlignCenter); 

				break;
			}
			case 2:
			{
				Mat rot_mat(2, 3, CV_32FC1);

				Point center = Point(image.cols / 2, image.rows / 2);
				//double angle = atof(ui.w3Linex1->text().toStdString().c_str());
				//float anglw1 = ui.w3Line1->text().toDouble();

				double angle = ui.w3Line1->text().toDouble();
				double scale = ui.w3Line2->text().toDouble();

				/// 通过上面的旋转细节信息求得旋转矩阵
				rot_mat = getRotationMatrix2D(center, angle, scale);

				/// 旋转已扭曲图像
				warpAffine(image, image, rot_mat, image.size());

				QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);
				//label_in = new QLabel();
				ui.w3Label->setPixmap(QPixmap::fromImage(img));
				ui.w3Label->setAlignment(Qt::AlignCenter);

				break;
	
			}
			case 3:
			{
				Point2f srcTri[4], dstTri[4];
				//创建数组指针
				Mat warp_mat(3, 3, CV_32FC1);

				Mat dst;
				//载入和显示图像
				//src = cvLoadImage("1.jpg", CV_LOAD_IMAGE_UNCHANGED);
				//cvNamedWindow("原图", CV_WINDOW_AUTOSIZE);
				//cvShowImage("原图", src);

				//dst = cvCloneImage(src);
				//dst->origin = src->origin;
				//cvZero(dst);
				//构造变换矩阵
				srcTri[0] = Point2f(0, 0);
				srcTri[1] = Point2f(image.cols - 1, 0);
				srcTri[2] = Point2f(0, image.rows - 1);
				srcTri[3] = Point2f(image.cols - 1, image.rows - 1);

				dstTri[0] = Point2f(ui.w3Linex1->text().toFloat(), ui.w3Liney1->text().toFloat());
				dstTri[1] = Point2f(ui.w3Linex2->text().toFloat(), ui.w3Liney2->text().toFloat());
				dstTri[2] = Point2f(ui.w3Linex3->text().toFloat(), ui.w3Liney3->text().toFloat());
				dstTri[3] = Point2f(ui.w3Linex3->text().toFloat(), ui.w3Liney3->text().toFloat());
				//计算透视映射矩阵
				warp_mat = getPerspectiveTransform(srcTri, dstTri);
				//调用函数cvWarpPerspective（）
				warpPerspective(image, image, warp_mat, image.size());

				QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);
				//label_in = new QLabel();
				ui.w3Label->setPixmap(QPixmap::fromImage(img));
				ui.w3Label->setAlignment(Qt::AlignCenter);

				break;
			}
		default:
			break;
		}
	}
	catch (...)
	{

		QMessageBox::warning(this, "warning", "wrong data!");
		return;
	}
}

//目标定位
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
		

		double m = ui.label_in_5->height();
		double n = ui.label_in_5->width();
		image_fit(image, m, n);
		h1 = image.rows * t;
		w1 = image.cols* t;
		cv::resize(image, image, Size(w1, h1));

		cvtColor(image, image3, COLOR_BGR2RGB);
		cvtColor(image, image2, COLOR_BGR2GRAY);
		//cv::resize(image2, image2, Size(300, 200));
		//cv::resize(image3, image3, Size(300, 200));
//		ui.pushButton_start_5->setEnabled("false");
		QImage img = QImage((const unsigned char*)(image3.data), image3.cols, image3.rows, image3.cols*image.channels(), QImage::Format_RGB888);

		ui.label_in_5->setPixmap(QPixmap::fromImage(img));
		ui.label_in_5->resize(QSize(img.width(), img.height()));
		ui.label_out_5->clear();
	}
}

void Hi_Opencv::on_convexHull()
{
	i = 1;
	ui.label_out_5->clear();
	ui.label_19->setText("convexHull");

}

void Hi_Opencv::on_rectcircle()
{
	i = 2;
	ui.label_out_5->clear();
	ui.label_19->setText("rectcircle");

}

void Hi_Opencv::on_fitEllipse()
{
	i = 3;
	ui.label_out_5->clear();
	ui.label_19->setText("fitEllipse");
}

void Hi_Opencv::on_start_5()
{
	switch (i)
	{
	case 1:
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
		QImage img1 = QImage((const unsigned char*)(drawing.data), drawing.cols, drawing.rows, drawing.cols*image.channels(), QImage::Format_RGB888);
		ui.label_out_5->setPixmap(QPixmap::fromImage(img1));
		ui.label_out_5->resize(QSize(img1.width(), img1.height()));
		break;
	}
	case 2:
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
		QImage img1 = QImage((const unsigned char*)(drawing.data), drawing.cols, drawing.rows, drawing.cols*image.channels(), QImage::Format_RGB888);
		ui.label_out_5->setPixmap(QPixmap::fromImage(img1));
		ui.label_out_5->resize(QSize(img1.width(), img1.height()));
		break;
	}
	case 3:
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
			QImage img1 = QImage((const unsigned char*)(drawing.data), drawing.cols, drawing.rows, drawing.cols*drawing.channels(), QImage::Format_RGB888);
			ui.label_out_5->setPixmap(QPixmap::fromImage(img1));
			ui.label_out_5->resize(QSize(img1.width(), img1.height()));
		}
		break;
	}
	default:
		break;
	}

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

		double m = ui.label_in_original->height();
		double n = ui.label_in_original->width();
		image_fit(image, m, n);
		h1 = image.rows * t;
		w1 = image.cols* t;
		t1 = t;
		cv::resize(image, image, Size(w1, h1));

		cvtColor(image, image2, COLOR_BGR2RGB);
		//cv::resize(image2, image2, Size(300, 200));
		QImage img = QImage((const unsigned char*)(image2.data), image2.cols, image2.rows, image2.cols*image2.channels(), QImage::Format_RGB888);
		ui.label_in_original->setPixmap(QPixmap::fromImage(img));
		ui.label_in_original->resize(QSize(img.width(), img.height()));
		ui.label_in_templat->clear();
		ui.label_out_result->clear();
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
		image4 = image1;
		int h2 = image4.rows*t1;
		int w2 = image4.cols*t1;
		cv::resize(image4, image4, Size(w2, h2));

		/*double m = ui.label_in_templat->height();
		double n = ui.label_in_templat->width();
		image_fit(image1, m, n);
		h1 = image1.rows * t;
		w1 = image1.cols* t;
		cv::resize(image1, image1, Size(w1, h1));*/

		cvtColor(image4, image4, COLOR_BGR2RGB);
		QImage img = QImage((const unsigned char*)(image4.data), image4.cols, image4.rows, image4.cols*image4.channels(), QImage::Format_RGB888);
		ui.label_in_templat->setPixmap(QPixmap::fromImage(img));
		ui.label_in_templat->resize(QSize(img.width(), img.height()));
		ui.label_out_result->clear();
	}
}

void Hi_Opencv::on_method1()
{
	ui.pushButton_match->setEnabled(true);
	match_method = TM_SQDIFF;
	/*ui.radioButton_method2->setEnabled(false);
	ui.radioButton_method3->setEnabled(false);
	ui.radioButton_method4->setEnabled(false);
	ui.radioButton_method5->setEnabled(false);
	ui.radioButton_method6->setEnabled(false);*/
}

void Hi_Opencv::on_method2()
{
	ui.pushButton_match->setEnabled(true);
	match_method = TM_SQDIFF_NORMED;
	/*ui.radioButton_method1->setEnabled(false);
	ui.radioButton_method3->setEnabled(false);
	ui.radioButton_method4->setEnabled(false);
	ui.radioButton_method5->setEnabled(false);
	ui.radioButton_method6->setEnabled(false);*/
}

void Hi_Opencv::on_method3()
{
	ui.pushButton_match->setEnabled(true);
	match_method = TM_CCORR;
	/*ui.radioButton_method2->setEnabled(false);
	ui.radioButton_method1->setEnabled(false);
	ui.radioButton_method4->setEnabled(false);
	ui.radioButton_method5->setEnabled(false);
	ui.radioButton_method6->setEnabled(false);*/
}

void Hi_Opencv::on_method4()
{
	ui.pushButton_match->setEnabled(true);
	match_method = TM_CCORR_NORMED;
	/*ui.radioButton_method2->setEnabled(false);
	ui.radioButton_method3->setEnabled(false);
	ui.radioButton_method1->setEnabled(false);
	ui.radioButton_method5->setEnabled(false);
	ui.radioButton_method6->setEnabled(false);*/
}

void Hi_Opencv::on_method5()
{
	ui.pushButton_match->setEnabled(true);
	match_method = TM_CCOEFF;
	/*ui.radioButton_method2->setEnabled(false);
	ui.radioButton_method3->setEnabled(false);
	ui.radioButton_method4->setEnabled(false);
	ui.radioButton_method1->setEnabled(false);
	ui.radioButton_method6->setEnabled(false);*/
}

void Hi_Opencv::on_method6()
{
	ui.pushButton_match->setEnabled(true);
	match_method = TM_CCOEFF_NORMED;
	/*ui.radioButton_method2->setEnabled(false);
	ui.radioButton_method3->setEnabled(false);
	ui.radioButton_method4->setEnabled(false);
	ui.radioButton_method5->setEnabled(false);
	ui.radioButton_method1->setEnabled(false);*/
}


void Hi_Opencv::on_match()
{
	/*ui.radioButton_method1->setEnabled(true);
	ui.radioButton_method2->setEnabled(true);
	ui.radioButton_method3->setEnabled(true);
	ui.radioButton_method4->setEnabled(true);
	ui.radioButton_method5->setEnabled(true);
	ui.radioButton_method6->setEnabled(true);*/
	
	//cv::resize(image3, image4, Size(25, 22));
	Mat image_display;
	image2.copyTo(image_display);

	int result_cols = image2.cols - image4.cols + 1;
	int result_rows = image2.rows - image4.rows + 1;

	result.create(result_cols, result_rows, CV_32FC1);
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

	QImage img3 = QImage((const unsigned char*)(image_display.data), image_display.cols, image_display.rows, image_display.cols*image_display.channels(), QImage::Format_RGB888);
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

		double m = ui.label_in_3->height();
		double n = ui.label_in_3->width();
		image_fit(image, m, n);
		h1 = image.rows * t;
		w1 = image.cols* t;
		cv::resize(image, image, Size(w1, h1));

		cvtColor(image, image2, COLOR_BGR2RGB);
		//cv::resize(image2, image2, Size(300, 200));
		QImage img = QImage((const unsigned char*)(image2.data), image2.cols, image2.rows,image2.cols*image2.channels(), QImage::Format_RGB888);

		ui.label_in_3->setPixmap(QPixmap::fromImage(img));
		ui.label_in_3->resize(QSize(img.width(), img.height()));
		ui.label_out_3->clear();

	}
}

void Hi_Opencv::on_threshold()
{
	ui.pushButton_open_7->show();
	ui.widget_5->hide();
	ui.widget_4->show();
	ui.spinBox_type->setValue(0);
	ui.horizontalSlider_value->setValue(0);
	ui.label_out_3->clear();

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
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image1.channels(), QImage::Format_RGB888);
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
	ui.label_out_3->clear();
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
	cv::resize(image, image1, Size(w1-left-right,h1-top-right));
	copyMakeBorder(image1, image1, top, bottom, left, right, j, value);

	cvtColor(image1, image1, COLOR_BGR2RGB);
	//cv::resize(image1, image1, Size(300, 200));
	QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, image1.cols*image1.channels(), QImage::Format_RGB888);
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
	//cv::resize(src, src, Size(300, 200));
	QImage img = QImage((const unsigned char*)(src.data), src.cols, src.rows, QImage::Format_RGB888);
	ui.label_in_3->setPixmap(QPixmap::fromImage(img));
	ui.label_in_3->resize(QSize(img.width(), img.height()));

	QImage img1 = QImage((const unsigned char*)(drawing.data), drawing.cols, drawing.rows, QImage::Format_RGB888);
	ui.label_out_3->setPixmap(QPixmap::fromImage(img1));
	ui.label_out_3->resize(QSize(img1.width(), img1.height()));
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
		//QLabel *label = new QLabel();
		ui.label_in_4->setPixmap(QPixmap::fromImage(img));
		ui.label_in_4->resize(QSize(img.width(), img.height()));
		ui.pushButton_open_3->setEnabled(true);
	}
}

Mat img1,src_gray, grad;
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
			cvtColor(image1,image1,COLOR_GRAY2BGR);

			QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
			ui.label_out_4->setPixmap(QPixmap::fromImage(img));
			ui.label_out_4->resize(QSize(img.width(), img.height()));
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
			cvtColor(image1, image1, COLOR_GRAY2BGR);
			QImage img = QImage((const unsigned char*)(image1.data), image1.cols, image1.rows, QImage::Format_RGB888);
			ui.label_out_4->setPixmap(QPixmap::fromImage(img));
			ui.label_out_4->resize(QSize(img.width(), img.height()));

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
			ui.label_out_4->setPixmap(QPixmap::fromImage(img));
			ui.label_out_4->resize(QSize(img.width(), img.height()));

		}
		else
		{
			QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
			return;
		}
		break;
	case 34:
		i_by = atoi(ui.lineEdit31->text().toStdString().c_str());
		if (i_by > 0)
		{
			Mat src, src_gray;
			Mat dst, cdst;

			src = image;
			cvtColor(src, src_gray, COLOR_BGR2GRAY);
			Canny(src_gray, dst, i_by, 200 ,3);
			cvtColor(dst, cdst, COLOR_GRAY2BGR);

			/*vector<Vec2f> lines;
			HoughLines(dst, lines, 1, 3.1415926 / 180, 100, 0, 0);

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
				line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, 8);
				*/
			vector<Vec4i> lines;
			HoughLinesP(dst, lines, 1, CV_PI / 180, 50, 50, 10);
			for (size_t i = 0; i < lines.size(); i++)
			{
				Vec4i l = lines[i];
				line(cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, LINE_AA);
			}

			QImage img = QImage((const unsigned char*)(cdst.data), cdst.cols, cdst.rows, QImage::Format_RGB888);
			ui.label_out_4->setPixmap(QPixmap::fromImage(img));
			ui.label_out_4->resize(QSize(img.width(), img.height()));

		}
		else
		{
			QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
			return;
		}
		break;

	case 35:
	{
		i_by = atoi(ui.lineEdit31->text().toStdString().c_str());
		if (i_by > 0)
		{
			Mat src, src_gray;
			//i_by = atoi(ui.lineEdit31->text().toStdString().c_str());
			src = image;
			cvtColor(src, src_gray, COLOR_BGR2GRAY);

			//GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);

			vector<Vec3f> circles;

			/// Apply the Hough Transform to find the circles
			HoughCircles(src_gray, circles, HOUGH_GRADIENT, 1, src_gray.rows / 8, i_by, 100, 0, 0);

			for (int i = 0; i < circles.size(); i++)
			{
				Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
				int radius = cvRound(circles[i][2]);
				// circle center
				circle(src, center, 3, Scalar(0, 255, 0), -1, 8, 0);
				// circle outline
				circle(src, center, radius, Scalar(0, 0, 255), 3, 8, 0);
			}

			QImage img = QImage((const unsigned char*)(src.data), src.cols, src.rows, QImage::Format_RGB888);
			ui.label_out_4->setPixmap(QPixmap::fromImage(img));
			ui.label_out_4->resize(QSize(img.width(), img.height()));
		}
		else
		{
			QMessageBox::warning(this, "warning", "Incorrect input,Please enter positive  number");
			return;
		}
		break;
	}

	case 36:
		i_by = atoi(ui.lineEdit31->text().toStdString().c_str());
		if ( i_by > 0 )
		{
			Mat src, src_gray,canny_output;
			RNG rng(12345);
			src = image;
			/// 原图像转换为灰度图像
			cvtColor(src, src_gray, COLOR_BGR2GRAY);;
			/// 运行Canny算子
			Canny(src_gray, canny_output, i_by, 200, 3);

			/// 使用 Canny算子输出边缘作为掩码显示原图像
			vector<vector<Point> > contours;
			vector<Vec4i> hierarchy;
			findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

			//计算矩：
			vector<Moments> mu(contours.size());
			for (int i = 0; i < contours.size(); i++)
			{
				mu[i] = moments(contours[i], false);
			}

			///  计算中心矩:
			vector<Point2f> mc(contours.size());
			for (int i = 0; i < contours.size(); i++)
			{
				mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
			}

			/// 绘出轮廓
			Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
			for (int i = 0; i < contours.size(); i++)
			{
				Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
				drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
				circle(drawing, mc[i], 4, color, -1, 8, 0);
			}
			QImage img = QImage((const unsigned char*)(drawing.data), drawing.cols, drawing.rows, QImage::Format_RGB888);
			ui.label_out_4->setPixmap(QPixmap::fromImage(img));
			ui.label_out_4->resize(QSize(img.width(), img.height()));

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
	//改功能可能存在的bug输入的数值范围可能会引起内存溢出；
	i = 31;
	ui.label_by1->setText("sobel");
	ui.label_31->show();
	ui.lineEdit31->show();
	ui.lineEdit31->setText("");
	return i;
}
int Hi_Opencv::on_laplace_show()
{
	i = 32;
	ui.label_by1->setText("Laplace");
	ui.label_31->show();
	ui.lineEdit31->show();
	ui.lineEdit31->setText("");
	return i;
}
int Hi_Opencv::on_canny_show()
{
	i = 33;
	ui.label_by1->setText("Canny");
	ui.label_31->show();
	ui.lineEdit31->show();
	ui.lineEdit31->setText("");

	return i;
}
int Hi_Opencv::on_HoughLine_show()
{
	i = 34;
	ui.label_by1->setText("HoughLine");
	ui.label_31->show();
	ui.lineEdit31->show();
	ui.lineEdit31->setText("");
	return i;
}
int Hi_Opencv::on_HoughCircle_show()
{
	i = 35;
	ui.label_by1->setText("HoughCircle");
	ui.label_31->show();
	ui.lineEdit31->show();
	ui.lineEdit31->setText("");
	return i;
}

int Hi_Opencv::on_findContoursLength_show()
{
	i = 36;
	ui.label_by1->setText("Canny operation");
	ui.label_31->show();
	ui.lineEdit31->show();
	ui.lineEdit31->setText("");
	return i;
}


/*##############################
#############直方图#############
###############################*/

void Hi_Opencv::on_zhi_open()
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
		image_zhi = imread(str);
		cvtColor(image_zhi, image_zhi, COLOR_BGR2RGB);
		cv::resize(image_zhi, image_zhi, Size(300, 200));
		QImage img = QImage((const unsigned char*)(image_zhi.data), image_zhi.cols, image_zhi.rows, QImage::Format_RGB888);

		//label_in = new QLabel();
		ui.label_zhi_in->setPixmap(QPixmap::fromImage(img));
		ui.label_zhi_in->resize(QSize(img.width(), img.height()));
		//ui.label_in->show();
		//ui.pushButton_start->setEnabled(true);
	}
}



int Hi_Opencv::on_zhione_show()
{
	Mat src;
	// 1. 加载源图像
	image_zhi.copyTo(src);

	if (!src.data)
	{
		QMessageBox::warning(this, "warning", "Please open a picture first!");
		return 0;
	}

	// 2. 在R、G、B平面中分离源图像，把多通道图像分为多个单通道图像。使用OpenCV函数cv::split。
	vector<Mat> bgr_planes;
	split(src, bgr_planes);// 把多通道图像分为多个单通道图像

//	printf("channels=%d\n", bgr_planes.size());//3通道，所以size也是3

	// 3. 现在我们准备开始为每个平面配置直方图。 由于我们正在使用B，G和R平面，我们知道我们的值将在区间[0,255]范围内
	int histBins = 256;//建立箱数（5,10 ......）
	float range[] = { 0, 255 };//设置值的范围（在0到255之间）
	const float * histRanges = range;//注意：函数形参 float ** 与 const float ** 是两种不同数据类型。
	bool uniform = true, accumulate = false;//我们希望我们的箱子具有相同的尺寸（均匀）并在开头清除直方图
	Mat b_hist, g_hist, r_hist;//calcHist计算出来的Mat中元素的最大值可能上几千，所以最好归一化后再绘制直方图
	//使用OpenCV函数cv::calcHist计算直方图：
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histBins, &histRanges, uniform, accumulate);//计算直方图
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histBins, &histRanges, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histBins, &histRanges, uniform, accumulate);

	// 4. 归一化
	int hist_cols = 400;
	int hist_rows = 512;
	int bin_w = hist_rows / histBins;

	//请注意，在绘制之前，我们首先对直方图进行cv :: normalize，使其值落在输入参数指示的范围内：
	normalize(b_hist, b_hist, 0, hist_cols, NORM_MINMAX, -1, Mat());//b_hist中元素的值转换到 0-hist_cols 之间
	normalize(g_hist, g_hist, 0, hist_cols, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, hist_cols, NORM_MINMAX, -1, Mat());//传参 0, hist_cols 或 hist_cols, 0 结果一致

	// 5. 绘制直方图
	Mat histImage(hist_rows, hist_cols, CV_8UC3, Scalar(0, 0, 0));
	for (int i = 1; i < histBins; i++)
	{
		// cvRound 四舍五入，返回整型值
		line(histImage, Point((i - 1)*bin_w, hist_cols - cvRound(b_hist.at<float>(i - 1))),
			Point(i*bin_w, hist_cols - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 2, LINE_AA);
		line(histImage, Point((i - 1)*bin_w, hist_cols - cvRound(g_hist.at<float>(i - 1))),
			Point(i*bin_w, hist_cols - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 2, LINE_AA);
		line(histImage, Point((i - 1)*bin_w, hist_cols - cvRound(r_hist.at<float>(i - 1))),
			Point(i*bin_w, hist_cols - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 2, LINE_AA);
	}
	QImage img = QImage((const unsigned char*)(histImage.data), histImage.cols, histImage.rows, QImage::Format_RGB888);
	ui.label_zhi_out->setPixmap(QPixmap::fromImage(img));

	QImage img2 = QImage((const unsigned char*)(image_zhi.data), image_zhi.cols, image_zhi.rows, QImage::Format_RGB888);
	ui.label_zhi_in->setPixmap(QPixmap::fromImage(img2));

	return(0);
}

int Hi_Opencv::on_zhitwo_show()
{
	Mat src, dst;

	char* source_window = (char*)"Source image";
	char* equalized_window = (char*)"Equalized Image";

	/// 加载源图像
	image_zhi.copyTo(src);

	if (!src.data)
	{
		QMessageBox::warning(this, "warning", "Please open a picture first!");
		return 0;
	}

	/// 转为灰度图
	cvtColor(src, src, CV_BGR2GRAY);

	/// 应用直方图均衡化
	equalizeHist(src, dst);

	/// 显示结果

/*显示彩色图*/
//	QImage img = QImage((const unsigned char*)(dst.data), dst.cols, dst.rows, QImage::Format_RGB888);
//	ui.label_zhi_out->setPixmap(QPixmap::fromImage(img));

/*显示灰度图*/
	QImage img = QImage((const uchar*)dst.data, dst.cols, dst.rows, dst.cols*dst.channels(), QImage::Format_Indexed8);
	ui.label_zhi_out->setPixmap(QPixmap::fromImage(img));

	QImage img2 = QImage((const uchar*)src.data, src.cols, src.rows, src.cols*src.channels(), QImage::Format_Indexed8);
	ui.label_zhi_in->setPixmap(QPixmap::fromImage(img2));

	return 0;
}



/// 全局变量
Mat src_zhi; Mat hsv_zhi; Mat hue_zhi; Mat dst_zhi;
int bins_zhi = 25;

/// 函数申明
void Hist_and_Backproj(int, void*);

/** @函数 main */
int Hi_Opencv::on_zhithree_show()
{
	/// 读取图像
	image_zhi.copyTo(src_zhi);
	if (!src_zhi.data)
	{
		QMessageBox::warning(this, "warning", "Please open a picture first!");
		return 0;
	}
	/// 转换到 HSV 空间
	cvtColor(src_zhi, hsv_zhi, CV_BGR2HSV);

	/// 分离 Hue 通道
	hue_zhi.create(hsv_zhi.size(), hsv_zhi.depth());
	int ch[] = { 0, 0 };
	mixChannels(&hsv_zhi, 1, &hue_zhi, 1, ch, 1);

	/// 创建 Trackbar 来输入bin的数目
	//char* window_image = (char*)"Source image";
	//namedWindow(window_image, CV_WINDOW_AUTOSIZE);
	//createTrackbar("* Hue  bins: ", window_image, &bins_zhi, 180, Hist_and_Backproj);
	Hist_and_Backproj(0, 0);

	/// 现实图像
	//imshow(window_image, src_zhi);

	Mat backproj;
	dst_zhi.copyTo(backproj);
	QImage img = QImage((const uchar*)backproj.data, backproj.cols, backproj.rows, backproj.cols*backproj.channels(), QImage::Format_Indexed8);
	ui.label_zhi_out->setPixmap(QPixmap::fromImage(img));

	return 0;
}


/**
 * @函数 Hist_and_Backproj
 * @简介：Trackbar事件的回调函数
 */
void Hist_and_Backproj(int, void*)
{
	MatND hist;
	int histSize = MAX(bins_zhi, 2);
	float hue_range[] = { 0, 180 };
	const float* ranges = { hue_range };

	/// 计算直方图并归一化
	calcHist(&hue_zhi, 1, 0, Mat(), hist, 1, &histSize, &ranges, true, false);
	normalize(hist, hist, 0, 255, NORM_MINMAX, -1, Mat());

	/// 计算反向投影
	MatND backproj;
	calcBackProject(&hue_zhi, 1, 0, hist, backproj, &ranges, 1, true);

	backproj.copyTo(dst_zhi);

	/// 显示反向投影
//	imshow("BackProj", backproj);



	/// 显示直方图
	int w = 400; int h = 400;
	int bin_w = cvRound((double)w / histSize);
	Mat histImg = Mat::zeros(w, h, CV_8UC3);

	for (int i = 0; i < bins_zhi; i++)
	{
		rectangle(histImg, Point(i*bin_w, h), Point((i + 1)*bin_w, h - cvRound(hist.at<float>(i)*h / 255.0)), Scalar(0, 0, 255), -1);
	}

	//	imshow("Histogram", histImg);
}
