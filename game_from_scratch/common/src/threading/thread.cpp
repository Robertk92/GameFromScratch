#include <common/threading/thread.h>
#include <common/diagnostics/assertion.h>

#if defined (_WIN32)
	#include <common/threading/windows/win_thread_impl.h>
#elif defined(__APPLE__)
#elif defined(__linux__)
#endif

Common::Thread::Thread() {
#if defined (_WIN32)
	_threadImpl = new WinThreadImpl();
#elif defined(__APPLE__)
#elif defined(__linux__)
#else 
	os_not_supported();
#endif
}

Common::Thread::~Thread() {
	if (_threadImpl != nullptr) {
		delete _threadImpl;
	}
}

#if defined(_WIN32)
	#include <windows.h>
	void Common::Thread::sleep_ms(UInt32 milliseconds) {
		Sleep(milliseconds);
	}
#elif defined(__APPLE__)
	void Common::Thread::sleep_ms(UInt32 milliseconds) { not_implemented(); }
#elif defined(__linux__)
	void Common::Thread::sleep_ms(UInt32 milliseconds) { not_implemented(); }
#else
	void Common::Thread::sleep_ms(UInt32 milliseconds) { os_not_supported(); }
#endif



