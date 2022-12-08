#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <malloc.h>

#define path L"\\\\.\\pipe\\MyPipe"

int main()
{
	system("chcp 1251");
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;
	sa.nLength = 0;
	
	int digit = 0;
	char* buffer = calloc(20, sizeof(char));
	int countSymbols;
	HANDLE file;

	while (TRUE)
	{
		file = CreateFile(path, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
		
		BOOL checkPipe;
		DWORD dwMode = PIPE_READMODE_MESSAGE;
		checkPipe = SetNamedPipeHandleState(
			file,
			&dwMode,
			NULL,
			NULL
		);
		if (checkPipe)
		{
			printf("Подключено!\n");
			BOOL checkWord = FALSE;
			while(TRUE)
			{
				fgets(buffer, 20, stdin);
				
				for (int i = 0; buffer[i] != '\0'; i++)
				{
					if (isalpha(buffer[i]) != 0)
					{
						printf("Не число! Повторите ввод!\n");
						checkWord = TRUE;
						break;
					}
				}
				if (!checkWord)
				{
					WriteFile(file, buffer, 20, &countSymbols, NULL);
					ReadFile(file, buffer, 20, &countSymbols, NULL);
					printf("%s\n", buffer);
				}
				else checkWord = FALSE;
				
			}
		}
		else
		{
			printf("Сервер не отвечает\n");
			Sleep(1000);
		}

	}
	
}