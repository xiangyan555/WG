// GameDll.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "GameDll.h"
#include "DlgMainForm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMainDlg *pDlgMain = NULL;
HHOOK g_hHook = NULL;

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CGameDllApp

BEGIN_MESSAGE_MAP(CGameDllApp, CWinApp)
END_MESSAGE_MAP()


// CGameDllApp ����

CGameDllApp::CGameDllApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CGameDllApp ����

CGameDllApp theApp;


// CGameDllApp ��ʼ��

BOOL CGameDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

LRESULT CALLBACK GameProc(int nCode, WPARAM wParam, LPARAM lParam) 
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	if (wParam == VK_HOME && lParam & (1 << 31))
	{
		if (pDlgMain == NULL)
		{
			pDlgMain = new CMainDlg();
			pDlgMain->Create(IDD_DLG_MAIN);
			pDlgMain->ShowWindow(TRUE);
		} else {
			pDlgMain->ShowWindow(pDlgMain->IsWindowVisible() ? SW_HIDE : SW_SHOW);
		}
	}
	return CallNextHookEx(0,nCode,wParam,lParam);
}

void StartHook(DWORD dwThreadID) {
	if (g_hHook == NULL)
	{
		g_hHook = ::SetWindowsHookEx(WH_KEYBOARD, GameProc, theApp.m_hInstance, dwThreadID);	//���̹���
		if (g_hHook == NULL)
		{
			TRACE("��װ����ʧ��!\n");
		} else {
			TRACE("��װ���ӳɹ�!\n");
		}
	}
	
}


void UnHook() {
	if (g_hHook != NULL)
	{
		::UnhookWindowsHookEx(g_hHook);
		g_hHook = NULL;
		TRACE("��ж�ع���\n");
	}
}



int CGameDllApp::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pDlgMain != NULL)
	{
		delete pDlgMain;
		pDlgMain = NULL;
	}

	return CWinApp::ExitInstance();
}
