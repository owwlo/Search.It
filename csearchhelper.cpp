#include "csearchhelper.h"
#include "csqliteindexguard.h"

CSearchHelper * CSearchHelper::me;

CSearchHelper::CSearchHelper(QObject *parent)
	: QThread(parent)
{
	connect(CTraverseMFT::GetInstance(),SIGNAL(Signal_OnTraverseDone()),this,SLOT(OnTraverseDone()));
}

CSearchHelper::~CSearchHelper()
{

}

CSearchHelper* CSearchHelper::GetInstance()
{
	if(!me)
		me = new CSearchHelper(0);
	return me;
}

void CSearchHelper::run()
{
	
}

void CSearchHelper::OnTraverseDone()
{
	mIndexGuard = CSQLiteIndexGuard::GetInstance();
	mIndexGuard->WriteToIndex(*(CTraverseMFT::GetInstance()->GetTraverseFileList()));
}
