// TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GameDll.h"
#include "TestDlg.h"
#include "afxdialogex.h"
#include "GameHelper.h"
#include "StructDef.h"


// CTestDlg �Ի���

IMPLEMENT_DYNAMIC(CTestDlg, CDialogEx)

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDlg::IDD, pParent)
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_GoodCombo);
	DDX_Control(pDX, IDC_COMBO2, m_SayCombo);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTestDlg::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CTestDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON4, &CTestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CTestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CTestDlg::OnBnClickedButton6)
END_MESSAGE_MAP()

//00530F98  |> \8D8D 80FEFFFF LEA ECX,DWORD PTR SS:[EBP-180]
//00530F9E  |.  E8 7DB6F0FF   CALL Game.0043C620                       ;  ��ʼ��


/*
0-3�ֽڣ���һ��������ַ���ڳ�ʼ���к����и�ֵ
4-15�ֽڣ��̶�ֵ
16�ֽڣ���Ʒλ��
17-19�ֽڣ���ʼ�������и�ֵ
20-23:[��Ʒ����+0x14]+8
24-27:[��Ʒ����+0x14]
28-31:[��Ʒ����+0x14]+4
32-35:[[�����ַ]+70]+34
36-39:�̶�ֵBF800000,����[[�����ַ]+70]+54���
40-43���̶�ֵBF800000,����[[�����ַ]+70]+54���
44-56����ʼ�������и�ֵ
*/
//#pragma pack(push)
//#pragma pack(1)
//struct _ParamerPack
//{
//	BYTE	paramer1[16];
//	BYTE	pos;
//	BYTE	paramer2[3];
//	DWORD	paramer3;
//	DWORD	paramer4;
//	DWORD	paramer5;
//	DWORD   paramer6;
//	DWORD   paramer7;
//	DWORD   paramer8;
//	BYTE	paramer9[13];
//};
//#pragma pack()
//#pragma pack(pop)


// CTestDlg ��Ϣ�������

