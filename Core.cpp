#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <fstream>
#include <sstream>
#include <Psapi.h>
#include "ScriptContext.h"
bool isRunning = true;
//cleaning this shit up later

/* functions */
//todo


/* initiate */
void MainThread() {
try {
    utilities::ConsoleBypass();
    AllocConsole();
    freopen("conin$", "r+t", stdin);
    freopen("conout$", "w+t", stdout);
    freopen("conout$", "w+t", stderr);
    ScriptContext *ScrContext;
    int *GlobalState = ScrContext->Getglobalstate(0xd3adbeef,1,0xd3adbeef);
}


/* initiation thread */
extern "C" __declspec(dllexport) void StartThread()
{
	DWORD MThreadID;
	HANDLE MThread;

	MThread = CreateThread(NULL, 0, MainThread, 0, 0, &MThreadID);
	if (!(MThread == NULL))
		CloseHandle(MThread);

}

/* initiate thread */
BOOL WINAPI DllMain(HMODULE hModule, DWORD  reason, LPVOID)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:		
		start_thread();
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		
		isRunning = false;
	        on_dll_detach();
		break;
	}
	return TRUE;
}
