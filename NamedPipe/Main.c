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

	HANDLE pipe;
	pipe = CreateNamedPipeA(path, PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE, PIPE_UNLIMITED_INSTANCES, 120, 120, INFINITE, &sa);
	if (pipe == INVALID_HANDLE_VALUE) printf("Ошибка %d", GetLastError());
	
	char* buffer = calloc(20, sizeof(char));
	int countSymbols = 0;
	int a;
	while (1)
	{
		ReadFile(pipe, buffer, 7, &countSymbols, NULL);
		//a = atoi(buffer);
		printf("%s", buffer);
		Sleep(1000);
		//WaitForSingleObject(pipe, INFINITE);
	}
}