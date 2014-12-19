#include "StdAfx.h"
#include "DataHelp.h"
#include "StructDef.h"
#include <exception>
#include "BaseAddr.h"

DataHelp::DataHelp(void)
{
}


DataHelp::~DataHelp(void)
{
	
}


/************************************************************************/
/* 函数说明：根据特征码扫描基址
/* 参数一：markCode 特征码字符串,不能有空格
/* 参数二：特征码离基址的距离，默认距离：1
/* 参数三：findMode 扫描方式，找到特征码后，默认为：1
/*                  0：往上找基址（特征码在基址下面）
/*                  1：往下找基址（特征码在基址上面）
/* 参数四：offset 保存基址距离进程的偏移，默认为：不保存
/************************************************************************/
DWORD DataHelp::ScanAddress(const char *markCode, DWORD distinct /* = 1 */, DWORD findMode /* = 1 */, LPDWORD offset /* = NULL */) {
	//起始地址
	const DWORD beginAddr = 0x00400000;
	//结束地址
	const DWORD endAddr = 0x7FFFFFFF;
	//每次读取游戏内存数目的大小
	const DWORD pageSize = 4096;
	////////////////////////处理特征码/////////////////////
	//特征码长度不能为单数
	if (strlen(markCode) % 2 != 0) return 0;
	//特征码长度
	int len = strlen(markCode) / 2;
	//将特征码转换成byte型
	BYTE *m_code = new BYTE[len];
	for (int i = 0; i < len; i++){
		char c[] = {markCode[i*2], markCode[i*2+1], '\0'};
		m_code[i] = (BYTE)::strtol(c, NULL, 16);
	}
	/////////////////////////查找特征码/////////////////////
	BOOL _break = FALSE;
	//用来保存在第几页中的第几个找到的特征码
	int curPage = 0;
	int curIndex = 0;
	Base base;
	//每页读取4096个字节
	BYTE page[pageSize];
	DWORD tmpAddr = beginAddr;
	while (tmpAddr <= endAddr - len){
		//::ReadProcessMemory(process, (LPCVOID)tmpAddr, &page, pageSize, 0);
		memcpy(page, (int*)tmpAddr, pageSize);
		//在该页中查找特征码
		for (int i = 0; i < pageSize; i++){
			for (int j = 0; j < len; j++){
				//只要有一个与特征码对应不上则退出循环
				if (m_code[j] != page[i + j])break;
				//找到退出所有循环
				if (j == len - 1){
					_break = TRUE;
					if (!findMode){
						curIndex = i;
						base.data[0] = page[curIndex-distinct-4];
						base.data[1] = page[curIndex-distinct-3];
						base.data[2] = page[curIndex-distinct-2];
						base.data[3] = page[curIndex-distinct-1];
					}else{
						curIndex = i + j;
						base.data[0] = page[curIndex+distinct+1];
						base.data[1] = page[curIndex+distinct+2];
						base.data[2] = page[curIndex+distinct+3];
						base.data[3] = page[curIndex+distinct+4];
					}
					break;
				}
			}
			if (_break) break;
		}
		if (_break) break;
		curPage++;
		tmpAddr += pageSize;
	}
	if(offset != NULL){
		*offset = curPage * pageSize + curIndex + beginAddr;
	}

	delete []m_code;
	return base.address;
}

/************************************************************************/
/* 函数说明：根据特征码扫描call地址
/* 参数一：markCode 特征码字符串,不能有空格
/* 参数二：特征码离基址的距离，默认距离：1
/* 参数三：findMode 扫描方式，找到特征码后，默认为：1
/*                  0：往上找基址
/*                  1：往下找基址
/************************************************************************/
DWORD DataHelp::ScanCall(const char *markCode, DWORD distinct /* = 1 */, DWORD findMode /* = 1 */) {
	DWORD offset;
	DWORD call = ScanAddress(markCode, distinct, findMode, &offset);
	call += offset;
	if(findMode) call = call + 5 + distinct;
	else call = call - distinct;
	return call;
}

/*
const char g_szRoleCode[] = "8B46108B1150FF52488BD885";			//人物属性基址特征码
const char g_szMapCode[]  = "8B1183F8010F94C0508B4650";			//当前地图特征码
const char g_szPickParamCode[] = "8B56088B0152FF9080000000";	//采集动作参数基址特征码
const char g_szAutoRunCode[] = "8945CC8B46108B55CC5051";		//自动寻路CALL基址特征码(同一地图)
const char g_szPickAllCode[] = "8B01FF90AC01000033C0C20400";	//捡取全部基址特征码(这个易变)
const char g_szIsEnemyCode[] = "8D55B45256C745B4000000008B0157";//判断是否是怪特征码
const char g_szSelectedEnemyCode[] = "8B46088B116A0150FF523C";	//选怪特征码
const char g_szUserSkillCode[] = "0FBF96840000005051528BCE";	//使用技能特征码
const char g_szOpenPackageDlg[] = "8B46088B760C56508BCF";		//打开包裹CALL特征码
const char g_szBagPropsBaseCode[] = "0FB658128B06578BCEFF90D8000000";	//道具背包基址特征码
const char g_szUseGoodsCode[] = "8995A4FEFFFF8985A8FEFFFFE8";	//使用物品CALL，参数基址特征码
*/

//更新游戏基址
void DataHelp::UpdateGameData() {
	try
	{
		GameBaseAddr = ScanAddress("8B46108B1150FF52488BD885", 0, 0);	//人物基址
		PackageBaseAddr = ScanAddress("0FB658128B06578BCEFF90D8000000", 0, 0);	//背包基址
		UseGoodsPacketInitCall = ScanCall("8B06BB100000008BCE895DFCFF5030", 0, 0);
		UseGoodsCallParam = ScanAddress("8995A4FEFFFF8985A8FEFFFFE8",0, 0);
		UseGoodsCall = ScanCall("8995A4FEFFFF8985A8FEFFFFE8", 0, 1);
		JudgeCallAddr = ScanAddress("8D55B45256C745B4000000008B01", 0, 0);
		SelectMonsterCallAddr = ScanAddress("8B46088B116A0150FF523C8B87D8000000", 0, 0);
		UseSkillCall = ScanCall("528B55C4525156508BCFE8", 0, 1);
		TRACE("角色基址：%08X\n",GameBaseAddr);
		TRACE("背包基址：%08X\n",PackageBaseAddr);
		TRACE("使用物品封包数据初始化CALL：%08X\n",UseGoodsPacketInitCall);
		TRACE("使用物品CALL参数：%08X\n",UseGoodsCallParam);
		TRACE("使用物品CALL：%08X\n",UseGoodsCall);
		TRACE("判断对象小类Call基址：%08X\n",JudgeCallAddr);
		TRACE("选怪CALL基址：%08X", SelectMonsterCallAddr);
		TRACE("使用技能CALL：%08X", UseSkillCall);
	}
	catch (std::exception ex)
	{
		AfxMessageBox(ex.what());
	}
}