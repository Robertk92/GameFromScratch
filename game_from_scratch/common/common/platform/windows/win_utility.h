#ifndef __WIN_UTILITY_GUARD__
#define __WIN_UTILITY_GUARD__
#if defined(_WIN32) || defined(_WIN64)

#include <common/system/system.h>

namespace Common {
	class COMMON WinUtility {
	public:
		static const wchar_t* to_wchar_ptr(const char* charPtr);
	};
}

#endif // defined(_WIN32) || defined(_WIN64)
#endif //__WIN_UTILITY_GUARD__