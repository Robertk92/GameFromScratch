#ifndef __SYSTEM_GUARD__
#define __SYSTEM_GUARD__

typedef __int8				Int8;
typedef __int16				Int16;
typedef __int32				Int32;
typedef __int64				Int64;
typedef unsigned __int8		UInt8;
typedef unsigned __int16	UInt16;
typedef unsigned __int32	UInt32;
typedef unsigned __int64	UInt64;

typedef UInt64	Size;
typedef Int64	PtrDiff;
typedef Int64	IntPtr;

#define _CRT_SECURE_NO_WARNINGS
#define COMMON __declspec(dllexport)

#if defined(_WIN32) || defined(_WIN64)
	#include <windows.h>
#elif defined(__Apple__)
	// TODO_APPLE: include apple system header
#elif defined(__linux__)
	// TODO_LINUX: include linux system header
#endif

namespace Common {
	class String;
	class COMMON Out {
	public:
		static void log_no_newline(const String& str);
		static void log(const String& str);
		static void error(const String& errStr);
		static void error(const char* err);
		static void error(const char* err, const char* file, int line);

	private:
		static void log_internal(const char* chars);
	};

	class COMMON In {
	public:
		
	private:

	};
}

#endif //__SYSTEM_GUARD__
