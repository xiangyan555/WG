#pragma once
#include <Windows.h>

/*
��Ϸ�����л�ַ
*/

DWORD GameBaseAddr;			//��Ϸ��ַ����ɫ�����ﹲ�ã�
DWORD PackageBaseAddr;		//�����׵�ַ
DWORD UseGoodsPacketInitCall;	//��ʼ��ʹ����Ʒ���CALL
DWORD UseGoodsCallParam;		//ʹ����ƷCALL�Ĳ���
DWORD UseGoodsCall;				//ʹ����ƷCALL	
DWORD JudgeCallAddr;			//�ж϶����ǹ��NPC������CALL
DWORD SelectMonsterCallAddr;	//ѡ��CALL��ַ
DWORD UseSkillCall;				//ʹ�ü���CALL