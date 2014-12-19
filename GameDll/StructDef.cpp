#include "stdafx.h"
#include "StructDef.h"
#include "ConstantDef.h"

extern DWORD GameBaseAddr;

//��ɫ��Ϣ�Ĺ��캯��
ROLE::ROLE()
{
	DWORD dwTmp;	//��ʱ����
	DWORD dwTmp2;
	__try
	{
		
		dwTmp = * (DWORD *)GameBaseAddr;
		dwTmp = * (DWORD *)(dwTmp + ROLE_OFFSET_1);
		dwTmp2 = dwTmp;
		dwTmp = * (DWORD *)(dwTmp + ROLE_OFFSET_2);
		dwTmp = * (DWORD *)(dwTmp + ROLE_OFFSET_3);
		dwCurrentBlood = * (DWORD *)(dwTmp + ROLE_CURRENT_BLOOD_OFFSET);
		dwMaxBlood = * (DWORD *)(dwTmp + ROLE_MAX_BLOOD_OFFSET);
		dwCurrentMagic = * (DWORD *)(dwTmp + ROLE_CURRENT_MAGIC_OFFSET);
		dwMaxMagic = * (DWORD *)(dwTmp + ROLE_MAX_MAGIC_OFFSET);
		dwCurrentEnergy = * (DWORD *)(dwTmp + ROLE_CURRENT_ENERGY_OFFSET);
		dwMaxEnergy = * (DWORD *)(dwTmp + ROLE_MAX_ENERGY_OFFSET);
		dwCurrentPower = * (DWORD *)(dwTmp + ROLE_CURRENT_POWER_OFFSET);
		dwMaxPower = * (DWORD *)(dwTmp + ROLE_MAX_POWER_OFFSET);
		pName = (char *)(dwTmp + ROLE_NAME_OFFSET);
		dwLevel = * (DWORD *)(dwTmp + ROLE_LEVEL_OFFSET);
		dwCurrentExp = * (DWORD *)(dwTmp + ROLE_CURRENT_EXP_OFFSET);
		dwBindMoney = * (DWORD *)(dwTmp + ROLE_BIND_MONEY_OFFSET);
		dwMoney = * (DWORD *)(dwTmp + ROLE_MONEY_OFFSET);

		//λ����Ϣ
		dwTmp2 = *(DWORD *)(dwTmp2 + ROLE_POSITION_OFFSET);
		dwTmp2 = *(DWORD *)(dwTmp2 + ROLE_OFFSET_3);
		x = *(float *)(dwTmp2 + ROLE_POSITION_X_OFFSET);
		y = *(float *)(dwTmp2 + ROLE_POSITION_Y_OFFSET);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		TRACE("��ɫ���캯������\n");
	}
}

GoodsInfo::GoodsInfo()
{
	pGoodsName = NULL;	//��Ʒ����
	dwType = 0;			//��Ʒ����
	bNum = 0;			//����
	bGoodsLevel = 0;	//��Ʒ�ȼ�
	bUseLevel = 0;		//ʹ�õȼ�
	dwUnknown_14_0 = 0;	//δ֪
	dwUnknown_14_4 = 0;
	dwUnknown_14_8 = 0;
}

//��Ʒ��Ϣ�Ĺ��캯��
GoodsInfo::GoodsInfo(DWORD dwGoodsObj)
{
	DWORD dwTmp;
	__try
	{
		dwTmp = * (DWORD *) (dwGoodsObj + GOODS_TYPE_OFFSET_1);
		dwType = * (DWORD *) (dwTmp + GOODS_TYPE_OFFSET_2);
		if (dwType == GOODS_TYPE_ITEM)		//��ʹ�õ���Ʒ
		{
			pGoodsName = (char *)*(DWORD *)(dwTmp + GOODS_NAME_ITEM_OFFSET_2);	//����
			dwTmp = *(DWORD *)(dwGoodsObj + GOODS_NUMBER_OFFSET_1);	
			bNum = *(BYTE *)(dwTmp + GOODS_NUMBER_OFFSET_2);	//����
			bUseLevel = *(BYTE *)(dwTmp + GOODS_USE_LEVEL_OFFSET);//ʹ�õȼ�

			dwUnknown_14_0 = *(DWORD *)dwTmp;
			dwUnknown_14_4 = *(DWORD *)(dwTmp + GOODS_UNKNOWN_4_OFFSET);
			dwUnknown_14_8 = *(DWORD *)(dwTmp + GOODS_UNKNOWN_8_OFFSET);
		} else if (dwType == GOODS_TYPE_EQUIP)
		{
			pGoodsName = (char *)*(DWORD *)(dwTmp + GOODS_NAME_EQUIQ_OFFSET_2);
		}

	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		TRACE("��Ʒ��Ϣ���캯������\n");
	}
}

MonsterInfo::MonsterInfo(DWORD dwBase)
{
	DWORD	dwTmp = 0;
	DWORD	dwTmp2 = 0;
	__try
	{
		dwTmp = *(DWORD *)(dwBase + MONSTER_OBJECT_OFFSET);
		dwTmp2 = dwTmp;
		dwTmp = *(DWORD *)(dwTmp + MONSTER_TYPE_OFFSET_1);
		dwType = *(DWORD *)(dwTmp + MONSTER_TYPE_OFFSET_2);

		if (dwType == TYPE_MONSTER)
		{
			x = *(float *)(dwTmp2 + MONSTER_POS_X_OFFSET);
			y = *(float *)(dwTmp2 + MONSTER_POS_Y_OFFSET);
			dwID = *(DWORD *)(dwTmp2 + MONSTER_ID_OFFSET);

			dwTmp2 = *(DWORD *)(dwTmp2 + MONSTER_ATTR_OFFSET_1);
			dwTmp2 = *(DWORD *)(dwTmp2 + MONSTER_ATTR_OFFSET_2);
			pName = (char *)(dwTmp2 + MONSTER_NAME_OFFSET);
			fBlood = *(float *)(dwTmp2 + MONSTER_BLOOD_OFFSET);
			dwLevel = *(DWORD *)(dwTmp2 + MONSTER_LEVEL_OFFSET);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		TRACE("����������ʱ����,�������%08X\n",dwBase);
	}
}