// GameDll.cpp : 定义 DLL 的初始化例程。
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
//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CGameDllApp

BEGIN_MESSAGE_MAP(CGameDllApp, CWinApp)
END_MESSAGE_MAP()


// CGameDllApp 构造

CGameDllApp::CGameDllApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CGameDllApp 对象

CGameDllApp theApp;


// CGameDllApp 初始化

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
		g_hHook = ::SetWindowsHookEx(WH_KEYBOARD, GameProc, theApp.m_hInstance, dwThreadID);	//键盘勾子
		if (g_hHook == NULL)
		{
			TRACE("安装勾子失败!\n");
		} else {
			TRACE("安装勾子成功!\n");
		}
	}
	
}


void UnHook() {
	if (g_hHook != NULL)
	{
		::UnhookWindowsHookEx(g_hHook);
		g_hHook = NULL;
		TRACE("已卸载勾子\n");
	}
}



int CGameDllApp::ExitInstance()
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pDlgMain != NULL)
	{
		delete pDlgMain;
		pDlgMain = NULL;
	}

	return CWinApp::ExitInstance();
}
