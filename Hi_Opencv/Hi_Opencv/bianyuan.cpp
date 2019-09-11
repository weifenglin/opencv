#include "bianyuan.h"
#include <QDebug>
#include <qmessagebox.h>
using namespace cv;

bianyuan::bianyuan(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//i = -1;
	

}

///QString转String
String qstrtostr(QString qstr)
{
	QByteArray cdata = qstr.toLocal8Bit();
	return String(cdata);
}

void bianyuan::on_byopen()
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
		String str = qstrtostr(filename);//写了一个qstr2str函数用于转化
		image = imread(str);
		cvtColor(image, image, COLOR_BGR2RGB);
		cv::resize(image, image, Size(300, 200));
		QImage img = QImage((const unsigned char*)(image.data), image.cols, image.rows, QImage::Format_RGB888);

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
		ui.label_by1->setText("sobel导数");
		

		return i;

	}
