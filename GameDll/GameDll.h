// GameDll.h : GameDll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGameDllApp
// �йش���ʵ�ֵ���Ϣ������� GameDll.cpp
//

class CGameDllApp : public CWinApp
{
public:
	CGameDllApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};
