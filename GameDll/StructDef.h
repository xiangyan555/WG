#pragma once

//////////////////////////////��ɫ��Ϣƫ��///////////////////////////////////////////////////////////////
#define ROLE_OFFSET_1					0x70		//��ɫһ��ƫ��
#define ROLE_OFFSET_2					0x1EC		//��ɫ����ƫ��
#define ROLE_OFFSET_3					0x4			//��ɫ����ƫ��
#define ROLE_CURRENT_BLOOD_OFFSET		0x24a0		//��ǰѪֵƫ��
#define ROLE_MAX_BLOOD_OFFSET			0x2520		//���Ѫֵƫ��
#define ROLE_CURRENT_MAGIC_OFFSET		0x24A4		//��ǰ��ֵ
#define ROLE_MAX_MAGIC_OFFSET			0x2524		//�����ֵ
#define ROLE_CURRENT_ENERGY_OFFSET		0x24B4		//��ǰ����ֵ
#define ROLE_MAX_ENERGY_OFFSET			0x24B8		//������ֵ
#define ROLE_CURRENT_POWER_OFFSET		0x24BC		//��ǰ����ֵ
#define ROLE_MAX_POWER_OFFSET			0x24C0		//�����ֵ
#define ROLE_NAME_OFFSET				0x34		//��ɫ��ƫ��
#define ROLE_LEVEL_OFFSET				0x64		//�ȼ�
#define ROLE_CURRENT_EXP_OFFSET			0x24A8		//ӵ�о���
#define ROLE_BIND_MONEY_OFFSET			0x2404		//����
#define ROLE_MONEY_OFFSET				0x24AC		//���


#define ROLE_POSITION_OFFSET			0x200		//��ɫλ��ƫ��
#define ROLE_POSITION_X_OFFSET			0x48		//X����ƫ��
#define ROLE_POSITION_Y_OFFSET			0x50		//Y����ƫ��
#define ROLE_UNKNOWN_OFFSET				0x54		//δ֪
//////////////////////////////////////////////////////////////////////////////////////////////

#define BAG_PROPS_HEAD_OFFSET			0x33D8		//���߱����׵�ַƫ��
#define BAG_PROPS_SPACE_OFFSET			0x33F0		//���߱����ܸ���ƫ��
#define BAG_MATERIAL_SPACE_OFFSET		0x33F1		//���ϱ����ܸ���ƫ��

#define GOODS_NAME_OFFSET_1				0x28		//��Ʒ����һ��ƫ��
#define GOODS_NAME_ITEM_OFFSET_2		0x18		//��Ʒ���ƶ���ƫ�ƣ�����Ʒ��
#define GOODS_NAME_EQUIQ_OFFSET_2		0x28		//��Ʒ���ƶ���ƫ�ƣ�װ����


#define GOODS_TYPE_OFFSET_1				0x28		//��Ʒ���һ��ƫ��
#define GOODS_TYPE_OFFSET_2				0x4			//��Ʒ������ƫ��

#define GOODS_NUMBER_OFFSET_1			0x14		//��Ʒ����һ��ƫ��
#define GOODS_NUMBER_OFFSET_2			0x3C		//��Ʒ��������ƫ��	
#define GOODS_USE_LEVEL_OFFSET			0x3D		//��Ʒʹ�õȼ�

#define GOODS_UNKNOWN_4_OFFSET			0x4
#define GOODS_UNKNOWN_8_OFFSET			0x8
///////////////////////////////////////////////////////////////////////////////////////////////

#define ENV_TREE_LEFT_OFFSET			0x4			//����ƫ��
#define ENV_TREE_RIGHT_OFFSET			0x8			//����ƫ��
#define ENV_TREE_FLAG_OFFSET			0x15		//��־

