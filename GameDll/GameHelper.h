#pragma once
#include "StructDef.h"

class GameHelper
{
public:
	GameHelper(void);
	~GameHelper(void);
public:
	void Test();//����ר��
	int UseGoods(CString strGoodsName);	//ʹ����Ʒ
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
	//void UseSkill(DWORD dwSkillID, DWORD dwEnemyID);	//���ݼ���IDʹ�ü���
	//void UseHotKey(DWORD dwKey);	//���ݿ�ݼ�ʹ�ü���
	//void TraverseEnver(DWORD dwBaseAddr, DWORD dwType, CList<DWORD, DWORD> &kindList, CDWordArray &objList);	//������Χ����
	//void PickGoods(DWORD dwPackID);									//�ɼ���Ʒ
	//void PickGoods(CDWordArray &objList);
	//DWORD GetRoleStatus();
	//void AutoRun(float x, float y);
	//void GetNextPoint(CPoint &point);	//��һ��Ҫ�ƶ��ĵص�����
	//char *GetCurrentMap();
	//void GetRoundVegetation(CList<DWORD,DWORD> &kindList, CDWordArray &objList);	//�����Χ�ɲɼ���ֲ���б�
	//void GetItemObj(DWORD dwAddr, ItemInfo &itemInfo);
	//void CollectGoods(CDWordArray &objList);	//ʰȡ��Ʒ
	//void CollectGoods(DWORD dwID);
	//DWORD GetRoleEnergy();	//��ɫ��ǰ����ֵ
	//DWORD GetRolePower();
	//void GetRolePos(CPoint &point);
	//void GetRoundEnemy(CDWordArray &objList);
	//float GetRolePosX();
	//float GetRolePosY();
	//void GetRoundPackage(CDWordArray &objList);	//��Χ����İ���
	//float GetEnemyBlood(DWORD dwObj);
	//DWORD SelectNextEnemy();
	//void CollectAllItem();
	//char *GetRoleName();
	//void TraverseBagProps(CDWordArray &objList);	//�������߱���
};

