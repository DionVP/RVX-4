#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <fstream>
#include <sstream>
#include <Psapi.h>
bool isRunning = true;
//cleaning this shit up later

/* functions */

bool on_dll_detach()
{
    //some trick to only close rvx-4 instead of rvx-4 and roblox
    //being worked on
    return 1;
}

/* initiate */
void MainThread() {
try {
  //todo
	}
	catch (std::exception e) {
	//TODO
	}
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
