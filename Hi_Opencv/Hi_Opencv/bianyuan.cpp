#include "bianyuan.h"
#include <QDebug>
#include <qmessagebox.h>
using namespace cv;

bianyuan::bianyuan(QWidget *parent)
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

void bianyuan::on_open()
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
/*
void bianyuan::on_start()
{
	switch (i) {
	case 1:
		
		
		break;

	default:
		break;

	}
	*/

	int bianyuan::on_sobel_show()
	{
		i = 1;
		ui.label_by1->setText("gaussian");
		ui.label_w->hide();
		ui.label_h->hide();
		ui.lineEdit_w->hide();
		ui.lineEdit_h->hide();
		ui.label_i->show();
		ui.lineEdit_i->show();
		ui.label_by1

		return i;

	}
