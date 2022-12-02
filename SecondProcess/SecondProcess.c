#include <stdio.h>
#include <Windows.h>
#include <malloc.h>

#define path "\\\\.\\pipe\\MyPipe"

int main()
{
	system("chcp 1251");
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;
	sa.nLength = 0;

	HANDLE file;
	file = CreateFileA(path, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, &sa, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	printf("%d", file);
	while (1)
	{
		char* buffer = "awdawd";
		int countSymbols = 0;
		WriteFile(file, buffer, 7, &countSymbols, NULL);
	}
	
}