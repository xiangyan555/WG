// AutoThread.cpp : ʵ���ļ�
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
	// TODO: �ڴ�ִ���������̳߳�ʼ��
	return TRUE;
}

int CAutoThread::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CAutoThread, CWinThread)
END_MESSAGE_MAP()


// CAutoThread ��Ϣ�������


int CAutoThread::Run()
{
	// TODO: �ڴ����ר�ô����/����û���
	if (m_pOwner == NULL)
	{
		return -1;
	}

	return 0;
	//return CWinThread::Run();
}
