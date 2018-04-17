#include <Windows.h>
#include <wchar.h>

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif // !_WIN32_WINNT

int wmain(int argc, WCHAR * argv[])
{
	if (argc != 2)
	{
		fwprintf(stderr, L"\nUsage: %s [NewComputerName]\n", argv[0]);
		return 1;
	}

	//SetComputerNameEx
	COMPUTER_NAME_FORMAT nameType = ComputerNamePhysicalDnsHostname;
		

	if (!SetComputerNameExW(
		nameType,
		argv[1]))
	{
		fwprintf(stderr, L"\nError setting computer name, code: %u\n", GetLastError());
		return 1;
	}

	wprintf(L"\nComputer name has been set to %s. Please, restart your computer.\n", argv[1]);

	return 0;
}