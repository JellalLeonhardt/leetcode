#include "stdio.h"
#include "windows.h"
#include "string.h"
//���ַ����ŵ����а�
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
	// �򿪼�����   
	if (!OpenClipboard(NULL) || !EmptyClipboard())
	{
		printf("�򿪻���ռ��а����\n");
		return;
	}

	HGLOBAL hMen;
	TCHAR strText[256];
	strcpy(strText, target);

	// ����ȫ���ڴ�    
	hMen = GlobalAlloc(GMEM_MOVEABLE, ((strlen(strText) + 1) * sizeof(TCHAR)));

	if (!hMen)
	{
		printf("����ȫ���ڴ����\n");
		// �رռ��а�    
		CloseClipboard();
		return;
	}

	// �����ݿ�����ȫ���ڴ���   
	// ��ס�ڴ���    
	LPSTR lpStr = (LPSTR)GlobalLock(hMen);

	// �ڴ渴��   
	memcpy(lpStr, strText, ((strlen(strText)) * sizeof(TCHAR)));
	// �ַ�������    
	lpStr[strlen(strText)] = (TCHAR)0;
	// �ͷ���    
	GlobalUnlock(hMen);

	// ���ڴ��е����ݷŵ����а���   
	SetClipboardData(CF_TEXT, hMen);
	CloseClipboard();

	return;
}
//�Ӽ��а��ȡ�ַ���
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
//��ռ��а�
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
		printf("����ʧ��");
	}
	return 0;
}