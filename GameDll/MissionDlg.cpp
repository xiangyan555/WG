// MissionDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GameDll.h"
#include "MissionDlg.h"
#include "afxdialogex.h"


// CMissionDlg �Ի���

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


// CMissionDlg ��Ϣ�������


BOOL CMissionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_UnSelectList.AddString("�ɼ���Ʒ");
	m_UnSelectList.AddString("������");

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CMissionDlg::OnLbnDblclkList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString	strText;
	int nSel = m_MissionList.GetCurSel();
	TRACE("%d\n", nSel);
	m_MissionList.GetText(nSel, strText);
	m_MissionList.DeleteString(nSel);

	int nCount = m_UnSelectList.GetSelCount();
	m_UnSelectList.InsertString(0,strText);
}
