#include "StdAfx.h"
#include "CommonFun.h"
#include <math.h>

//���ݹ��ɶ�����������֮��ľ���
DWORD CalculateDistance(float x1, float y1, float x2, float y2) {
	float x3 = x1 - x2;
	float y3 = y1 - y2;
	float result = sqrt(pow(x3,2) + pow(y3, 2));
	return (DWORD) result;
}


//��ǰӦ�ó������е�Ŀ¼
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

//ȡ��a��b֮����������
int GetRandNum(int nMin, int nMax) {
	int nRand = nMin + nMax * rand() / (RAND_MAX + 1);
	return nRand;
}

//������ת��ʮ������
DWORD FloatToHex(float f) {
	return *(DWORD *)&f;
}




////��ȡ·�������ļ�
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
//		msg.Format("�ļ���%s��ȡʧ�ܡ������룺%u",filePath,fileException.m_cause);
//		AfxMessageBox(msg);
//	}
//}

