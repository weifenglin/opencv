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

///QStringתString
String qstrtostr(QString qstr)
{
	QByteArray cdata = qstr.toLocal8Bit();
	return String(cdata);
}

void bianyuan::on_byopen()
{
	QString filename;
	filename = QFileDialog::getOpenFileName(this, tr("ѡ��ͼ��"), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF)"));

	if (filename.isEmpty())
	{
		return;
	}
	else
	{

		//String str  filename.toStdString();//QString�ַ�����������ת����String��������
		String str = qstrtostr(filename);//д��һ��qstr2str��������ת��
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
		ui.label_by1->setText("sobel����");
		

		return i;

	}
