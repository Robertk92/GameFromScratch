#if defined(_WIN32)
#include <common/threading/windows/win_thread_impl.h>
#include <common/diagnostics/assertion.h>

DWORD WINAPI ThreadFunc(LPVOID lpParam);

Common::WinThreadImpl::WinThreadImpl() {
	_threadHandle = NULL;
	_threadId = 0;
	_threadHandle = CreateThread(NULL, 0, ThreadFunc, NULL, 0, &_threadId);
	ensure(_threadHandle != NULL && "Failed to create thread");
}

Common::WinThreadImpl::~WinThreadImpl() {
	WaitForSingleObject(_threadHandle, INFINITE);
	CloseHandle(_threadHandle);
	//TODO: HeapFree any potential data passed to the thread as arguments
}

DWORD WINAPI ThreadFunc(LPVOID lpParam) {
	//TODO: Invoke delegate function here
	return 0;
}


#endif