#ifndef __THREAD_GUARD__
#define __THREAD_GUARD__

#include <common/system/system.h>

namespace Common {
	class ThreadImpl;
	class COMMON Thread final {
	public:
		Thread();
		~Thread();

		static void sleep_ms(UInt32 milliseconds);

	private:
		ThreadImpl* _threadImpl;
	};
}
#endif//__THREAD_GUARD__
