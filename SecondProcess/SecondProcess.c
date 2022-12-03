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
	int a = 0;
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
			scanf_s("%d", a);
		}
		else
		{
			printf("Сервер не отвечает\n");
			Sleep(1000);
		}



		/*char* buffer = "awdawd";
		int countSymbols = 0;
		WriteFile(file, buffer, 7, &countSymbols, NULL);*/
	}
	
}