#include <Windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

DWORD WINAPI MyThread(LPVOID arg)
{
	while (1)
	{
		cout << "1 ";
	}
	return 0;
}

int main()
{
	// CPU ������ �˾Ƴ���.
	SYSTEM_INFO si;
	GetSystemInfo(&si);

	// CPU ������ŭ �����带 �����Ѵ�.
	for (int i = 0; i < (int)si.dwNumberOfProcessors; ++i)
	{
		HANDLE hThread = CreateThread(NULL, 0, MyThread, NULL, 0, NULL);
		if (hThread == NULL) return 1;
		// �ְ� �켱������ �����Ѵ�.
		SetThreadPriority(hThread, THREAD_PRIORITY_TIME_CRITICAL);
		CloseHandle(hThread);
	}

	Sleep(1000);

	while(1)
	{
		cout << "�� ������ ����!" << endl;
		break;
	}

	return 0;
}