// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "cpp2ahk_distribute.h"
#include <windows.h>
bool WINAPI HandlerRoutine(DWORD dwCtrlType)
{
	switch (dwCtrlType)
	{
	case CTRL_CLOSE_EVENT :
		//MessageBox(NULL, L"Program being closed!", L"CEvent", MB_OK);
		break;
	}
	return true;
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		AllocConsole();
		SetConsoleOutputCP(65001);
		SetConsoleCtrlHandler((PHANDLER_ROUTINE)HandlerRoutine, true);
		ShowWindow(::GetConsoleWindow(), SW_HIDE);
		SetConsoleTitle(TEXT("LOG4AHK"));
		//SendMessage(::GetConsoleWindow(),WM_SETICON,ICON_SMALL,(LPARAM)LoadIcon(NULL,MAKEINTRESOURCE(IDI_WARNING)));
		SendMessage(::GetConsoleWindow(),WM_SETICON,ICON_SMALL,(LPARAM)LoadIcon(NULL,MAKEINTRESOURCE(IDI_INFORMATION)));
		//std::system("color F4");
		//SetLayeredWindowAttributes(GetConsoleWindow(), RGB(255,255,255), 0, LWA_COLORKEY);
		SetWindowPos(GetConsoleWindow(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		break;
    case DLL_THREAD_ATTACH:
		break;
    case DLL_THREAD_DETACH:
		break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

