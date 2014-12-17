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

//自动寻路
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
//		TRACE("自动寻路CALL出错!\n");
//	}
//}
//
////采集动作CALL
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
//		TRACE("调用采集动作CALL出错\n");
//	}
//}
//
////拾取全部CALL
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
//		TRACE("调用拾取全部CALL出错\n");
//	}
//}
//
///************************************************************************/
///* 人物当前状态 0--正常不动   2--跑动中   5---动功中  6--打座  7--战斗中  8--采集中*/ 
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
//		TRACE("获取人物状态出错\n");
//	}
//
//	return dwStatus;
//}
//
////获得当前地图名称
//PCHAR GCall::Call_GetCurrentMap() {
//		DWORD dwOffset = *(DWORD *)g_BaseAddrInfo.dwMapBaseAddr;
//		PCHAR pMapName = NULL;
//		__try {
//			dwOffset = *(DWORD *)(dwOffset + 0x46CC);
//			pMapName = (PCHAR)(dwOffset + 0x68);
//			return pMapName;
//		}
//		__except (EXCEPTION_EXECUTE_HANDLER) {
//			TRACE("获取当前地图出错\n");
//		}
//		return pMapName;
//}
//
////环境二叉树左树
//DWORD GCall::Call_GetEnvirLeftTree() {
//	DWORD dwOffset = *(DWORD *)g_BaseAddrInfo.dwRoleBaseAddr;
//	dwOffset = *(DWORD *)(dwOffset + 0x64);
//	dwOffset = *(DWORD *)(dwOffset + 0x4);
//	return dwOffset;
//}
//
////获得对象类型
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
//		TRACE("获取对象类型时出错\n");
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
//		TRACE("获取对象种类时出错\n");
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
//		TRACE("获得对象ID时出错\n");
//	}
//	return dwID;
//}
//
////获得角色对象
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
//		TRACE("获取角色对象时出错\n");
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
//		TRACE("获取角色当前活力值出错\n");
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
//		TRACE("获取角色当前活力值出错\n");
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
//		TRACE("获取人物X坐标时出错\n");
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
//		TRACE("获取人物Y坐标时出错\n");
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
//		TRACE("决断是否是怪CALL出错\n");
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
//		TRACE("调用选怪CALL出错\n");
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
//		TRACE("获得对象血值时出错\n");
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
//		TRACE("使用技能出错\n");
//	}
//}
//
//DWORD GCall::Call_GetObjClassID(DWORD dwObj) {
//	__try {
//		return *(DWORD *)(dwObj + 0x340);
//	}
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("获取对象小类ID时出错\n");
//	}
//	
//	return -1;
//}
//
////打开包裹对话框
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
//		TRACE("打开包裹CALL出错!\n");
//	}
//}
//
////使用快捷键
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
//		TRACE("使用快捷键出错\n");
//	}
//}
//
////获得角色名
//PCHAR GCall::Call_GetRoleName() {
//	char * roleName = NULL;
//	 __try {
//		 DWORD dwObj = Call_GetRoleObject();	//获得角色对象
//		 roleName = (char *)(dwObj + ROLE_NAME_OFFSET);
//		 return roleName;
//	 }
//	__except (EXCEPTION_EXECUTE_HANDLER) {
//		TRACE("获得角色名称时出错\n");
//	}
//	return roleName;
//}
//
////获得道具背包首地址
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
//		TRACE("获得道具背包首地址时出错\n");
//	}
//
//	return 0;
//}
//
////道具背包的总格数
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
//		TRACE("获取道具背包的总格数时出错\n");
//	}
//
//	return 0;
//}
//
////获得背包物品对象的类别
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
//		TRACE("获取背包物品类别时出错\n");
//	}
//
//	return 0;
//}
//
////获取背包物品的名字
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
//		TRACE("获取背包物品名称时出错\n");
//	}
//
//	return pGoodsName;
//}
