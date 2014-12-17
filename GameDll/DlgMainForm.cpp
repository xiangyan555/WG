// DlgMainForm.cpp : 实现文件
//

#include "stdafx.h"
#include "GameDll.h"
#include "DlgMainForm.h"
#include "afxdialogex.h"
#include "GameHelper.h"
#include "DataHelp.h"
#include "CommonFun.h"


GameHelper helper;
CString strConfigFileName;
// CMainDlg 对话框

IMPLEMENT_DYNAMIC(CMainDlg, CDialog)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{
	m_pThread = NULL;
}

CMainDlg::~CMainDlg()
{
	if (m_pThread != NULL)
	{
		TerminateThread(m_pThread->m_hThread, 0);
		m_pThread->Delete();
		m_pThread = NULL;
		TRACE("结束线程成功\n");
	}

	DestroyWindow();
	TRACE("CMainDlg调用了析构函数\n");
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMainDlg::OnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMainDlg::OnBnClickedButton1)
END_MESSAGE_MAP()



//更新基址线程
UINT __cdecl ThreadFunction( LPVOID pParam ) {
	DataHelp dataHelper;
	dataHelper.UpdateGameData();

	//char path[MAX_PATH] = {0};
	//GetCurrentFolder(MAX_PATH,path);
	//strcat_s(path,"\\");
	//strcat_s(path,helper.GetRoleName());
	//strcat_s(path, ".ini");
	//TRACE("文件路径：%s\n", path);
	//
	return 0;
}

// CMainDlg 消息处理程序
BOOL CMainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//TODO:  在此添加额外的初始化
	m_Tab.InsertItem(0, "任务选择");
	m_Tab.InsertItem(1, "采集设置");
	m_Tab.InsertItem(2, "测试");
	
	m_MissionDlg.Create(IDD_DLG_MISSION, GetDlgItem(IDC_TAB1));
	m_PickDlg.Create(IDD_DLG_PICK, GetDlgItem(IDC_TAB1));
	m_TestDlg.Create(IDD_DLG_TEST, GetDlgItem(IDC_TAB1));

	CRect rect;
	m_Tab.GetClientRect(&rect);
	rect.top += 22;
	rect.bottom -= 2;
	rect.left += 2;
	rect.right -= 2;
	m_MissionDlg.MoveWindow(&rect);
	m_PickDlg.MoveWindow(&rect);
	m_TestDlg.MoveWindow(&rect);

	m_Tab.SetCurSel(0);
	m_MissionDlg.ShowWindow(TRUE);
	m_PickDlg.ShowWindow(FALSE);
	m_TestDlg.ShowWindow(FALSE);

	//strConfigFileName = strConfigFileName + "\\config.ini";

	AfxBeginThread(ThreadFunction, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CMainDlg::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int nCurSel = m_Tab.GetCurSel();
	switch (nCurSel) {
	case 0 :
		m_MissionDlg.ShowWindow(TRUE);
		m_PickDlg.ShowWindow(FALSE);
		m_TestDlg.ShowWindow(FALSE);
		break;
	case  1:
		m_MissionDlg.ShowWindow(FALSE);
		m_PickDlg.ShowWindow(TRUE);
		m_TestDlg.ShowWindow(FALSE);
		break;
	case 2:
		m_MissionDlg.ShowWindow(FALSE);
		m_PickDlg.ShowWindow(FALSE);
		m_TestDlg.ShowWindow(TRUE);
		break;
	case 3:

		break;
	default:
		break;
	}
	*pResult = 0;
}




void CMainDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}
