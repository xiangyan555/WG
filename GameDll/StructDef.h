#pragma once

//////////////////////////////角色信息偏移///////////////////////////////////////////////////////////////
#define ROLE_OFFSET_1					0x70		//角色一级偏移
#define ROLE_OFFSET_2					0x1EC		//角色二级偏移
#define ROLE_OFFSET_3					0x4			//角色三级偏移
#define ROLE_CURRENT_BLOOD_OFFSET		0x24a0		//当前血值偏移
#define ROLE_MAX_BLOOD_OFFSET			0x2520		//最大血值偏移
#define ROLE_CURRENT_MAGIC_OFFSET		0x24A4		//当前气值
#define ROLE_MAX_MAGIC_OFFSET			0x2524		//最大气值
#define ROLE_CURRENT_ENERGY_OFFSET		0x24B4		//当前活力值
#define ROLE_MAX_ENERGY_OFFSET			0x24B8		//最大活力值
#define ROLE_CURRENT_POWER_OFFSET		0x24BC		//当前精力值
#define ROLE_MAX_POWER_OFFSET			0x24C0		//最大精力值
#define ROLE_NAME_OFFSET				0x34		//角色名偏移
#define ROLE_LEVEL_OFFSET				0x64		//等级
#define ROLE_CURRENT_EXP_OFFSET			0x24A8		//拥有经验
#define ROLE_BIND_MONEY_OFFSET			0x2404		//交子
#define ROLE_MONEY_OFFSET				0x24AC		//金币


#define ROLE_POSITION_OFFSET			0x200		//角色位置偏移
#define ROLE_POSITION_X_OFFSET			0x48		//X坐标偏移
#define ROLE_POSITION_Y_OFFSET			0x50		//Y坐标偏移
#define ROLE_UNKNOWN_OFFSET				0x54		//未知
//////////////////////////////////////////////////////////////////////////////////////////////

#define BAG_PROPS_HEAD_OFFSET			0x33D8		//道具背包首地址偏移
#define BAG_PROPS_SPACE_OFFSET			0x33F0		//道具背包总格数偏移
#define BAG_MATERIAL_SPACE_OFFSET		0x33F1		//材料背包总格数偏移

#define GOODS_NAME_OFFSET_1				0x28		//物品名称一级偏移
#define GOODS_NAME_ITEM_OFFSET_2		0x18		//物品名称二级偏移（消耗品）
#define GOODS_NAME_EQUIQ_OFFSET_2		0x28		//物品名称二级偏移（装备）


#define GOODS_TYPE_OFFSET_1				0x28		//物品类别一级偏移
#define GOODS_TYPE_OFFSET_2				0x4			//物品类别二级偏移

#define GOODS_NUMBER_OFFSET_1			0x14		//物品数量一级偏移
#define GOODS_NUMBER_OFFSET_2			0x3C		//物品数量二级偏移	
#define GOODS_USE_LEVEL_OFFSET			0x3D		//物品使用等级

#define GOODS_UNKNOWN_4_OFFSET			0x4
#define GOODS_UNKNOWN_8_OFFSET			0x8
///////////////////////////////////////////////////////////////////////////////////////////////

#define ENV_TREE_LEFT_OFFSET			0x4			//左树偏移
#define ENV_TREE_RIGHT_OFFSET			0x8			//右树偏移
#define ENV_TREE_FLAG_OFFSET			0x15		//标志

#define MONSTER_OFFSET					0x64		//怪物偏移
#define MONSTER_OBJECT_OFFSET			0x10		//对象偏移
#define MONSTER_ATTR_OFFSET_1			0x1E8		//属性一级偏移
#define MONSTER_ATTR_OFFSET_2			0x4			//属性二级偏移
#define MONSTER_BLOOD_OFFSET			0x8			//血值偏移
#define MONSTER_NAME_OFFSET				0x34		//名字偏移
#define MONSTER_LEVEL_OFFSET			0x64		//等级偏移
#define MONSTER_ID_OFFSET				0x34		//ID偏移
#define MONSTER_POS_X_OFFSET			0x48		//X坐标偏移
#define MONSTER_POS_Y_OFFSET			0x50		//Y坐标偏移
#define MONSTER_TYPE_OFFSET_1			0x2C		//类型一级偏移
#define MONSTER_TYPE_OFFSET_2			0x18		//类型二级偏移


//角色
struct ROLE {
	DWORD dwCurrentBlood;	//当前血值
	DWORD dwMaxBlood;		//最大血值
	DWORD dwCurrentMagic;	//当前气值
	DWORD dwMaxMagic;		//最大气值
	DWORD dwCurrentEnergy;	//当前活力值
	DWORD dwMaxEnergy;		//最大活力值
	DWORD dwCurrentPower;	//当前精力值
	DWORD dwMaxPower;		//最大精力值
	char  *pName;			//角色名字
	DWORD dwLevel;			//等级
	DWORD dwCurrentExp;		//当前经验
	char  *pMapName;		//所在地图
	float x;				//角色位置X坐标
	float y;				//角色位置Y坐标
	DWORD dwBindMoney;		//交子(绑定的金钱)
	DWORD dwMoney;			//金币（高四位是金子，中两位是银子，低两位是铜钱）
	//构造函数
	ROLE();
} ;

//使用物品封包结构
#pragma pack(push)
#pragma pack(1)
struct GoodsPacket
{
	BYTE	b_Param_0_15[16];	//初始化函数中赋值。前四个字节，是一个函数地址
	BYTE	b_Pos_16;			//物品在背包中的位置
	BYTE	b_Param_17_19[3];	//初始化函数中赋值
	DWORD	dw_Param_20_23;		//[物品对象+0x14]+0x8
	DWORD	dw_Param_24_27;		//[物品对象+0x14]
	DWORD	dw_Param_28_31;		//[物品对象+0x14]+0x4
	DWORD   dw_Param_32_35;		//[[人物基址]+70]+34
	DWORD   dw_Param_36_39;		//固定值BF800000,可用[[人物基址]+70]+54获得
	DWORD   dw_Param_40_43;		//固定值BF800000,可用[[人物基址]+70]+54获得
	BYTE	b_Param_44_56[13];	//初始化函数中赋值
};
#pragma pack()
#pragma pack(pop)

//物品信息
struct GoodsInfo
{
	char	*pGoodsName;	//物品名字
	DWORD	dwType;			//物品类型
	BYTE	bNum;			//数量
	BYTE	bGoodsLevel;	//物品等级
	BYTE	bUseLevel;		//使用等级
	DWORD	dwUnknown_14_0;	//未知
	DWORD	dwUnknown_14_4;
	DWORD	dwUnknown_14_8;
	GoodsInfo();
	GoodsInfo(DWORD dwGoodsObj);	//构造函数
};

//怪物信息
struct MonsterInfo
{
	DWORD	dwID;		//ID
	DWORD	dwType;		//类型 3.怪物、NPC、宠物 7.自己、地面包裹 8.采集物 鱼   11.其它玩家
	char	*pName;		//名字
	DWORD	dwLevel;	//等级
	float	fBlood;		//血值
	float	x;			//X坐标
	float	y;			//Y坐标

	MonsterInfo(DWORD dwBase);
};


//搜索基址用
union Base {
	DWORD address;
	BYTE  data[4];
};