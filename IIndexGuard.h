#ifndef IINDEXGUARD_H
#define IINDEXGUARD_H

#include <QTime>
#include <QString>
#include <QList>
#include "ctraversemft.h"

class IIndexGuard
{
public:
	virtual void SearchForFiles(QStringList keyWordList) = 0;
	virtual void WriteToIndex(QList<FILE_ITEM> fileList) = 0;
	virtual QList<DSFileItem> * SearchForFilesSync(QStringList keyWordList) = 0;
};
#endif