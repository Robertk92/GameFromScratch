#ifndef __PLATFORM_WINDOWS_GUARD__
#define __PLATFORM_WINDOWS_GUARD__
#if defined(_WIN32) || defined(_WIN64)

#include <common/system/system.h>

namespace Common {
	class COMMON PlatformWindows {
	public:
		static const wchar_t* to_wchar_ptr(const char* charPtr);
	};
}

#endif // defined(_WIN32) || defined(_WIN64)
#endif //__PLATFORM_WINDOWS_GUARD__