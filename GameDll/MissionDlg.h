#pragma once
#include "afxwin.h"


// CMissionDlg �Ի���

class CMissionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMissionDlg)

public:
	CMissionDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMissionDlg();

// �Ի�������
	enum { IDD = IDD_DLG_MISSION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_UnSelectList;
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnDblclkList1();
	CListBox m_MissionList;
	afx_msg void OnLbnDblclkList2();
};
