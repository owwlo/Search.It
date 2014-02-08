#include "FTSOperator.h"
#include "IIndexGuard.h"
#include "csqliteindexguard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include  <string>
#include "ICTCLAS50.h"
#include <QStringList>
#include <QString>

#define POS_TAGGER_TEST
#ifdef POS_TAGGER_TEST
bool g_bPOSTagged=true;
#else
bool g_bPOSTagged=false;
#endif	

using namespace std;

FTSOperator * FTSOperator::me;

FTSOperator::FTSOperator(QObject *parent)
	: QThread(parent)
{
	if(!ICTCLAS_Init()) //初始化分词组件。
	{
		printf("Init fails\n");  
		return ;
	}
	else
	{
		printf("Init ok\n");
	}

	//设置词性标注集(0 计算所二级标注集，1 计算所一级标注集，2 北大二级标注集，3 北大一级标注集)
	ICTCLAS_SetPOSmap(3);

	//char* sSentence="随后温总理就离开了舟曲县城，预计温总理今天下午就回到北京。以上就是今天上午的最新动态 i'm am a good boy cnbeta 1020.23"; // 需要分词的内容
	//unsigned int nPaLen=strlen(sSentence); // 需要分词的长度
	//char* sRst=0;   //用户自行分配空间，用于保存结果；
	//sRst=(char *)malloc(nPaLen*2); //建议长度为字符串长度的倍。
	//int nRstLen=0; //分词结果的长度

	//nRstLen = ICTCLAS_ParagraphProcess(sSentence,nPaLen,sRst,CODE_TYPE_UNKNOWN,0);  //字符串处理
	//printf("The result is:\n%s\n",sRst);
	//free(sRst);
	//也可以用文件文本导入,调用文件分词接口，将分词结果写入“Test_reslult.txt”文件中
	//ICTCLAS_FileProcess("Test.txt", "Test_result.txt",CODE_TYPE_GB,0);
	
}

FTSOperator::~FTSOperator()
{
	ICTCLAS_Exit();	//释放资源退出
}

FTSOperator * FTSOperator::GetInstance()
{
	if (!me)
		me = new FTSOperator(0);
	return me;
}

void FTSOperator::run()
{
	/*dbconn = &QSqlDatabase::addDatabase("QSQLITE");
	dbconn->setDatabaseName(":memory:");
	if(!dbconn->open())
		qDebug()<<"fail to open sqlite" ;
	*/
	QSqlQuery query;
	query.exec("CREATE VIRTUAL TABLE wholetext USING fts3(filename,filepath,body);");

	IIndexGuard * ig = CSQLiteIndexGuard::GetInstance();
	QStringList keyList;
	keyList.append(".txt");
	QList<DSFileItem> * textContainerFileList = ig->SearchForFilesSync(keyList);

	qDebug()<<"get text file : "<<textContainerFileList->size();

	QList<DSFileItem>::iterator i = textContainerFileList->begin();
	while(i != textContainerFileList->end())
	{
		DSFileItem fi = *i;
		QString line;
		QFile file(fi.FilePath + fi.FileName);
		//QTextCodec *code=QTextCodec::codecForName("utf8");
		file.open(QFile::ReadOnly);
		QTextStream stream(&file);
		//stream.setCodec(code);//输出流的设置--------必须嘀
		while(stream.atEnd()==0)
		{  
			line += stream.readLine();
		}
		string ss = line.toStdString();
		char* sSentence=const_cast<char*>(ss.c_str());
		unsigned int nPaLen=strlen(sSentence);
		char* sRst=0;
		sRst=(char *)malloc(nPaLen*6);
		int nRstLen=0;

		nRstLen = ICTCLAS_ParagraphProcess(sSentence,nPaLen,sRst,CODE_TYPE_UNKNOWN,0);
		line = QString::fromLocal8Bit(sRst);
		free(sRst);

		line = line.replace(QRegExp("'"),"");
		line = line.replace(QRegExp("\""),"");

		line = line.replace(QRegExp("[\\s]+")," ");

		query.exec("INSERT INTO wholetext (filename,filepath,body) VALUES ('"+fi.FileName+"','"+ fi.FilePath +"', '" + line + "');");

		//QStringList termList = line.split(QRegExp("[\\s]+"));
		
		//qDebug()<<"INSERT INTO wholetext (filename,filepath,body) VALUES ('"+fi.FilePath + fi.FileName+"', '" + line + "');";
		i++;
	}
	qDebug()<<"FTS3 Done";

	//query.exec("SELECT file FROM wholetext where body MATCH '的';");
	//while(query.next()) {
	//	qDebug()<< query.value(0).toString();  
	//}
}
QList<DSFileItem> * FTSOperator::SearchForFilesSync( QStringList keyWordList )
{
	string ss = keyWordList.at(0).toStdString();
	char* sSentence=const_cast<char*>(ss.c_str());
	unsigned int nPaLen=strlen(sSentence);
	char* sRst=0;
	sRst=(char *)malloc(nPaLen*6);
	int nRstLen=0;

	nRstLen = ICTCLAS_ParagraphProcess(sSentence,nPaLen,sRst,CODE_TYPE_UNKNOWN,0);
	QString line = QString::fromLocal8Bit(sRst);
	free(sRst);

	line = line.left(line.length()-1);
	line.replace(" "," AND ");
	qDebug()<<line;

	QList<DSFileItem> * fl = new QList<DSFileItem>;
	QSqlQuery query;
	query.exec("select filename,filepath from wholetext where body match '" + line + "';");
	while(query.next())
	{
		PDSFileItem pDsFileItem = new DSFileItem;
		pDsFileItem->FileName = query.value(0).toString();
		pDsFileItem->FilePath = query.value(1).toString();

		fl->append(*pDsFileItem);
	}

	return fl;

}