void CTestDlg::OnBnClickedButton1()
{
	int nIndex = m_GoodCombo.GetCurSel();
	CString strName;
	m_GoodCombo.GetLBText(nIndex, strName);
	GameHelper helper;
	helper.UseGoods(strName);
	//DWORD	dwBase = * (DWORD *) 0x131425C;
	//DWORD	dwBagBase = *(DWORD *) (dwBase + 0x33d8);
	//DWORD	dwTmp;
	//BYTE	bPos = 0;
	//BYTE	bSize;
	//DWORD	dwObj;
	//DWORD	dwType;
	//char	*pItemName;
	//try
	//{
	//	bSize = * (BYTE *) (dwBase + 0x33F0);	//���߱������ܸ���
	//	for (BYTE i = 0; i < bSize; i++)
	//	{
	//		dwObj = * (DWORD *) (dwBagBase + i * 4);
	//		if (dwObj)
	//		{
	//			dwTmp = * (DWORD *) (dwObj + 0x28);
	//			dwType = * (DWORD *) (dwTmp + 0x4);
	//			//TRACE("��%d��---���:%d\n", i, dwType);
	//			if (dwType == 3)	//ֻ�ж�����Ʒ
	//			{
	//				dwTmp = * (DWORD *) (dwObj + 0x28);
	//				dwTmp = * (DWORD *) (dwTmp + 0x18);
	//				pItemName = (char *)dwTmp;
	//				if (strName == pItemName)
	//				{
	//					bPos = i;
	//					TRACE("%sλ�ڵ�%d��\n",strName, bPos);
	//					break;
	//				}
	//			}
	//		}

	//	}
	//	TRACE("%X\n", dwObj);
	//	struct _ParamerPack paramerPack;
	//	memset(&paramerPack, 0, sizeof(_ParamerPack));
	//	__asm
	//	{
	//		pushad;
	//		lea		ecx, paramerPack;
	//		mov		eax, 0x0043C6F0;
	//		call	eax;
	//		popad;
	//	}
	//	DWORD dwParamer;
	//	paramerPack.pos = bPos;
	//	dwParamer =  *(DWORD *) (dwObj + 0x14);
	//	paramerPack.paramer3 = *(DWORD *)(dwParamer + 0x8);
	//	paramerPack.paramer4 = *(DWORD *)dwParamer;
	//	paramerPack.paramer5 = *(DWORD *)(dwParamer + 0x4);

	//	DWORD dwRoleBase = *(DWORD *)0x9B2AE4;
	//	dwTmp = *(DWORD *)(dwRoleBase + 0x70);
	//	paramerPack.paramer6 = *(DWORD *)(dwTmp + 0x34);
	//	paramerPack.paramer7 = * (DWORD *)(dwTmp + 0x54);
	//	paramerPack.paramer8 = * (DWORD *)(dwTmp + 0x54);
	//
	//	__asm
	//	{
	//		pushad;
	//		lea		ecx, paramerPack;
	//		push	ecx;
	//		mov		ebx, 0x1320B2C;
	//		mov		ecx, [ebx];
	//		mov		eax, 0x0065A0C0;
	//		call	eax;
	//		popad;
	//	}
	//}
	//catch (...)
	//{
	//}


	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//BYTE bParamer[48] = {0x18, 0xD6, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
	//					0x01, 0x97, 0xCC, 0x6E, 0x6B, 0xC7, 0xC9, 0x01, 0x00, 0x01, 0x4C, 0x04, 0x9A, 0x53, 0xB4, 0x21,
	//					0xE2, 0x4C, 0x00, 0x00, 0x00, 0x00, 0x80, 0xBF, 0x00, 0x00, 0x80, 0xBF, 0x00, 0x00, 0x80, 0xBF};
	//BYTE bParamer[57] = { 0 };

	//try
	//{
	//	__asm
	//	{
	//		pushad;
	//		lea		ecx, bParamer;
	//		mov		eax, 0x0043C620;
	//		call	eax;
	//		popad;
	//	}

	//	/*__asm
	//	{
	//		pushad;
	//		lea		ecx, bParamer;
	//		push	ecx;
	//		mov		ebx, 0x131FB2C;
	//		mov		ecx, [ebx];
	//		mov		eax, 0x00659F40;
	//		call	eax;
	//		popad;
	//	}*/
	//}
	//catch (CException* e)
	//{
	//}
}

//��õ�ǰ�������辭��
void CTestDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	

	try
	{
		//������ﵱǰ�ȼ�  
		DWORD dwBase = *(DWORD *)0x9B1AE4;
		dwBase = *(DWORD *) (dwBase + 0x70);
		dwBase = *(DWORD *) (dwBase + 0x1E8);
		dwBase = *(DWORD *) (dwBase + 0x4);
		DWORD dwLevel = * (DWORD *) (dwBase + 0x64);
		TRACE("��ǰ�ȼ���%X\n", dwLevel);
		DWORD dwRet = 0;
		__asm
		{
			pushad;
			mov		eax,0x13134A0;
			mov		eax,[eax];
			mov		edx,[eax];
			mov		ecx, dwLevel;
			push	ecx;
			mov		ecx, eax;
			call	[edx];				//����CALL������һ������[����+0x4]�����������辭��
			mov		ebx, eax;
			mov		eax, [ebx+0x4];
			mov     dwLevel,eax;
			popad;
		}

		TRACE("�������飺%d\n", dwLevel);
	}
	catch (...)
	{
		
	}

}


BOOL CTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_GoodCombo.AddString("��Ѫɢ");
	m_GoodCombo.AddString("������");
	m_GoodCombo.SetCurSel(0);


	m_SayCombo.AddString("����Ƶ��");
	m_SayCombo.AddString("����Ƶ��");
	m_SayCombo.AddString("ͬ��Ƶ��");
	m_SayCombo.AddString("����Ƶ��");
	m_SayCombo.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CTestDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDWordArray dwList;
	//GameHelper helper;
	//helper.TraverseBagProps(dwList);
}


