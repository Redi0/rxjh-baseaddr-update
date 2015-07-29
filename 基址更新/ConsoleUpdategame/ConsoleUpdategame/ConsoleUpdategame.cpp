// ConsoleUpdategame.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CUpdateBaseaddr.h"
#include <iostream>
#include <fstream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	HWND hGame = FindWindowA("D3D Window", NULL);
	if (hGame == NULL)
	{
		cout << "��Ϸû������" << endl;
		return 0;
	}

	DWORD pid = 0;

	GetWindowThreadProcessId(hGame, &pid);

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	if (hProcess == NULL)
	{
		cout << "��Ϸ����û�д򿪳ɹ�" << endl;
		return 0;

	}

	CUpdateAddr *update = new CUpdateAddr(hProcess);

	


	ofstream fout;
	fout.open("BaseAddr.h");

	DWORD ndCuraddr = NULL;
	DWORD ndBaseaddr = NULL;
	char szpFeatureCode[256] = "C745FCFFFFFFFF8D47D0B9";
	DWORD offset = 0xb;
	ndCuraddr = update->ScanFeatureCode(szpFeatureCode);
	ndBaseaddr= update->ReadBaseAddr(ndCuraddr + offset, 4);
	fout << "#define Base_RoleAddr " << std::hex<<ndBaseaddr <<"//�������Ի�ַ" << endl;

	fout.close();

	//getchar();
	//getchar();
	return 0;
}

