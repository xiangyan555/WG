#pragma once


// CPickDlg �Ի���

class CPickDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPickDlg)

public:
	CPickDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPickDlg();

// �Ի�������
	enum { IDD = IDD_DLG_PICK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

};
