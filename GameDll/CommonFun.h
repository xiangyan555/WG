#pragma once

//���ݹ��ɶ�����������֮��ľ���
float CalculateDistance(float x1, float y1, float x2, float y2);

//��ǰӦ�ó������е�Ŀ¼
DWORD GetCurrentFolder(DWORD nBufferLength, LPTSTR lpBuffer);

//ȡ��a��b֮����������
int GetRandNum(int nMin, int nMax);

//������ת��ʮ������
DWORD FloatToHex(float f);

////��ȡѰ·�����ļ�
//void ReadWayPath(LPCTSTR, CList<CPoint,CPoint &> pathList);