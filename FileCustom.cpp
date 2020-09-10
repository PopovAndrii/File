#include "FileCustom.h"

void FileCustom::Copy(char& from, char& to) {

	HANDLE hR = CreateFileA(
		&from,
		GENERIC_WRITE | GENERIC_READ,
		0,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	HANDLE hW = CreateFileA(
		&to,
		GENERIC_WRITE | GENERIC_READ,
		0,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	int bSize = GetFileSize(hR, 0);

	int it = (bSize / m_nNumberOfBytesToRead) + 1;

	for (; it; --it, bSize -= m_nNumberOfBytesToRead) {

		if (it == 1) m_nNumberOfBytesToRead = bSize;

		if (ReadFile(
			hR,
			&m_lpBuffer,
			m_nNumberOfBytesToRead,
			&m_lpNumberOfBytesRead,
			NULL
		)) {
			// if empty file (copy empty file)
			if (m_lpNumberOfBytesRead == 0) break;
			
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




	}

	CloseHandle(hR);
	CloseHandle(hW);
}

