#include "Hi_Opencv.h"
#include <QDebug>
#include <qmessagebox.h>

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

