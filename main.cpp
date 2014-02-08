#include "desktopsearch.h"
#include <QtGui/QApplication>
#include <QTextCodec>
#include "ctraversemft.h"
#include "csearchhelper.h"


int main(int argc, char *argv[])
{
	QTextCodec *codec = QTextCodec::codecForName("System"); 
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);
	QTextCodec::setCodecForTr(codec);

	QApplication a(argc, argv);
	a.setFont(QFont("Microsoft YaHei",9));
	DesktopSearch w;
	w.show();
	CTraverseMFT::GetInstance()->start();
	CSearchHelper::GetInstance()->start();

	return a.exec();
}
