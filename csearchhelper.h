#ifndef CSEARCHHELPER_H
#define CSEARCHHELPER_H

#include <QThread>
#include "IIndexGuard.h"


class CSearchHelper : public QThread
{
	Q_OBJECT

public:
	~CSearchHelper();
	static CSearchHelper* GetInstance();

public slots:
	void OnTraverseDone();

private:
	CSearchHelper(QObject *parent);
	virtual void run();
	static CSearchHelper* me;
	IIndexGuard * mIndexGuard;
};

#endif // CSEARCHHELPER_H
