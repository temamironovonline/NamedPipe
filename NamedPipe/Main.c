#include <stdio.h>
#include <Windows.h>
#include <malloc.h>

#define path "\\\\.\\pipe\\MyPipe"

int main()
{
	system("chcp 1251");
	HANDLE pipe;
	char* buffer = calloc(20, sizeof(char));
	int countSymbols = 0;
	while (TRUE)
	{
		pipe = CreateNamedPipeA(
			path, 
			PIPE_ACCESS_DUPLEX, 
			PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, 
			PIPE_UNLIMITED_INSTANCES, 
			120, 
			120, 
			INFINITE, 
			NULL);
		if (pipe == INVALID_HANDLE_VALUE) printf("Ошибка %d", GetLastError());

		BOOL checkConnect;
		checkConnect = ConnectNamedPipe(pipe, NULL);

		if (checkConnect)
		{
			printf("Клиент подключился!");

			ReadFile(pipe, buffer, 20, &checkConnect, NULL);
			printf("%s", buffer);
		}

	}
	
	
	
	
	
	
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