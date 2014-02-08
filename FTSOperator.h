#ifndef FTSOPERATOR_H
#define FTSOPERATOR_H

#include <QThread>
#include <QtSql>
#include "Types.h"

class FTSOperator : public QThread
{
	Q_OBJECT

public:
	static FTSOperator * GetInstance();
	~FTSOperator();
	QList<DSFileItem> * SearchForFilesSync( QStringList keyWordList );

private:
	FTSOperator(QObject *parent);

	virtual void run();

	static FTSOperator * me;
	QSqlDatabase * dbconn;
};

#endif // FTSOPERATOR_H
