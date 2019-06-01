#ifndef __THREAD_GUARD__
#define __THREAD_GUARD__

#include <common/system/system.h>

namespace Common {
	class COMMON Thread {
	public:
		static void sleep_ms(UInt64 milliseconds);
	};
}
#endif//__THREAD_GUARD__
