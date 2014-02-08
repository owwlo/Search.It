#ifndef CSQLITEINDEXGUARD_H
#define CSQLITEINDEXGUARD_H

#include <QObject>
#include "IIndexGuard.h"
#include <QtSql>


class CSQLiteIndexGuard :public QThread ,public IIndexGuard
{
	Q_OBJECT

public:
	~CSQLiteIndexGuard();
	static CSQLiteIndexGuard * GetInstance();
	virtual void SearchForFiles( QStringList keyWordList );
	virtual void WriteToIndex( QList<FILE_ITEM> fileList );
	virtual QList<DSFileItem> * SearchForFilesSync(QStringList keyWordList);

private:
	CSQLiteIndexGuard(QObject *parent);
	QSqlDatabase *dbconn;
	static CSQLiteIndexGuard * me;

signals:
	void finished(QList<DSFileItem> *);
	
};

#endif // CSQLITEINDEXGUARD_H
