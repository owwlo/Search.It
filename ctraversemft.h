#ifndef CTRAVERSEMFT_H
#define CTRAVERSEMFT_H

#include <QObject>
#include <QThread>
#include "Types.h"


class CTraverseMFT : public QThread
{
	Q_OBJECT

public:
	~CTraverseMFT();
	virtual void run();
	QList<FILE_ITEM>* GetTraverseFileList();
	static CTraverseMFT* GetInstance();

signals:
	void Signal_OnTraverseDone();

private:
	CTraverseMFT(QObject *parent);
	QList<FILE_ITEM> mFileList;
	static CTraverseMFT * me;
	
};

#endif // CTRAVERSEMFT_H
