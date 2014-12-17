#include "StdAfx.h"
#include "CommonFun.h"
#include <math.h>

//根据勾股定理，计算两点之间的距离
DWORD CalculateDistance(float x1, float y1, float x2, float y2) {
	float x3 = x1 - x2;
	float y3 = y1 - y2;
	float result = sqrt(pow(x3,2) + pow(y3, 2));
	return (DWORD) result;
}


//当前应用程序运行的目录
DWORD GetCurrentFolder(DWORD nBufferLength, LPTSTR lpBuffer) {
	DWORD dwRet = 0;
	CString strPath;
	GetModuleFileName(AfxGetInstanceHandle(), strPath.GetBufferSetLength(MAX_PATH), MAX_PATH);
	strPath.ReleaseBuffer();

	int idx = strPath.ReverseFind('\\');
	if (idx >= 0) {
		strPath = strPath.Left(idx);
	} else {
		return 0;
	}

	dwRet = strPath.GetLength();
	_tcsncpy_s(lpBuffer, nBufferLength, strPath, dwRet);
	dwRet = (nBufferLength >= dwRet) ? dwRet : nBufferLength;

	return dwRet;
}

//取得a到b之间的随机整数
int GetRandNum(int nMin, int nMax) {
	int nRand = nMin + nMax * rand() / (RAND_MAX + 1);
	return nRand;
}

//将浮点转成十六进制
DWORD FloatToHex(float f) {
	return *(DWORD *)&f;
}




////读取路径配置文件
//void ReadWayPath(LPCTSTR filePath, CList<CPoint,CPoint &> pathList) {
//	if (strlen(filePath) == 0)
//	{
//		return;
//	}
//
//	pathList.RemoveAll();
//	CStdioFile stdFile;
//	CFileException fileException;
//	if (stdFile.Open(filePath, CFile::typeText|CFile::readOnly,&fileException))
//	{
//	}
//	else
//	{
//		CString msg;
//		msg.Format("文件：%s读取失败。错误码：%u",filePath,fileException.m_cause);
//		AfxMessageBox(msg);
//	}
//}

