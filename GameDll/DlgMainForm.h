#pragma once
#include "afxcmn.h"
#include "MissionDlg.h"
#include "PickDlg.h"
#include "AutoThread.h"
#include "TestDlg.h"

// CDlgMainForm �Ի���

class CMainDlg : public CDialog
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMainDlg();

// �Ի�������
	enum { IDD = IDD_DLG_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_Tab;
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
protected:
	afx_msg LRESULT OnDeleteMsg(WPARAM wParam, LPARAM lParam);
public:
	CMissionDlg m_MissionDlg;
	CPickDlg	m_PickDlg;
	CTestDlg	m_TestDlg;
	CAutoThread *m_pThread;

	afx_msg void OnBnClickedButton1();
};
