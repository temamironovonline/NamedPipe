#define _CRT_SECURE_NO_WARNINGS

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
	int a = 5;

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
			printf("Клиент подключился!\n");
			while (TRUE)
			{
				BOOL check = ReadFile(pipe, buffer, 20, &countSymbols, NULL);
				if (!check)
				{
					printf("Клиент отключился!\n");
					break;
				}
				a = atoi(buffer);
				a *= a;
				sprintf(buffer, "%d", a);

				WriteFile(pipe, buffer, 20, &countSymbols, NULL);
				
			}
			
		}

	}
}