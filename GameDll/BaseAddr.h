#pragma once
#include <Windows.h>

/*
游戏有所有基址
*/

DWORD GameBaseAddr;			//游戏基址（角色，怪物共用）
DWORD PackageBaseAddr;		//背包首地址
DWORD UseGoodsPacketInitCall;	//初始化使用物品封包CALL
DWORD UseGoodsCallParam;		//使用物品CALL的参数
DWORD UseGoodsCall;				//使用物品CALL	
DWORD JudgeCallAddr;			//判断对象是怪物、NPC、宠物CALL
DWORD SelectMonsterCallAddr;	//选怪CALL基址
DWORD UseSkillCall;				//使用技能CALL