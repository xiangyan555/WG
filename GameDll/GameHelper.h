#pragma once
#include "StructDef.h"

class GameHelper
{
public:
	GameHelper(void);
	~GameHelper(void);
public:
	void Test();//测试专用
	int UseGoods(CString strGoodsName);	//使用物品
	BOOL GetGoodsInfoByName(CString strGoodsName, GoodsPacket &goodsPacket);
	void TraverseMonster(CDWordArray &monsterNodes);
	void TraverseMonster(CDWordArray &monsterNodes, DWORD dwBase);
	//void GetRoleInfo(Role &role);
	//void DoAction(DWORD actionID);
	//void TraverseEnemy(CList<Enemy, Enemy&> &enemyList);
	//void TraverseEnemy(CList<Enemy, Enemy&> &enemyList, DWORD dwBaseAddr);
	//DWORD SelectedEnemy(DWORD dwObj);
	//void AutoFight(DWORD dwEnemy);
	//DWORD IsSelectedEnemy();
	//DWORD SelectNearEnemy(float x, float y, CDWordArray &enemyList);
	//void UseSkill(DWORD dwSkillID, DWORD dwEnemyID);	//根据技能ID使用技能
	//void UseHotKey(DWORD dwKey);	//根据快捷键使用技能
	//void TraverseEnver(DWORD dwBaseAddr, DWORD dwType, CList<DWORD, DWORD> &kindList, CDWordArray &objList);	//遍历周围环境
	//void PickGoods(DWORD dwPackID);									//采集物品
	//void PickGoods(CDWordArray &objList);
	//DWORD GetRoleStatus();
	//void AutoRun(float x, float y);
	//void GetNextPoint(CPoint &point);	//下一个要移动的地点坐标
	//char *GetCurrentMap();
	//void GetRoundVegetation(CList<DWORD,DWORD> &kindList, CDWordArray &objList);	//获得周围可采集的植物列表
	//void GetItemObj(DWORD dwAddr, ItemInfo &itemInfo);
	//void CollectGoods(CDWordArray &objList);	//拾取物品
	//void CollectGoods(DWORD dwID);
	//DWORD GetRoleEnergy();	//角色当前活力值
	//DWORD GetRolePower();
	//void GetRolePos(CPoint &point);
	//void GetRoundEnemy(CDWordArray &objList);
	//float GetRolePosX();
	//float GetRolePosY();
	//void GetRoundPackage(CDWordArray &objList);	//周围掉落的包裹
	//float GetEnemyBlood(DWORD dwObj);
	//DWORD SelectNextEnemy();
	//void CollectAllItem();
	//char *GetRoleName();
	//void TraverseBagProps(CDWordArray &objList);	//遍历道具背包
};

