#ifndef __CUPDATEBASEADDR_H_
#define __CUPDATEBASEADDR_H_  
#include "stdafx.h"

#include <windows.h>


class CUpdateAddr{

private:


	void HexStrToX(IN OUT CHAR* szpHexbuf); //ͨ�����֧��
	DWORD bytesToHexStr(IN BYTE *nbData, DWORD nbDataSize, OUT char* szpHexbuf); //�ֽڼ�ת��Ϊʮ������
	bool HexStrCmp(IN const char* hexStr1, IN const char* hexStr2);  //ʮ�������ַ����Ƚ�
	char IsLowToBigCase(char c); //�����Сд��ĸ�򷵻ش�д��ĸ
	bool HexStrToBigCase(IN OUT char* szHexstr);

	BOOL CharToHex(OUT char* szpHexbuf, BYTE c);
	BOOL IsHexStr(char c);
	//DWORD  ReadBaseAddr( DWORD ndCurAddr, DWORD ndSize);

	
public:
	DWORD ScanFeatureCode(
		IN OUT char* szpFeatureCode,
		DWORD ndStartAddress = 00400000,
		DWORD ndEndAddress = 0x7FFFFFFF); //ɨ��������ĺ���
	CUpdateAddr(HANDLE hd);
	~CUpdateAddr();
	DWORD  ReadBaseAddr(DWORD ndCurAddr, DWORD ndSize);
	//DWORD OneKeyUpdate(char* szpFeaturCode , DWORD AddrOffset);

private:
	const DWORD PageSize = 0x1024;
	HANDLE handle;

};


#endif