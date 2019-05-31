#if defined(_WIN32) || defined(_WIN64)
#include <common/platform/windows/win_utility.h>
#include <windows.h>

const wchar_t* Common::WinUtility::to_wchar_ptr(const char* charPtr) {
	size_t msgSize = strlen(charPtr) + 1;
	wchar_t* wcMsg = new wchar_t[msgSize];
	size_t converted = 0;
	mbstowcs_s(&converted, wcMsg, msgSize, charPtr, _TRUNCATE);
	return wcMsg;
}

#endif // defined(_WIN32) || defined(_WIN64)