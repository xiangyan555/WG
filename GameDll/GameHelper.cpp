#include "StdAfx.h"
#include "GameHelper.h"
#include "StructDef.h"
#include "ConstantDef.h"

extern DWORD GameBaseAddr;			//��Ϸ��ַ����ɫ�����ﹲ�ã�
extern DWORD PackageBaseAddr;		//�����׵�ַ
extern DWORD UseGoodsPacketInitCall;	//��ʼ��ʹ����Ʒ���CALL
extern DWORD UseGoodsCallParam;		//ʹ����ƷCALL�Ĳ���
extern DWORD UseGoodsCall;				//ʹ����ƷCALL	
extern DWORD JudgeCallAddr;			//�ж϶����ǹ��NPC������CALL
GameHelper::GameHelper(void)
{
	srand( (unsigned)time( NULL ) );
}


GameHelper::~GameHelper(void)
{
	
}

//����ר��
void GameHelper::Test() {

}

//ʹ����Ʒ
BOOL GameHelper::UseGoods(CString strGoodsName)
{
	BOOL		bRet = TRUE;
	GoodsPacket packet;	//���ݰ�
	DWORD dwTmp;
	memset(&packet, 0, sizeof(GoodsPacket));
	try
	{
		__asm
		{
			pushad;
			lea		ecx, packet;
			mov		eax, UseGoodsPacketInitCall;		//��ʼ��
			call	eax;
			popad;
		}

		if (GetGoodsInfoByName(strGoodsName, packet))
		{
			dwTmp = *(DWORD *)GameBaseAddr;
			dwTmp = *(DWORD *)(dwTmp + ROLE_OFFSET_1);
			packet.dw_Param_32_35 = *(DWORD *)(dwTmp + ROLE_NAME_OFFSET);
			packet.dw_Param_36_39 = *(DWORD *)(dwTmp + ROLE_UNKNOWN_OFFSET);
			packet.dw_Param_40_43 = *(DWORD *)(dwTmp + ROLE_UNKNOWN_OFFSET);

				__asm
				{
					pushad;
					lea		ecx, packet;
					push	ecx;
					mov		ebx, UseGoodsCallParam;
					mov		ecx, [ebx];
					mov		eax, UseGoodsCall;
					call	eax;
					popad;
				}
		}
	}
	catch (...) 
	{

	}


	return bRet;
}

//�������ֻ����Ʒ��Ϣ��������ݰ�
BOOL GameHelper::GetGoodsInfoByName(CString strGoodsName, GoodsPacket &goodsPacket)
{
	BYTE	bySize;		//�����Ĵ�С
	DWORD	dwGoodsObj;	//��Ʒ����
	BYTE	byPos;	//�ڱ����е�λ��
	BOOL	bFlag = FALSE;	//��û�ҵ�
	DWORD	dwTmp;
	GoodsInfo goodsInfo;
	memset(&goodsInfo, 0, sizeof(GoodsInfo));
	dwTmp = *(DWORD *)PackageBaseAddr;
	bySize = * (BYTE *) (dwTmp + BAG_PROPS_SPACE_OFFSET);
	dwTmp = *(DWORD *)(dwTmp + BAG_PROPS_HEAD_OFFSET);
	for (BYTE i = 0; i < bySize; i++ )
	{
		dwGoodsObj = * (DWORD *) (dwTmp + i * 4);		//�����Ʒ����
		if (dwGoodsObj)		//������ǿ�
		{
			GoodsInfo tmp(dwGoodsObj);
			//TRACE("%sλ��%d��\n", tmp.pGoodsName, i);
			if (strGoodsName == tmp.pGoodsName)
			{
				byPos = i;
				memcpy(&goodsInfo, &tmp, sizeof(GoodsInfo));
				bFlag = TRUE;
				break;
			}
		}
	}

	if (!bFlag)
	{
		return bFlag;
	}

	goodsPacket.b_Pos_16 = byPos;
	goodsPacket.dw_Param_20_23 = goodsInfo.dwUnknown_14_8;
	goodsPacket.dw_Param_24_27 = goodsInfo.dwUnknown_14_0;
	goodsPacket.dw_Param_28_31 = goodsInfo.dwUnknown_14_4;

	return bFlag;

}

