#include "FileCustom.h"

void FileCustom::Copy(const char& from, const char& to) {

	HANDLE hR = CreateFileA(&from,
		GENERIC_WRITE | GENERIC_READ,
		0,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (hR == INVALID_HANDLE_VALUE)	{ std::cout << "Could not create \"from\" file.\n"; }

	HANDLE hW = CreateFileA(&to,
		GENERIC_WRITE | GENERIC_READ,
		0,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (hW == INVALID_HANDLE_VALUE)	{ std::cout << "Could not create temporary file.\n"; }

	int bSize = GetFileSize(hR, 0);

	int it = (bSize / m_nNumberOfBytesToRead) + 1;

	/*
	for (; it; --it, bSize -= m_nNumberOfBytesToRead) {

		if (it == 1) m_nNumberOfBytesToRead = bSize;

		if (ReadFile(
			hR,
			&m_lpBuffer,
			m_nNumberOfBytesToRead,
			&m_lpNumberOfBytesRead,
			NULL
		)) {
			
			if (m_lpNumberOfBytesRead == 0) {
				break; // ..empty file 
			}
			
			if (WriteFile(
				hW,
				&m_lpBuffer,
				m_nNumberOfBytesToRead,
				&m_lpNumberOfBytesRead,
				NULL
			)) {
			
			}
			else {
				//..can't write
			}

		}
		else {
			//..can't read
		}
	} */

	char buffer[4096];

	do
	{
		if (ReadFile(hR, &buffer, 4096, &m_lpNumberOfBytesRead, NULL))
		{
			std::cout << buffer[0];
			WriteFile(hW, &buffer, m_lpNumberOfBytesRead, NULL, NULL);
		}
	} while (m_lpNumberOfBytesRead == 4096);

	CloseHandle(hR);
	CloseHandle(hW);
}

