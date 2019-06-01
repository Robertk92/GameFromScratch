#include <common/threading/thread.h>
#include <common/diagnostics/assertion.h>

#if defined(_WIN32) || defined(_WIN64)
	#include <windows.h>
	void Common::Thread::sleep_ms(UInt64 milliseconds) {
		Sleep(milliseconds);
	}
#elif defined(__APPLE__)
	void Common::Thread::sleep_ms(UInt64 milliseconds) { not_implemented(); }
#elif defined(__linux__)
	void Common::Thread::sleep_ms(UInt64 milliseconds) { not_implemented(); }
#else
	void Common::Thread::sleep_ms(UInt64 milliseconds) { not_implemented(); }
#endif
