#pragma once
#include "afxwin.h"


// CMissionDlg 对话框

class CMissionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMissionDlg)

public:
	CMissionDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMissionDlg();

// 对话框数据
	enum { IDD = IDD_DLG_MISSION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_UnSelectList;
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnDblclkList1();
	CListBox m_MissionList;
	afx_msg void OnLbnDblclkList2();
};
