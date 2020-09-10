#pragma once

#include <windows.h>
#include <iostream>

class FileCustom
{
public:

	explicit FileCustom() {}
	~FileCustom() {}

	void Copy(const char& from, const char& to);

private:
	DWORD m_lpBuffer = NULL;
	int m_nNumberOfBytesToRead = 4;
	DWORD m_lpNumberOfBytesRead = NULL;
};

