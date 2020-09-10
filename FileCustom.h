#pragma once

#include <windows.h>
#include <iostream>

class FileCustom
{
public:

	explicit FileCustom() {}
	~FileCustom() {}

	void Copy(char& from, char& to);

private:

	HANDLE m_hFile = NULL;
	DWORD m_lpBuffer = NULL; // ����� ������
	int m_nNumberOfBytesToRead = 4; // ����� ������ ��� ������
	DWORD m_lpNumberOfBytesRead = NULL; // ����� ����������� ������
};

