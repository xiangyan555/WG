#include "StdAfx.h"
#include "GCall.h"
#include "StructDef.h"
#include "ConstantDef.h"


GCall::GCall(void)
{
}


GCall::~GCall(void)
{
}

//�Զ�Ѱ·
//void GCall::Call_AutoRun(DWORD x, DWORD y) {
//	__try {
//		DWORD dwBase = *(DWORD *)g_BaseAddrInfo.dwRoleBaseAddr;
//		dwBase = *(DWORD *)(dwBase + 0x70);
//		dwBase = *(DWORD *)(dwBase + 0x1f0);
//		DWORD dwCallAddr = g_BaseAddrInfo.AutoRunCall;
//		__asm {
//			pushad;
//			push 0;
//			push 1;
//			push y;
//			push x;
//			mov eax,dwCallAddr;
//			call eax;
//			popad;
//		}
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("�Զ�Ѱ·CALL����!\n");
//	}
//}
//
////�ɼ�����CALL
//void GCall::Call_Pick_Action(DWORD dwID) {
//	__try {
//		DWORD dwBase = g_BaseAddrInfo.dwPickActionBaseAddr;
//		__asm {
//			pushad;
//			mov ecx,dwBase;
//			mov ecx,[ecx];
//			mov eax,[ecx];
//			mov edx,dwID;
//			push edx;
//			call [eax+0x80];
//			popad;
//		}
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("���òɼ�����CALL����\n");
//	}
//}
//
////ʰȡȫ��CALL
//void GCall::Call_Pick_All() {
//	__try {
//		DWORD dwBase = g_BaseAddrInfo.PickAllBaseAddr;
//		__asm {
//			pushad;
//			mov ecx, dwBase;
//			mov ecx, [ecx];
//			mov eax, [ecx];
//			call [eax+0x1AC];
//			popad;
//		}
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("����ʰȡȫ��CALL����\n");
//	}
//}
//
///************************************************************************/
///* ���ﵱǰ״̬ 0--��������   2--�ܶ���   5---������  6--����  7--ս����  8--�ɼ���*/ 
///************************************************************************/
//DWORD GCall::Call_GetRoleStatus() {
//	DWORD dwOffset = *(DWORD *)g_BaseAddrInfo.dwRoleBaseAddr;
//	DWORD dwStatus = -1;
//	__try
//	{
//		dwOffset = *(DWORD *)(dwOffset + 0x70);
//		dwStatus = *(DWORD *)(dwOffset + 0x1e8);
//		return dwStatus;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("��ȡ����״̬����\n");
//	}
//
//	return dwStatus;
//}
//
////��õ�ǰ��ͼ����
//PCHAR GCall::Call_GetCurrentMap() {
//		DWORD dwOffset = *(DWORD *)g_BaseAddrInfo.dwMapBaseAddr;
//		PCHAR pMapName = NULL;
//		__try {
//			dwOffset = *(DWORD *)(dwOffset + 0x46CC);
//			pMapName = (PCHAR)(dwOffset + 0x68);
//			return pMapName;
//		}
//		__except (EXCEPTION_EXECUTE_HANDLER) {
//			TRACE("��ȡ��ǰ��ͼ����\n");
//		}
//		return pMapName;
//}
//
////��������������
//DWORD GCall::Call_GetEnvirLeftTree() {
//	DWORD dwOffset = *(DWORD *)g_BaseAddrInfo.dwRoleBaseAddr;
//	dwOffset = *(DWORD *)(dwOffset + 0x64);
//	dwOffset = *(DWORD *)(dwOffset + 0x4);
//	return dwOffset;
//}
//
////��ö�������
//DWORD GCall::Call_GetObjType(DWORD dwAddr) {
//	DWORD dwType = -1;
//	__try {
//		DWORD dwOffset = *(DWORD *)(dwAddr + 0x10);
//		dwOffset = *(DWORD *)(dwOffset + 0x2C);
//		dwOffset = *(DWORD *)(dwOffset + 0x18);
//		dwType = dwOffset;
//		return dwType;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("��ȡ��������ʱ����\n");
//	}
//	return dwType;
//}
//
//
//DWORD GCall::Call_GetKindOfObj(DWORD dwAddr) {
//	DWORD dwType = -1;
//	__try {
//		DWORD dwOffset = *(DWORD *)(dwAddr + 0x10);
//		dwOffset = *(DWORD *)(dwOffset + 0x118);
//		dwOffset = *(DWORD *)dwOffset;
//		dwType = dwOffset;
//		return dwType;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("��ȡ��������ʱ����\n");
//	}
//	return dwType;
//}
//
//DWORD GCall::Call_GetObject(DWORD dwAddr) {
//	return *(DWORD *)(dwAddr + 0x10);
//}
//
//BYTE GCall::Call_GetFlag(DWORD dwAddr, DWORD dwOffset) {
//	return *(BYTE *)(dwAddr + dwOffset);
//}
//
//float GCall::Call_GetItem_X(DWORD dwAddr) {
//	return *(float *)(dwAddr + 0x48);
//}
//
//float GCall::Call_GetItem_Y(DWORD dwAddr) {
//	return *(float *)(dwAddr + 0x50);
//}
//
//DWORD GCall::Call_GetItem_ID(DWORD dwAddr) {
//	DWORD dwID = -1;
//	__try {
//		dwID =  *(DWORD *)(dwAddr + 0x34);
//		return dwID;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("��ö���IDʱ����\n");
//	}
//	return dwID;
//}
//
////��ý�ɫ����
//DWORD GCall::Call_GetRoleObject() {
//	DWORD dwObject = -1;
//	__try {
//		DWORD dwOffset = *(DWORD *)g_BaseAddrInfo.dwRoleBaseAddr;
//
//		dwOffset = *(DWORD *) (dwOffset + ROLE_OFFSET_1);
//		dwOffset = *(DWORD *) (dwOffset + ROLE_OFFSET_2);
//		dwOffset = *(DWORD *) (dwOffset + ROLE_OFFSET_3);
//		dwObject = dwOffset;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("��ȡ��ɫ����ʱ����\n");
//	}
//
//	return dwObject;
//}
//
//DWORD GCall::Call_GetRoleEnergy() {
//	__try {
//		DWORD dwRoleBase = Call_GetRoleObject();
//		DWORD dwEnergy = *(DWORD *)(dwRoleBase + 0x248C);
//		return dwEnergy;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("��ȡ��ɫ��ǰ����ֵ����\n");
//	}
//	return -1;
//}
//
//DWORD GCall::Call_GetRolePower() {
//	__try {
//		DWORD dwRoleBase = Call_GetRoleObject();
//		DWORD dwPower = *(DWORD *)(dwRoleBase + 0x2494);
//		return dwPower;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("��ȡ��ɫ��ǰ����ֵ����\n");
//	}
//	return -1;
//}
//
//float GCall::Call_GetRole_X() {
//	DWORD dwOffset = *(DWORD *)g_BaseAddrInfo.dwRoleBaseAddr;
//	__try {
//		dwOffset = *(DWORD *)(dwOffset + 0x70);
//		dwOffset = *(DWORD *)(dwOffset + 0x1f0);
//		dwOffset = *(DWORD *)(dwOffset + 0x4);
//		float x = *(float *)(dwOffset + 0x48);
//		return x;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("��ȡ����X����ʱ����\n");
//	}
//
//	return 0;
//}
//
//float GCall::Call_getRole_Y() {
//	DWORD dwOffset = *(DWORD *)g_BaseAddrInfo.dwRoleBaseAddr;
//	__try {
//		dwOffset = *(DWORD *)(dwOffset + 0x70);
//		dwOffset = *(DWORD *)(dwOffset + 0x1f0);
//		dwOffset = *(DWORD *)(dwOffset + 0x4);
//		float y = *(float *)(dwOffset + 0x50);
//		return y;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("��ȡ����Y����ʱ����\n");
//	}
//
//	return 0;
//}
//
//DWORD GCall::Call_IsEnemy(DWORD dwObj) {
//	DWORD dwOffset = *(DWORD *)g_BaseAddrInfo.dwRoleBaseAddr;
//	dwOffset = *(DWORD *)(dwOffset + 0x70);
//	DWORD dwBase = *(DWORD *)g_BaseAddrInfo.IsEnemyBaseAddr;
//	DWORD dwTmp = 0;
//	DWORD dwRet;
//	__try {
//		__asm {
//			pushad;
//			mov ecx, dwBase;
//			lea edx, dwTmp;
//			push edx;
//			push dwObj;
//			mov eax, [ecx];
//			push dwOffset;
//			call [eax + 0xFC];
//			mov dwRet, eax; 
//			popad;
//		}
//
//		return dwRet;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("�����Ƿ��ǹ�CALL����\n");
//	}
//	return -1;
//}
//
//void GCall::Call_SelectEnemy(DWORD dwID) {
//	DWORD dwBase = *(DWORD *)g_BaseAddrInfo.SelectEnemyBaseAddr;
//	__try {
//		__asm {
//			pushad;
//			mov ecx, dwBase;
//			mov edx, [ecx];
//			mov eax, dwID;
//			push 1;
//			push eax;
//			call [edx + 0x3C];
//			popad;
//		}
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("����ѡ��CALL����\n");
//	}
//}
//
//float GCall::Call_GetObj_Blood(DWORD dwObj) {
//	float blood = 0;
//	__try {
//		DWORD dwOffset = *(DWORD *)(dwObj + 0x1e0);
//		dwOffset = *(DWORD *)(dwOffset + 0x4);
//		blood = *(float *)(dwOffset + 0x8);
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("��ö���Ѫֵʱ����\n");
//	}
//
//	return blood;
//}
//
//void GCall::Call_UseSkill(DWORD dwSkillID, DWORD dwEnemyID) {
//	__try {
//		DWORD dwCall = g_BaseAddrInfo.UseSkillCallAddr;
//		DWORD dwOffset = *(DWORD *)g_BaseAddrInfo.dwRoleBaseAddr;
//		dwOffset = * (DWORD *)(dwOffset + 0x70);
//		dwOffset = * (DWORD *)(dwOffset + 0x1e0);
//		dwOffset = * (DWORD *)(dwOffset + 0x8);
//		dwOffset = * (DWORD *)(dwOffset + 0x1f0);
//		__asm {
//			pushad;
//			mov esi,dwOffset;
//			mov eax, [esi+0x9c];
//			push eax;
//			mov ecx, [esi+0x98];
//			push ecx;
//			mov edx, [esi+0x90];
//			push edx;
//			push dwEnemyID;
//			mov ecx, [esi + 0x88];
//			push ecx;
//			push dwSkillID;
//			mov ecx, esi;
//			call dwCall;
//			popad;
//		}
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("ʹ�ü��ܳ���\n");
//	}
//}
//
//DWORD GCall::Call_GetObjClassID(DWORD dwObj) {
//	__try {
//		return *(DWORD *)(dwObj + 0x340);
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("��ȡ����С��IDʱ����\n");
//	}
//	
//	return -1;
//}
//
////�򿪰����Ի���
//void GCall::Call_OpenPackageDlg(DWORD dwID) {
//	__try {
//		DWORD dwBase = *(DWORD *)g_BaseAddrInfo.dwRoleBaseAddr;
//		dwBase = *(DWORD *)(dwBase + 0x70);
//		dwBase = *(DWORD *)(dwBase + 0x1f0);
//		DWORD dwCallAddr = g_BaseAddrInfo.OpenPackageDlgCall;
//		__asm {
//			pushad;
//			push dwID;
//			mov ecx, dwBase;
//			call dwCallAddr;
//			popad;
//		}
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("�򿪰���CALL����!\n");
//	}
//}
//
////ʹ�ÿ�ݼ�
//void GCall::Call_UseHotKey(DWORD dwKey) {
//	__try {
//		__asm {
//			mov ecx,0x130B89C;
//			mov ecx,[ecx];
//			mov edx,[ecx];
//			push 0;
//			push 0;
//			call [edx+0x64];
//		}
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("ʹ�ÿ�ݼ�����\n");
//	}
//}
//
////��ý�ɫ��
//PCHAR GCall::Call_GetRoleName() {
//	char * roleName = NULL;
//	 __try {
//		 DWORD dwObj = Call_GetRoleObject();	//��ý�ɫ����
//		 roleName = (char *)(dwObj + ROLE_NAME_OFFSET);
//		 return roleName;
//	 }
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("��ý�ɫ����ʱ����\n");
//	}
//	return roleName;
//}
//
////��õ��߱����׵�ַ
//DWORD GCall::Call_GetBagPropsHeadAddr()
//{
//	DWORD dwBagHeadAddr;
//	DWORD	dwAddr;
//	__try
//	{
//		dwAddr = * (DWORD *)g_BaseAddrInfo.dwBagPropsAddr;
//		dwBagHeadAddr = * (DWORD *)(dwAddr + BAG_PROPS_HEAD_OFFSET);
//		return dwBagHeadAddr;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER)
//	{
//		TRACE("��õ��߱����׵�ַʱ����\n");
//	}
//
//	return 0;
//}
//
////���߱������ܸ���
//BYTE GCall::Call_GetBagPropsNum()
//{
//	BYTE	bNum = 0;
//	DWORD	dwAddr;
//	__try
//	{
//		dwAddr = * (DWORD *)g_BaseAddrInfo.dwBagPropsAddr;
//		bNum = * (BYTE *) (dwAddr + BAG_PROPS_SPACE_OFFSET);
//		return bNum;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER)
//	{
//		TRACE("��ȡ���߱������ܸ���ʱ����\n");
//	}
//
//	return 0;
//}
//
////��ñ�����Ʒ��������
//DWORD GCall::Call_GetBagGoodsType(DWORD dwObject)
//{
//	DWORD dwType;
//	DWORD dwTmp;
//	__try
//	{
//		dwTmp = * (DWORD *) (dwObject + 0x28);
//		dwType = * (DWORD *) (dwTmp + 0x4);
//		return dwType;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER)
//	{
//		TRACE("��ȡ������Ʒ���ʱ����\n");
//	}
//
//	return 0;
//}
//
////��ȡ������Ʒ������
//PCHAR GCall::Call_GetBagGoodsName(DWORD dwObject)
//{
//	char *pGoodsName = NULL;
//	DWORD dwTmp;
//	DWORD dwType;
//	__try
//	{
//		dwType = Call_GetBagGoodsType(dwObject);
//
//		dwTmp = * (DWORD *) (dwObject + GOODS_NAME_OFFSET_1);
//		if (dwType == GOODS_TYPE_ITEM)
//		{
//			dwTmp = *(DWORD *)(dwTmp + GOODS_NAME_ITEM_OFFSET_2);
//			pGoodsName = (char *)dwTmp;
//		} else if (dwType == GOODS_TYPE_EQUIP)
//		{
//			dwTmp = *(DWORD *)(dwTmp + GOODS_NAME_EQUIQ_OFFSET_2);
//			pGoodsName = (char *)dwTmp;
//		}
//
//		return pGoodsName;
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) 
//	{
//		TRACE("��ȡ������Ʒ����ʱ����\n");
//	}
//
//	return pGoodsName;
//}