void GameHelper::TraverseMonster(CDWordArray &monsterNodes)
{
	DWORD dwBase = *(DWORD *)GameBaseAddr;
	dwBase = *(DWORD *)(dwBase + MONSTER_OFFSET);
	dwBase = *(DWORD *)(dwBase + ENV_TREE_LEFT_OFFSET);
	TraverseMonster(monsterNodes, dwBase);
}

void GameHelper::TraverseMonster(CDWordArray &monsterNodes, DWORD dwBase)
{
	BYTE byFlag;
	DWORD dwRole;
	DWORD dwParam = 0;
	DWORD dwMonsterObj;
	DWORD dwRet;
	byFlag = *(BYTE *)(dwBase + ENV_TREE_FLAG_OFFSET);
	if (byFlag == 0)
	{
		MonsterInfo monster(dwBase);
		if (monster.dwType == TYPE_MONSTER)
		{
			dwRole = *(DWORD *)GameBaseAddr;
			dwRole = *(DWORD *)(dwRole + ROLE_OFFSET_1);

			dwMonsterObj = * (DWORD *)(dwBase + MONSTER_OBJECT_OFFSET);
			__asm
			{
				pushad;
				mov ecx,JudgeCallAddr;
				mov ecx,[ecx];
				push dwParam;
				push dwMonsterObj;
				mov eax,[ecx];
				push dwRole;
				call [eax+0xFC];
				mov dwRet,eax;
				popad;
			}

			if (dwRet == 0)
			{
				TRACE("����:%s--ID:%08X--X:%f--Y:%f\n", monster.pName, monster.dwID, monster.x, monster.y);
				monsterNodes.Add(dwBase);
			}
		}
	}

}

