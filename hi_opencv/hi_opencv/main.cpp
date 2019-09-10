#include "hi_opencv.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	hi_opencv w;
	w.show();
	return a.exec();
}
