#pragma once


// CPickDlg 对话框

class CPickDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPickDlg)

public:
	CPickDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPickDlg();

// 对话框数据
	enum { IDD = IDD_DLG_PICK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

};