//void GameHelper::DoAction(DWORD actionID)  {
//	//__try {
//	//	__asm {
//	//		push 0xbf800000;
//	//		push 0xbf800000;
//	//		push 0xbf800000;
//	//		push -1;
//	//		push -1;
//	//		push actionID;
//	//		call ACTION_CALL;
//	//	}
//	//}
//	//__except (EXCEPTION_EXECUTE_HANDLER) {
//	//	OutputDebugString("ִ�ж���ʧ��");
//	//}
//}
//
//void GameHelper::TraverseEnemy(CList<Enemy, Enemy&> &enemyList, DWORD dwBaseAddr) {
//	//TRACE("addr = %X \n", dwBaseAddr);
//	__try {
//		BYTE *pFlag = (BYTE *)(dwBaseAddr + 0x15);
//		if (*pFlag == 0)
//		{
//			DWORD *pBase = (DWORD*)(dwBaseAddr + 0x10);
//			if (*pBase != 0)
//			{
//				pBase = (DWORD*)(*pBase + 0x2C);
//				pBase = (DWORD*)(*pBase + 0x18);
//				
//				
//				if (*pBase == 3)	//����
//				{
//					DWORD dwOffset = *(DWORD*)(dwBaseAddr + 0x10);
//					DWORD dwSS = *(DWORD *)(0x9A44CC);
//					dwSS = *(DWORD *)(dwSS + 0x70);
//					DWORD dwRet;
//					DWORD dwTmp = 0;
//					__asm {
//						pushad;
//						mov ecx,0x1313830;
//						mov ecx,[ecx];
//						lea edx,dwTmp;
//						push edx;
//						push dwOffset;
//						mov eax,[ecx];
//						mov edi,dwSS;
//						push edi;
//						call [eax+0xFC];
//						mov dwRet,eax;
//						popad;
//					}
//					dwOffset = *(DWORD *)(dwOffset + 0x1e0);
//					dwOffset = *(DWORD *)(dwOffset + 0x4);
//					char *name = (char*)(dwOffset + 0x34);
//					TRACE("����=%s,С��ID=%X\n",name, dwRet);
//				}
//
//				TraverseEnemy(enemyList, *(DWORD *)dwBaseAddr);
//
//				DWORD *pRight = (DWORD *)(dwBaseAddr + 0x8);
//				TraverseEnemy(enemyList, *pRight);
//			}
//		}
//		
//	} 
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		OutputDebugString("�������������ʱ����\n");
//	}
//}
//
//void GameHelper::TraverseEnemy(CList<Enemy, Enemy&> &enemyList) {
//	DWORD *pBase = (DWORD*)0x9A44CC; 
//	pBase = (DWORD*)(*pBase + 0x64);
//	pBase = (DWORD*)(*pBase + 0x4);
//	TraverseEnemy(enemyList, *pBase);
//}
//
//DWORD GameHelper::SelectedEnemy(DWORD dwObj) {
//	DWORD dwID = Call_GetItem_ID(dwObj);
//	TRACE("����ID=%X\n", dwID);
//	if (dwID != -1)
//	{
//		Call_SelectEnemy(dwID);
//	}
//
//	return dwID;
//}
//
//void GameHelper::GetRoleInfo(Role &role) {
//	//__try {
//	//	DWORD dwOffset = *(DWORD *)g_BaseAddrInfo.dwRoleBaseAddr;
//	//	dwOffset = *(DWORD *)(dwOffset + 0x70);
//	//	dwOffset = *(DWORD *)(dwOffset + 0x1E0);
//	//	dwOffset = *(DWORD *)(dwOffset + 0x4);
//	//	char *name = (char*) (dwOffset + 0x34);
//	//	role.pName = name;
//	//	DWORD dwCurrentBlood = *(DWORD *) (dwOffset + 0x2478);
//	//	role.dwCurrentBlood = dwCurrentBlood;
//	//	DWORD dwMaxBlood = *(DWORD *)(dwOffset + 0x24F8);
//	//	role.dwMaxBlood = dwMaxBlood;
//	//	DWORD dwCurrentMagic = *(DWORD *)(dwOffset + 0x247c);
//	//	role.dwCurrentMagic = dwCurrentMagic;
//	//	DWORD dwMaxMagic = *(DWORD *)(dwOffset + 0x24Fc);
//	//	role.dwMaxMagic = dwMaxMagic;
//	//	DWORD dwCurrentEnergy = *(DWORD *)(dwOffset + 0x248c);
//	//	role.dwCurrentEnergy = dwCurrentEnergy;
//	//	DWORD dwMaxEnergy = *(DWORD *)(dwOffset + 0x2490);
//	//	role.dwMaxEnergy = dwMaxEnergy;
//	//	DWORD dwCurrentPower = *(DWORD *)(dwOffset + 0x2494);
//	//	role.dwCurrentPower = dwCurrentPower;
//	//	DWORD dwMaxPower = *(DWORD *)(dwOffset + 0x2498);
//	//	role.dwMaxPower = dwMaxPower;
//	//	DWORD dwCurrentLv = *(DWORD *)(dwOffset + 0x64);
//	//	role.dwLevel = dwCurrentLv;
//	//	DWORD dwCurrentExp = *(DWORD *)(dwOffset + 0x2480);
//	//	role.dwCurrentExp = dwCurrentExp;
//	//	
//	//	//��ȡ��ͼ��
//	//	dwOffset = *(DWORD *)g_BaseAddrInfo.dwMapBaseAddr;
//	//	dwOffset = *(DWORD *)(dwOffset + 0x448C);
//	//	char *pMapName = (char *)(dwOffset + 0x68);
//	//	role.pMapName = pMapName;
//
//	//	//��ȡ����
//	//	dwOffset = *(DWORD *)0x1300774;
//	//	dwOffset = *(DWORD *)(dwOffset + 0x78);
//	//	dwOffset = *(DWORD *)(dwOffset + 0x24);
//	//	dwOffset = *(DWORD *)(dwOffset + 0x4);
//	//	dwOffset = *(DWORD *)(dwOffset + 0x8);
//	//		
//	//	role.x = *(float *)(dwOffset + 0x48);
//	//	role.y = *(float *)(dwOffset + 0x50);
//	//}
//	//__except (EXCEPTION_EXECUTE_HANDLER) {
//	//	AfxMessageBox("��ȡ��ɫ��Ϣʱ����");
//	//}
//}
//
//void GameHelper::AutoFight(DWORD dwEnemy) {
//	DWORD dwID = Call_GetItem_ID(dwEnemy);
//	TRACE("����ID=%X\n", dwID);
//	UseSkill(SKILL_ID_LUOYINGJIAN, dwID);
//	//UseHotKey(0);
//	float f ;
//	while (f = Call_GetObj_Blood(dwEnemy) != 0) {
//		TRACE("Ѫֵ=%f\n",f);
//		Sleep(1000);
//	}
//	TRACE("Ѫֵ=%f\n",f);
//	//Sleep(3000);
//}
//
//float GameHelper::GetEnemyBlood(DWORD dwObj) {
//	return Call_GetObj_Blood(dwObj);
//}
//
////�ж��Ƿ�ѡ�й���
//DWORD GameHelper::IsSelectedEnemy() {
//	/*DWORD dwBase = 0x0094AC38;
//	DWORD dwResult = 0; 
//	__try {
//		__asm {
//			pushad;
//			mov eax, dwBase;
//			mov eax,[eax];
//			mov eax,[eax];
//			add eax,0xC;
//			mov eax,[eax];
//			add eax,0x64;
//			mov eax, [eax];
//			mov dwResult, eax;
//			popad;
//		}
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		OutputDebugString("�ж��Ƿ�ѡ�й�CALL����");
//	}
//
//	return dwResult;*/
//	return 0;
//}
//
////ѡ������Ĺ���
//DWORD GameHelper::SelectNearEnemy(float x, float y, CDWordArray &enemyList) {
//	DWORD dwRet = -1;
//	DWORD dwObj;
//	DWORD dwMinMeter = 0;	//��С�ľ���
//	for (int i = 0; i < enemyList.GetCount(); i++)
//	{
//		dwObj = enemyList.GetAt(i);
//		float x1 = Call_GetItem_X(dwObj);
//		float y1 = Call_GetItem_Y(dwObj);
//		DWORD dwTmp = CalculateDistance(x, y, x1, y1);
//		if (dwTmp < 16)
//		{
//			if (dwMinMeter == 0)
//			{
//				dwMinMeter = dwTmp;
//				dwRet = dwObj;
//			} else {
//				if (dwTmp < dwMinMeter)
//				{
//					dwMinMeter = dwTmp;
//					dwRet = dwObj;
//				}
//			}
//		}
//		
//	}
//	
//	return dwRet;
//
//}
//
//void GameHelper::UseSkill(DWORD dwSkillID, DWORD dwEnemyID) {
//	Call_UseSkill(dwSkillID, dwEnemyID);
//}
//
//void GameHelper::UseHotKey(DWORD dwKey) {
//	Call_UseHotKey(0);
//}
//
////��������
////dwType Ҫ����������
////dwKind �ĸ�ֲ����ʯ
////objList ���صĶ����б�
//void GameHelper::TraverseEnver(DWORD dwBaseAddr, DWORD dwType, CList<DWORD, DWORD> &kindList, CDWordArray &objList) {
//	BYTE bFlag = Call_GetFlag(dwBaseAddr, 0x15);
//
//	if (bFlag == 0)
//	{
//		DWORD _dwType = Call_GetObjType(dwBaseAddr);
//
//		if (_dwType == dwType)
//		{
//			if (_dwType == TYPE_VEGETATION)	//�ɼ���
//			{
//				DWORD _dwKind = Call_GetKindOfObj(dwBaseAddr);
//				
//				if (kindList.Find(_dwKind) != NULL)
//				{
//					DWORD dwObj = Call_GetObject(dwBaseAddr);
//					objList.Add(dwObj);
//				}
//			}
//			else if (_dwType == TYPE_ENEMY) {	//����
//				DWORD dwObj = Call_GetObject(dwBaseAddr);
//				if (Call_IsEnemy(dwObj) == 0)
//				{
//					if (Call_GetObj_Blood(dwObj) > 0)
//					{
//						objList.Add(dwObj);
//					}
//					
//				}
//			} 
//			else if (_dwType == TYPE_PACKAGE) {	//����
//				DWORD dwObj = Call_GetObject(dwBaseAddr);
//				if (Call_GetObjClassID(dwObj) != TYPE_CLASS_SELF)	//�������Լ�
//				{
//					if ((int)Call_GetItem_ID(dwObj) > 0)
//					{
//						objList.Add(dwObj);
//					}
//				}
//			}
//		}
//
//		TraverseEnver(*(DWORD *)dwBaseAddr, dwType, kindList, objList);
//		TraverseEnver(*(DWORD *)(dwBaseAddr + 0x8), dwType, kindList, objList);
//	}
//	
//}
//
////*******************************************
////˵���������Χ�ɲɼ���ֲ���б�
////������DWORD dwKind��Ҫ�ɼ�������ֲ��ID
////������CDWordArray &objList�����Բɼ��Ķ����ַ�б�
////����ֵ����
////*******************************************
//void GameHelper::GetRoundVegetation(CList<DWORD,DWORD> &kindList, CDWordArray &objList) {
//	DWORD dwBaseAddr = Call_GetEnvirLeftTree();
//	TraverseEnver(dwBaseAddr, TYPE_VEGETATION, kindList, objList);
//}
//
//void GameHelper::GetRoundEnemy(CDWordArray &objList) {
//	DWORD dwBaseAddr = Call_GetEnvirLeftTree();
//	CList<DWORD,DWORD> kindList;
//	TraverseEnver(dwBaseAddr, TYPE_ENEMY, kindList, objList);
//}
//
//void GameHelper::GetRoundPackage(CDWordArray &objList) {
//	DWORD dwBaseAddr = Call_GetEnvirLeftTree();
//	CList<DWORD,DWORD> kindList;
//	TraverseEnver(dwBaseAddr, TYPE_PACKAGE, kindList, objList);
//}
//
//void GameHelper::GetItemObj(DWORD dwAddr, ItemInfo &itemInfo) {
//	float x = Call_GetItem_X(dwAddr);
//	float y = Call_GetItem_Y(dwAddr);
//	DWORD ID = Call_GetItem_ID(dwAddr);
//
//	itemInfo.x = x;
//	itemInfo.y = y;
//	itemInfo.ID = ID;
//}
//
////�ɼ���Ʒ
//void GameHelper::PickGoods(DWORD dwPackID) {
//	Call_Pick_Action(dwPackID);	//�ɼ�����
//	DWORD dwStatus = 0;
//	do 
//	{
//		Sleep(1000); 
//		dwStatus = GetRoleStatus();
//	} while (dwStatus == 0x8);
//
//	Call_Pick_All();	//ʰȡȫ��
//}
//
////�ɼ���Ʒ
//void GameHelper::PickGoods(CDWordArray &objList) {
//	if (objList.GetCount() > 0)
//	{
//		for (int i = 0; i < objList.GetCount(); i++)
//		{
//			DWORD dwAddr = objList.GetAt(i);
//			ItemInfo info;
//			GetItemObj(dwAddr, info);
//			AutoRun(info.x, info.y);
//			DWORD dwStatus = 0;
//			do 
//			{
//				Sleep(1000);
//				dwStatus = GetRoleStatus();
//			} while (dwStatus == 0x2);
//
//			PickGoods(info.ID);	//�ɼ�
//		}
//	}
//}
//
////��ý�ɫ״̬
//DWORD GameHelper::GetRoleStatus() {
//	return Call_GetRoleStatus();
//}
//
////�Զ�Ѱ·
//void GameHelper::AutoRun(float x, float y) {
//	DWORD dwX = FloatToHex(x);
//	DWORD dwY = FloatToHex(y);
//	Call_AutoRun(dwX, dwY);
//}
//
////��һ��Ҫ�ƶ��ĵص�����
//void GameHelper::GetNextPoint(CPoint &point) {
//	point.x = GetRandNum(40, 290);
//	point.y = GetRandNum(40, 290);
//}
//
////��õ�ǰ��ͼ����
//char *GameHelper::GetCurrentMap() {
//	return Call_GetCurrentMap();
//}
//
////ʰȡ����İ���
//void GameHelper::CollectGoods(CDWordArray &objList) {
//	DWORD dwPackID;
//	for (int i = 0; i < objList.GetCount(); i++) {
//		dwPackID = Call_GetItem_ID(objList.GetAt(i));
//		CollectGoods(dwPackID);
//	}
//}
//
////ʰȡ����İ���
//void GameHelper::CollectGoods(DWORD dwID) {
//	TRACE("����ID=%X\n", dwID);
//	Call_OpenPackageDlg(dwID);	//�򿪰����Ի���
//	DWORD dwStatus = 0;
//	do 
//	{
//		Sleep(1000); 
//		dwStatus = GetRoleStatus();
//	} while (dwStatus == 0x2);
//
//	Call_Pick_All();	//ʰȡȫ��
//	Sleep(500);
//}
//
//DWORD GameHelper::GetRoleEnergy() {
//	return Call_GetRoleEnergy();
//}
//
//DWORD GameHelper::GetRolePower() {
//	return Call_GetRolePower();
//}
//
//void GameHelper::GetRolePos(CPoint &point) {
//	DWORD x = (DWORD)Call_GetRole_X();
//	DWORD y = (DWORD)Call_getRole_Y();
//	point.x = x;
//	point.y = y;
//}
//
//float GameHelper::GetRolePosX() {
//	return Call_GetRole_X();
//}
//
//float GameHelper::GetRolePosY() {
//	return Call_getRole_Y();
//}
//
//DWORD GameHelper::SelectNextEnemy() {
//	CDWordArray enemyList;
//	DWORD dwObj = -1;
//	GetRoundEnemy(enemyList);
//	if (enemyList.GetCount() > 0)
//	{
//		float f_x = GetRolePosX();
//		float f_y = GetRolePosY();
//		dwObj = SelectNearEnemy(f_x, f_y, enemyList);
//		if (dwObj > 0) {
//			SelectedEnemy(dwObj);
//			return dwObj;
//		}
//	}
//	return dwObj;
//}
//
//void GameHelper::CollectAllItem() {
//	CDWordArray packList;
//	GetRoundPackage(packList);
//	if (packList.GetCount() > 0)
//	{
//		CollectGoods(packList);	//�����
//	}
//}
//
//char *GameHelper::GetRoleName() {
//	return Call_GetRoleName();
//	
//}
//
////�������߱���
//void GameHelper::TraverseBagProps(CDWordArray &objList)
//{
//	BYTE bNum = Call_GetBagPropsNum();
//	DWORD dwBagPropsHeadAddr = Call_GetBagPropsHeadAddr();
//	DWORD dwGoodsObject;
//	char *pGoodsName= NULL;
//	for (int i = 0; i < bNum; i++ )
//	{
//		dwGoodsObject = * (DWORD *) (dwBagPropsHeadAddr + i * 4);
//		if (dwGoodsObject)
//		{
//			pGoodsName = Call_GetBagGoodsName(dwGoodsObject);
//			TRACE("��%d�����Ʒ�����ǣ�%s\n", i, pGoodsName);
//		}
//	}
//}
