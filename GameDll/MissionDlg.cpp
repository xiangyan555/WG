// MissionDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GameDll.h"
#include "MissionDlg.h"
#include "afxdialogex.h"


// CMissionDlg 对话框

IMPLEMENT_DYNAMIC(CMissionDlg, CDialogEx)

CMissionDlg::CMissionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMissionDlg::IDD, pParent)
{

}

CMissionDlg::~CMissionDlg()
{
}

void CMissionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_UnSelectList);
	DDX_Control(pDX, IDC_LIST2, m_MissionList);
}


BEGIN_MESSAGE_MAP(CMissionDlg, CDialogEx)
	ON_LBN_DBLCLK(IDC_LIST1, &CMissionDlg::OnLbnDblclkList1)
	ON_LBN_DBLCLK(IDC_LIST2, &CMissionDlg::OnLbnDblclkList2)
END_MESSAGE_MAP()


// CMissionDlg 消息处理程序


BOOL CMissionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_UnSelectList.AddString("采集物品");
	m_UnSelectList.AddString("定点打怪");

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CMissionDlg::OnLbnDblclkList1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString	strText;
	int nSel = m_UnSelectList.GetCurSel();
	TRACE("%d\n", nSel);
	m_UnSelectList.GetText(nSel, strText);
	m_UnSelectList.DeleteString(nSel);

	int nCount = m_MissionList.GetSelCount();
	m_MissionList.InsertString(0,strText);
}


void CMissionDlg::OnLbnDblclkList2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString	strText;
	int nSel = m_MissionList.GetCurSel();
	TRACE("%d\n", nSel);
	m_MissionList.GetText(nSel, strText);
	m_MissionList.DeleteString(nSel);

	int nCount = m_UnSelectList.GetSelCount();
	m_UnSelectList.InsertString(0,strText);
}
