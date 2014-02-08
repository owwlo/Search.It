#include "csqliteindexguard.h"
#include "FTSOperator.h"

CSQLiteIndexGuard * CSQLiteIndexGuard::me;

CSQLiteIndexGuard::CSQLiteIndexGuard(QObject *parent)
	: QThread(parent)
{
	dbconn = &QSqlDatabase::addDatabase("QSQLITE");
	dbconn->setDatabaseName(":memory:");
	if(!dbconn->open())
		qDebug()<<"fail to open sqlite" ;

	QSqlQuery query;
	query.exec("create table Files (FileName VARCHAR(512),FilePath varchar(1024));");
	//query.exec("create virtual table FileNameIndex using fts3(FileName,FilePath);");
}

CSQLiteIndexGuard::~CSQLiteIndexGuard()
{

}

void CSQLiteIndexGuard::SearchForFiles( QStringList keyWordList )
{
	QList<DSFileItem> * fl = new QList<DSFileItem>;
	QSqlQuery query;
	query.exec("select * from Files where FileName like '%"+keyWordList.at(0)+"%';");
	while(query.next())
	{
		PDSFileItem pDsFileItem = new DSFileItem;
		pDsFileItem->FileName = query.value(0).toString();
		pDsFileItem->FilePath = query.value(1).toString();

		fl->append(*pDsFileItem);
	}

	emit finished(fl);

	//return *fl;
}
QList<DSFileItem> * CSQLiteIndexGuard::SearchForFilesSync( QStringList keyWordList )
{
	QList<DSFileItem> * fl = new QList<DSFileItem>;
	QSqlQuery query;
	query.exec("select * from Files where FileName like '%"+keyWordList.at(0)+"%';");
	while(query.next())
	{
		PDSFileItem pDsFileItem = new DSFileItem;
		pDsFileItem->FileName = query.value(0).toString();
		pDsFileItem->FilePath = query.value(1).toString();

		fl->append(*pDsFileItem);
	}

	return fl;

}
void CSQLiteIndexGuard::WriteToIndex( QList<FILE_ITEM> fileList )
{
	QTime counter;
	counter.start();

	QSqlQuery query;
	//QSqlQuery queryIndex;
	//dbconn->transaction();

	query.prepare("insert into Files values (?, ?);");
	//queryIndex.prepare("insert into FileNameIndex (FileName,FilePath) values (?, ?);");

	QVariantList* fileName = new QVariantList;
	QVariantList* filePath = new QVariantList;

	QList<FILE_ITEM>::iterator i = fileList.begin();
	for(; i != fileList.end(); i++)
	{
		*fileName << (*i).FileName;
		*filePath << (*i).FilePath;
		//query.exec("insert into Files values('"+(*i).FileName+"','"+(*i).FilePath+"');");
	}
	query.addBindValue(*fileName);
	query.addBindValue(*filePath);
	//queryIndex.addBindValue(*fileName);
	//queryIndex.addBindValue(*filePath);

	query.execBatch();
	//queryIndex.execBatch();

	//query.exec("select count(*) from Files;");
	//query.exec("create index FileNameIndex on Files(FileName);");
	//query.exec("SELECT * FROM Files where FileName like '%owwlo%';");
	//while(query.next())
	//{
	//	qDebug()<<query.value(0).toString()<<query.value(1).toString();
	//}

	QString sqlAttach = QString("ATTACH DATABASE '%1' AS fileDB")
		.arg(QDir::toNativeSeparators("c:/DS.db"));
	query.exec(sqlAttach);
	query.exec("CREATE TABLE fileDB.Files AS SELECT * from Files");

	//dbconn->close();
	qDebug() <<"done!!!";
	//dbconn->commit();
	qDebug()<<counter.elapsed()/1000.0;

	FTSOperator * ftso = FTSOperator::GetInstance();
	ftso->start();
}

CSQLiteIndexGuard * CSQLiteIndexGuard::GetInstance()
{
	if(!me)
		me = new CSQLiteIndexGuard(0);
	return me;
}
