#include <windows.h>
#include <stdio.h>

volatile int running = 0;
volatile int programAlive = 1;

DWORD WINAPI clickThread(LPVOID lpParam)
{
    INPUT inputs[2];

    ZeroMemory(inputs, sizeof(inputs));

    // LEFT DOWN
    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    // LEFT UP
    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    while (programAlive)
    {
        if (running)
        {
            SendInput(2, inputs, sizeof(INPUT));

            Sleep(50);
        }
    }

    return 0;
}

int main()
{
    printf("=====================================\n");
    printf(" ULTRA FAST AUTOCLICKER - C VERSION\n");
    printf("=====================================\n\n");

    printf("F6 -> ON/OFF\n");
    printf("F7 -> EXIT\n\n");

    // Prioridade alta do processo
    SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);

    HANDLE hThread = CreateThread(
        NULL,
        0,
        clickThread,
        NULL,
        0,
        NULL
    );

    if (hThread == NULL)
    {
        printf("Erro ao criar thread.\n");
        return 1;
    }

    while (programAlive)
    {
        // Detecta clique único da tecla F6
        if (GetAsyncKeyState(VK_F6) & 1)
        {
            running = !running;

            if (running)
                printf("[AUTOCLICK ON]\n");
            else
                printf("[AUTOCLICK OFF]\n");
        }

        // F7 fecha o programa
        if (GetAsyncKeyState(VK_F7) & 1)
        {
            printf("Encerrando...\n");
            programAlive = 0;
        }

        Sleep(1);
    }

    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);

    return 0;
}