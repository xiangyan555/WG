#pragma once



// CAutoThread
class CMainDlg;

class CAutoThread : public CWinThread
{
	DECLARE_DYNCREATE(CAutoThread)

protected:
	CAutoThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CAutoThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual int Run();
private:
	CMainDlg *m_pOwner;
public:
	void SetOwner(CMainDlg *pOwner) { m_pOwner = pOwner; }
};


