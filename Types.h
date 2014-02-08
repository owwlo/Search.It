#ifndef TYPES_H
#define TYPES_H

#include <QString>
#include <QTime>

typedef struct
{
	QString FileName;
	long	FileSize;
	QString	FilePath;
	QTime	LastModified;

}DSFileItem,*PDSFileItem;

typedef struct
{
	QString FileName;
	QString FilePath;
} FILE_ITEM ,*PFILE_ITEM;
#endif