#define MONSTER_OFFSET					0x64		//����ƫ��
#define MONSTER_OBJECT_OFFSET			0x10		//����ƫ��
#define MONSTER_ATTR_OFFSET_1			0x1E8		//����һ��ƫ��
#define MONSTER_ATTR_OFFSET_2			0x4			//���Զ���ƫ��
#define MONSTER_BLOOD_OFFSET			0x8			//Ѫֵƫ��
#define MONSTER_NAME_OFFSET				0x34		//����ƫ��
#define MONSTER_LEVEL_OFFSET			0x64		//�ȼ�ƫ��
#define MONSTER_ID_OFFSET				0x34		//IDƫ��
#define MONSTER_POS_X_OFFSET			0x48		//X����ƫ��
#define MONSTER_POS_Y_OFFSET			0x50		//Y����ƫ��
#define MONSTER_TYPE_OFFSET_1			0x2C		//����һ��ƫ��
#define MONSTER_TYPE_OFFSET_2			0x18		//���Ͷ���ƫ��


//��ɫ
struct ROLE {
	DWORD dwCurrentBlood;	//��ǰѪֵ
	DWORD dwMaxBlood;		//���Ѫֵ
	DWORD dwCurrentMagic;	//��ǰ��ֵ
	DWORD dwMaxMagic;		//�����ֵ
	DWORD dwCurrentEnergy;	//��ǰ����ֵ
	DWORD dwMaxEnergy;		//������ֵ
	DWORD dwCurrentPower;	//��ǰ����ֵ
	DWORD dwMaxPower;		//�����ֵ
	char  *pName;			//��ɫ����
	DWORD dwLevel;			//�ȼ�
	DWORD dwCurrentExp;		//��ǰ����
	char  *pMapName;		//���ڵ�ͼ
	float x;				//��ɫλ��X����
	float y;				//��ɫλ��Y����
	DWORD dwBindMoney;		//����(�󶨵Ľ�Ǯ)
	DWORD dwMoney;			//��ң�����λ�ǽ��ӣ�����λ�����ӣ�����λ��ͭǮ��
	//���캯��
	ROLE();
} ;

//ʹ����Ʒ����ṹ
#pragma pack(push)
#pragma pack(1)
struct GoodsPacket
{
	BYTE	b_Param_0_15[16];	//��ʼ�������и�ֵ��ǰ�ĸ��ֽڣ���һ��������ַ
	BYTE	b_Pos_16;			//��Ʒ�ڱ����е�λ��
	BYTE	b_Param_17_19[3];	//��ʼ�������и�ֵ
	DWORD	dw_Param_20_23;		//[��Ʒ����+0x14]+0x8
	DWORD	dw_Param_24_27;		//[��Ʒ����+0x14]
	DWORD	dw_Param_28_31;		//[��Ʒ����+0x14]+0x4
	DWORD   dw_Param_32_35;		//[[�����ַ]+70]+34
	DWORD   dw_Param_36_39;		//�̶�ֵBF800000,����[[�����ַ]+70]+54���
	DWORD   dw_Param_40_43;		//�̶�ֵBF800000,����[[�����ַ]+70]+54���
	BYTE	b_Param_44_56[13];	//��ʼ�������и�ֵ
};
#pragma pack()
#pragma pack(pop)

//��Ʒ��Ϣ
struct GoodsInfo
{
	char	*pGoodsName;	//��Ʒ����
	DWORD	dwType;			//��Ʒ����
	BYTE	bNum;			//����
	BYTE	bGoodsLevel;	//��Ʒ�ȼ�
	BYTE	bUseLevel;		//ʹ�õȼ�
	DWORD	dwUnknown_14_0;	//δ֪
	DWORD	dwUnknown_14_4;
	DWORD	dwUnknown_14_8;
	GoodsInfo();
	GoodsInfo(DWORD dwGoodsObj);	//���캯��
};

//������Ϣ
struct MonsterInfo
{
	DWORD	dwID;		//ID
	DWORD	dwType;		//���� 3.���NPC������ 7.�Լ���������� 8.�ɼ��� ��   11.�������
	char	*pName;		//����
	DWORD	dwLevel;	//�ȼ�
	float	fBlood;		//Ѫֵ
	float	x;			//X����
	float	y;			//Y����

	MonsterInfo(DWORD dwBase);
};


//������ַ��
union Base {
	DWORD address;
	BYTE  data[4];
};