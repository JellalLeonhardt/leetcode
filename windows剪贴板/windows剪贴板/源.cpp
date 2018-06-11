#include "stdio.h"
#include "windows.h"
#include "string.h"
//将字符串放到剪切板
//int AppendBufferToClipboard(char *cBuffer, int nSize)
//{
//	HGLOBAL hClipboard = NULL;
//	char *pClipBuf = NULL;
//	if (OpenClipboard(NULL))
//	{
//		hClipboard = GlobalAlloc(GMEM_MOVEABLE, nSize);
//		pClipBuf = (char*)GlobalLock(hClipboard);
//		memcpy(pClipBuf, cBuffer, nSize);
//		GlobalUnlock(hClipboard);
//		SetClipboardData(CF_TEXT, hClipboard);
//		CloseClipboard();
//	}
//	else
//	{
//		return -1;
//	}
//	return 0;
//}
//int AppendBufferToClipboard(char *cBuffer, int nSize)
//{
//	HGLOBAL hClipboard = NULL;
//	char *pClipBuf = NULL;
//	hClipboard = GlobalAlloc(GMEM_MOVEABLE, nSize);
//	pClipBuf = (char*)GlobalLock(hClipboard);
//	memcpy(pClipBuf, cBuffer, nSize);
//	GlobalUnlock(hClipboard);
//	OpenClipboard(NULL);
//	SetClipboardData(CF_TEXT, hClipboard);
//	CloseClipboard();
//	return 0;
//}
void AppendBufferToClipboard(char *target)
{
	// 打开剪贴板   
	if (!OpenClipboard(NULL) || !EmptyClipboard())
	{
		printf("打开或清空剪切板出错！\n");
		return;
	}

	HGLOBAL hMen;
	TCHAR strText[256];
	strcpy(strText, target);

	// 分配全局内存    
	hMen = GlobalAlloc(GMEM_MOVEABLE, ((strlen(strText) + 1) * sizeof(TCHAR)));

	if (!hMen)
	{
		printf("分配全局内存出错！\n");
		// 关闭剪切板    
		CloseClipboard();
		return;
	}

	// 把数据拷贝考全局内存中   
	// 锁住内存区    
	LPSTR lpStr = (LPSTR)GlobalLock(hMen);

	// 内存复制   
	memcpy(lpStr, strText, ((strlen(strText)) * sizeof(TCHAR)));
	// 字符结束符    
	lpStr[strlen(strText)] = (TCHAR)0;
	// 释放锁    
	GlobalUnlock(hMen);

	// 把内存中的数据放到剪切板上   
	SetClipboardData(CF_TEXT, hMen);
	CloseClipboard();

	return;
}
//从剪切板获取字符串
int GetBufferFromClipboard(char *cBuffer, int nMaxSize)
{
	int nNeedSize = 0;
	HANDLE hClipboard = NULL;
	char *pClipBuf = NULL;
	if (OpenClipboard(NULL))
	{
		EmptyClipboard();
		hClipboard = GetClipboardData(CF_TEXT);
		nNeedSize = GlobalSize(hClipboard);
		if (nNeedSize > nMaxSize + 1)
		{
			return -1;
		}
		pClipBuf = (char*)GlobalLock(hClipboard);
		memset(cBuffer, 0, nMaxSize);
		memcpy(cBuffer, pClipBuf, nNeedSize);
		GlobalUnlock(hClipboard);
		CloseClipboard();
		return nNeedSize;
	}
	else
	{
		return 0;
	}
	return -1;
}
//清空剪切板
int ClearClipboradBuffer()
{
	HGLOBAL hClipboard = NULL;
	if (OpenClipboard(NULL))
	{
		hClipboard = GetClipboardData(CF_TEXT);
		GlobalFree(hClipboard);
		EmptyClipboard();
		CloseClipboard();
		return 0;
	}
	else
	{
		return -1;
	}
}

int main(int args, char *argv[])
{
	char text[200] = "testest";
	int i;
	for (i = 1; i < args; i++) {
		strcat(text, argv[i]);
	}
	printf("%s %d\n", text, strlen(text) + 1);
	if (AppendBufferToClipboard(text, strlen(text) + 1) == -1) {
		printf("拷贝失败");
	}
	return 0;
}