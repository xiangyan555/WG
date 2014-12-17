// AutoThread.cpp : 实现文件
//

#include "stdafx.h"
#include "GameDll.h"
#include "AutoThread.h"


// CAutoThread

IMPLEMENT_DYNCREATE(CAutoThread, CWinThread)

CAutoThread::CAutoThread()
{
}

CAutoThread::~CAutoThread()
{
}

BOOL CAutoThread::InitInstance()
{
	// TODO: 在此执行任意逐线程初始化
	return TRUE;
}

int CAutoThread::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CAutoThread, CWinThread)
END_MESSAGE_MAP()


// CAutoThread 消息处理程序


int CAutoThread::Run()
{
	// TODO: 在此添加专用代码和/或调用基类
	if (m_pOwner == NULL)
	{
		return -1;
	}

	return 0;
	//return CWinThread::Run();
}
