#include "StdAfx.h"
#include "DataHelp.h"
#include "StructDef.h"
#include <exception>
#include "BaseAddr.h"

DataHelp::DataHelp(void)
{
}


DataHelp::~DataHelp(void)
{
	
}


/************************************************************************/
/* ����˵��������������ɨ���ַ
/* ����һ��markCode �������ַ���,�����пո�
/* �����������������ַ�ľ��룬Ĭ�Ͼ��룺1
/* ��������findMode ɨ�跽ʽ���ҵ��������Ĭ��Ϊ��1
/*                  0�������һ�ַ���������ڻ�ַ���棩
/*                  1�������һ�ַ���������ڻ�ַ���棩
/* �����ģ�offset �����ַ������̵�ƫ�ƣ�Ĭ��Ϊ��������
/************************************************************************/
DWORD DataHelp::ScanAddress(const char *markCode, DWORD distinct /* = 1 */, DWORD findMode /* = 1 */, LPDWORD offset /* = NULL */) {
	//��ʼ��ַ
	const DWORD beginAddr = 0x00400000;
	//������ַ
	const DWORD endAddr = 0x7FFFFFFF;
	//ÿ�ζ�ȡ��Ϸ�ڴ���Ŀ�Ĵ�С
	const DWORD pageSize = 4096;
	////////////////////////����������/////////////////////
	//�����볤�Ȳ���Ϊ����
	if (strlen(markCode) % 2 != 0) return 0;
	//�����볤��
	int len = strlen(markCode) / 2;
	//��������ת����byte��
	BYTE *m_code = new BYTE[len];
	for (int i = 0; i < len; i++){
		char c[] = {markCode[i*2], markCode[i*2+1], '\0'};
		m_code[i] = (BYTE)::strtol(c, NULL, 16);
	}
	/////////////////////////����������/////////////////////
	BOOL _break = FALSE;
	//���������ڵڼ�ҳ�еĵڼ����ҵ���������
	int curPage = 0;
	int curIndex = 0;
	Base base;
	//ÿҳ��ȡ4096���ֽ�
	BYTE page[pageSize];
	DWORD tmpAddr = beginAddr;
	while (tmpAddr <= endAddr - len){
		//::ReadProcessMemory(process, (LPCVOID)tmpAddr, &page, pageSize, 0);
		memcpy(page, (int*)tmpAddr, pageSize);
		//�ڸ�ҳ�в���������
		for (int i = 0; i < pageSize; i++){
			for (int j = 0; j < len; j++){
				//ֻҪ��һ�����������Ӧ�������˳�ѭ��
				if (m_code[j] != page[i + j])break;
				//�ҵ��˳�����ѭ��
				if (j == len - 1){
					_break = TRUE;
					if (!findMode){
						curIndex = i;
						base.data[0] = page[curIndex-distinct-4];
						base.data[1] = page[curIndex-distinct-3];
						base.data[2] = page[curIndex-distinct-2];
						base.data[3] = page[curIndex-distinct-1];
					}else{
						curIndex = i + j;
						base.data[0] = page[curIndex+distinct+1];
						base.data[1] = page[curIndex+distinct+2];
						base.data[2] = page[curIndex+distinct+3];
						base.data[3] = page[curIndex+distinct+4];
					}
					break;
				}
			}
			if (_break) break;
		}
		if (_break) break;
		curPage++;
		tmpAddr += pageSize;
	}
	if(offset != NULL){
		*offset = curPage * pageSize + curIndex + beginAddr;
	}

	delete []m_code;
	return base.address;
}

/************************************************************************/
/* ����˵��������������ɨ��call��ַ
/* ����һ��markCode �������ַ���,�����пո�
/* �����������������ַ�ľ��룬Ĭ�Ͼ��룺1
/* ��������findMode ɨ�跽ʽ���ҵ��������Ĭ��Ϊ��1
/*                  0�������һ�ַ
/*                  1�������һ�ַ
/************************************************************************/
DWORD DataHelp::ScanCall(const char *markCode, DWORD distinct /* = 1 */, DWORD findMode /* = 1 */) {
	DWORD offset;
	DWORD call = ScanAddress(markCode, distinct, findMode, &offset);
	call += offset;
	if(findMode) call = call + 5 + distinct;
	else call = call - distinct;
	return call;
}

/*
const char g_szRoleCode[] = "8B46108B1150FF52488BD885";			//�������Ի�ַ������
const char g_szMapCode[]  = "8B1183F8010F94C0508B4650";			//��ǰ��ͼ������
const char g_szPickParamCode[] = "8B56088B0152FF9080000000";	//�ɼ�����������ַ������
const char g_szAutoRunCode[] = "8945CC8B46108B55CC5051";		//�Զ�Ѱ·CALL��ַ������(ͬһ��ͼ)
const char g_szPickAllCode[] = "8B01FF90AC01000033C0C20400";	//��ȡȫ����ַ������(����ױ�)
const char g_szIsEnemyCode[] = "8D55B45256C745B4000000008B0157";//�ж��Ƿ��ǹ�������
const char g_szSelectedEnemyCode[] = "8B46088B116A0150FF523C";	//ѡ��������
const char g_szUserSkillCode[] = "0FBF96840000005051528BCE";	//ʹ�ü���������
const char g_szOpenPackageDlg[] = "8B46088B760C56508BCF";		//�򿪰���CALL������
const char g_szBagPropsBaseCode[] = "0FB658128B06578BCEFF90D8000000";	//���߱�����ַ������
const char g_szUseGoodsCode[] = "8995A4FEFFFF8985A8FEFFFFE8";	//ʹ����ƷCALL��������ַ������
*/

//������Ϸ��ַ
void DataHelp::UpdateGameData() {
	try
	{
		GameBaseAddr = ScanAddress("8B46108B1150FF52488BD885", 0, 0);	//�����ַ
		PackageBaseAddr = ScanAddress("0FB658128B06578BCEFF90D8000000", 0, 0);	//������ַ
		UseGoodsPacketInitCall = ScanCall("8B06BB100000008BCE895DFCFF5030", 0, 0);
		UseGoodsCallParam = ScanAddress("8995A4FEFFFF8985A8FEFFFFE8",0, 0);
		UseGoodsCall = ScanCall("8995A4FEFFFF8985A8FEFFFFE8", 0, 1);
		JudgeCallAddr = ScanAddress("8D55B45256C745B4000000008B01", 0, 0);
		SelectMonsterCallAddr = ScanAddress("8B46088B116A0150FF523C8B87D8000000", 0, 0);
		UseSkillCall = ScanCall("528B55C4525156508BCFE8", 0, 1);
		TRACE("��ɫ��ַ��%08X\n",GameBaseAddr);
		TRACE("������ַ��%08X\n",PackageBaseAddr);
		TRACE("ʹ����Ʒ������ݳ�ʼ��CALL��%08X\n",UseGoodsPacketInitCall);
		TRACE("ʹ����ƷCALL������%08X\n",UseGoodsCallParam);
		TRACE("ʹ����ƷCALL��%08X\n",UseGoodsCall);
		TRACE("�ж϶���С��Call��ַ��%08X\n",JudgeCallAddr);
		TRACE("ѡ��CALL��ַ��%08X", SelectMonsterCallAddr);
		TRACE("ʹ�ü���CALL��%08X", UseSkillCall);
	}
	catch (std::exception ex)
	{
		AfxMessageBox(ex.what());
	}
}