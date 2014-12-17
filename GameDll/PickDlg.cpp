// PickDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GameDll.h"
#include "PickDlg.h"
#include "afxdialogex.h"


// CPickDlg 对话框

IMPLEMENT_DYNAMIC(CPickDlg, CDialogEx)

CPickDlg::CPickDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPickDlg::IDD, pParent)
{

}

CPickDlg::~CPickDlg()
{
}

void CPickDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPickDlg, CDialogEx)
	
END_MESSAGE_MAP()