void CTestDlg::OnCbnSelchangeCombo2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


/*
0-3����Ϸ�г�����ֵ
4-7��û������ֵ����Դ����ֵΪ0Ҳ�����
8-11��0
12-15��FF FF FF FF �̶�ֵ
16���������ͣ�0 ��ǰ��02 ����, 0B ͬ��, 07 ���ɣ�
17-19��û������ֵ����Դ����ֵΪ0Ҳ�����
20-23��[[9B2AE4]+70]+610
24���������ݵĳ���
�����ֽ�-----��������
*/
#pragma pack(push)
#pragma pack(1)
struct _SAYPACK
{
	BYTE paramer1[24];
	BYTE bLength;
	char szContent[255];
};
#pragma pack()
#pragma pack(pop)

void CTestDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItemText(IDC_EDIT2, str);
	if (str.IsEmpty())
	{
		return;
	}

	//char szContent[255] = {0};
	//GetDlgItemText(IDC_EDIT2, szContent, 255);
	//if (strlen(szContent) == 0)
	//{
	//	return;
	//}
	_SAYPACK sayPack;

	memset(&sayPack, 0, sizeof(_SAYPACK));

    try
	{
		//��ʼ��ǰ24���ֽ�
		//__asm
		//{
		//	pushad;
		//	lea ecx, sayPack;
		//	mov esi, ecx;
		//	mov ebx,0x00758B80;		
		//	call ebx;
		//	popad;
		//}

		(DWORD &)sayPack.paramer1[0] = 0x84EACC;
		(DWORD &)sayPack.paramer1[4] = 0;
		(DWORD &)sayPack.paramer1[8] = 0;
		(DWORD &)sayPack.paramer1[12] = 0xFFFFFFFF;
		sayPack.paramer1[16] = 0;	//����Ƶ��
		(DWORD &)sayPack.paramer1[17] = 0;
		DWORD dwBase = * (DWORD *)0x9B2AE4;
		dwBase = *(DWORD *) (dwBase + 0x70);
		dwBase = *(DWORD *) (dwBase + 0x610);
		(DWORD &)sayPack.paramer1[20] = dwBase;
		sayPack.bLength= str.GetLength();//strlen(szContent);
		memcpy(sayPack.szContent, str, str.GetLength());

		__asm
		{
			pushad;
			mov ecx,0x1320B2C;
			mov ecx,[ecx];
			lea edx, sayPack;
			push edx;
			mov eax, 0x0065A0C0;
			call eax;
			popad;
		}
	}
	catch (...)
	{

	}
}


void CTestDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ROLE role;
	TRACE("��ɫ�ĵ�ǰѪֵ��%d\n", role.dwCurrentBlood);
	TRACE("��ɫ�����Ѫֵ��%d\n", role.dwMaxBlood);
	TRACE("��ɫ�ĵ�ǰ��ֵ��%d\n", role.dwCurrentMagic);
	TRACE("��ɫ�������ֵ��%d\n", role.dwMaxMagic);
	TRACE("��ɫ�ĵ�ǰ����ֵ��%d\n", role.dwCurrentEnergy);
	TRACE("��ɫ��������ֵ��%d\n", role.dwMaxEnergy);
	TRACE("��ɫ�ĵ�ǰ����ֵ��%d\n", role.dwCurrentPower);
	TRACE("��ɫ�������ֵ��%d\n", role.dwMaxPower);
	TRACE("��ɫ���֣�%s\n", role.pName);
	TRACE("��ɫ�ĵȼ���%d\n", role.dwLevel);
	TRACE("��ɫ�Ľ��ӣ�%d\n", role.dwBindMoney);
	TRACE("��ɫ�Ľ�ң�%d\n", role.dwMoney);

	TRACE("��ɫX���꣺%f", role.x);
	TRACE("��ɫy���꣺%f", role.y);
}


void CTestDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GameHelper helper;
	CDWordArray baseArray;
	helper.TraverseMonster(baseArray);
}
