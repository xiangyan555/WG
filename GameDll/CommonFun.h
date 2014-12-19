#pragma once

//根据勾股定理，计算两点之间的距离
float CalculateDistance(float x1, float y1, float x2, float y2);

//当前应用程序运行的目录
DWORD GetCurrentFolder(DWORD nBufferLength, LPTSTR lpBuffer);

//取得a到b之间的随机整数
int GetRandNum(int nMin, int nMax);

//将浮点转成十六进制
DWORD FloatToHex(float f);

////读取寻路配置文件
//void ReadWayPath(LPCTSTR, CList<CPoint,CPoint &> pathList);