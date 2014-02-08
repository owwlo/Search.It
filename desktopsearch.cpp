#include "desktopsearch.h"
#include <QMouseEvent>
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include "csqliteindexguard.h"
#include "FTSOperator.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDesktopServices>

DesktopSearch::DesktopSearch(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
	,isFullTextModeOn(false)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);  
	setFixedSize(this->width(), this->height());
	setAttribute(Qt::WA_TranslucentBackground, true);
	setWindowFlags(Qt::FramelessWindowHint);

	ui.tableWidget->setColumnCount(4); 
	QStringList headers;
	headers << "File Name" << "Size" << "Path" << "Date Modified";
	ui.tableWidget->setHorizontalHeaderLabels(headers); 
	ui.tableWidget->setColumnWidth(0,300);
	ui.tableWidget->setColumnWidth(1,100);
	ui.tableWidget->setColumnWidth(2,500);

	esPath = QString::fromLocal8Bit(getenv("temp")) + "/es.exe";

	QFile file(":/DesktopSearch/Design/es.exe");
	file.copy(esPath);

	es = new QProcess(this);
	//connect(es, SIGNAL(finished(int)), this, SLOT(readResult(int)));
	connect(CSQLiteIndexGuard::GetInstance(),SIGNAL(finished(QList<DSFileItem> *)),this,SLOT(readResult(QList<DSFileItem> *)));	
	ui.listView->hide();
}

DesktopSearch::~DesktopSearch()
{

}
void DesktopSearch::mousePressEvent( QMouseEvent *event )
{
	if (event->button() == Qt::LeftButton)
	{
		dragPosition = event->globalPos() - frameGeometry().topLeft();
		event->accept();
	}
}

void DesktopSearch::mouseMoveEvent( QMouseEvent *event )
{
	if (event->buttons() == Qt::LeftButton) 
	{
		move(event->globalPos() - dragPosition);
		event->accept();
	}
}

void DesktopSearch::OnSearchBtnClicked()
{
	SearchIt(ui.lineEdit->text());
}

void DesktopSearch::SearchIt( QString s)
{
	if (s.length() == 0)
	{
		ui.listView->hide();
		return;
	}

	bool isIn=false;
	QList<HISTORY_ITEM*>::iterator i = historyList.begin();
	while (i != historyList.end())
	{
		HISTORY_ITEM * hi = *i;
		qDebug()<<"item:"<<hi->term<<" rank:"<<hi->rank;
		if(hi->term == s)
		{
			isIn = true;
			hi->rank++;
			break;
		}
		i++;
	}
	if (!isIn)
	{
		HISTORY_ITEM* hi = new HISTORY_ITEM;
		hi->rank=1;
		hi->term = s;
		historyList.append(hi);
	}
	
	ui.listView->hide();

	qSort(historyList.begin(), historyList.end());

	//es->start(esPath, QStringList() << s);
	if (!isFullTextModeOn)
	{
		IIndexGuard * ig = CSQLiteIndexGuard::GetInstance();
		QStringList keyList;
		keyList.append(s);
		ig->SearchForFiles(keyList);
	}
	else
	{
		FTSOperator * ftso = FTSOperator::GetInstance();
		QStringList keyList;
		keyList.append(s);
		ShowResult( ftso->SearchForFilesSync(keyList));
	}
}

void DesktopSearch::ShowResult( QList<DSFileItem> * fl)
{
	ui.tableWidget->clearContents();

	ui.tableWidget->setRowCount(fl->size());

	int k =0;

	QList<DSFileItem>::iterator i = fl->begin();
	for(; i != fl->end(); i++)
	{
		DSFileItem fileItem = *i;

		//QFileInfo file(filePath);
		
		//if (file.size() == 0)
			//continue;
		//qDebug()<<file.exists();
		
		ui.tableWidget->setItem(k,0, new QTableWidgetItem(fileItem.FileName));
		ui.tableWidget->setItem(k,1, new QTableWidgetItem(0));
		ui.tableWidget->setItem(k,2, new QTableWidgetItem(fileItem.FilePath));
		ui.tableWidget->setItem(k,3, new QTableWidgetItem(0));

		k++;
		
	}
	ui.tableWidget->setRowCount(k);
	ui.label_2->setText(QString::number(k));
}

void DesktopSearch::readResult(QList<DSFileItem> * fl)
{
	ShowResult( fl );
}
void DesktopSearch::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_F2)
		SwitchWholeTextSearchMode();
}
void DesktopSearch::SwitchWholeTextSearchMode()
{
	isFullTextModeOn = !isFullTextModeOn;
	if(isFullTextModeOn)
		ui.lineEdit->setStyleSheet("#lineEdit {\
										background-image: url(:/DesktopSearch/Design/SearchBarBackActive.png);\
										border:0px;\
										background-repeat:no-repeat;\
										background-color:transparent;\
										padding:2px 26px 0px;\
									}\
									#lineEdit:focus {\
										background-image: url(:/DesktopSearch/Design/SearchBarBackActive.png);\
									}");
	else
		ui.lineEdit->setStyleSheet("#lineEdit {\
										background-image: url(:/DesktopSearch/Design/SearchBarBack.png);\
										border:0px;\
										background-repeat:no-repeat;\
										background-color:transparent;\
										padding:2px 26px 0px;\
								   }\
								   #lineEdit:focus {\
										background-image: url(:/DesktopSearch/Design/SearchBarBack.png);\
								   }");
}

void DesktopSearch::OnEdit( QString s)
{
	qDebug()<<s;
	QList<HISTORY_ITEM*> ql;
	QList<HISTORY_ITEM*>::iterator i = historyList.begin();
	while (i != historyList.end())
	{
		HISTORY_ITEM * hi = *i;
		if(hi->term.indexOf(s) >= 0)
			ql.append(hi);
		i++;
	}
	if (ql.size() > 0)
	{
		QStandardItemModel * standardItemModel = new QStandardItemModel(this);  
		QStringList strList;  
		for (int i = 0;i<ql.size();i++)
		{
			HISTORY_ITEM * hi = ql.at(i);
			strList.append(hi->term);
			i++;
		}
		/*QList<HISTORY_ITEM*>::iterator i = ql.begin();
		while (i != ql.end())
		{
			HISTORY_ITEM * hi = *i;
			strList.append(hi->term);
			i++;
		}*/
		int nCount = strList.size();  
		for(int ii = 0; ii < nCount; ii++)  
		{  
			QString string = static_cast<QString>(strList.at(ii));  
			QStandardItem *item = new QStandardItem(string);  
			standardItemModel->appendRow(item);  
		}  
		ui.listView->setModel(standardItemModel);  
		ui.listView->show();
	}
	else
		ui.listView->hide();
}

void DesktopSearch::OnItemDoubleClicked( int a,int b )
{
	QTableWidgetItem * ti1 = ui.tableWidget->item(a,0);
	QTableWidgetItem * ti2 = ui.tableWidget->item(a,2);

	QString execFile = ti2->text() + ti1->text();

	qDebug()<<execFile;
	QDesktopServices::openUrl(QUrl::fromLocalFile(execFile));
}

void DesktopSearch::OnHistoryItemDoubleClicked( QModelIndex mi)
{
	QString selectString = mi.data().toString();
	qDebug()<<selectString;
	ui.lineEdit->setText(selectString);
	ui.listView->hide();
}
