#ifndef __THREAD_IMPL_GUARD__
#define __THREAD_IMPL_GUARD__

#include <common/system/system.h>

namespace Common {
	class COMMON ThreadImpl {
	public:
		virtual ~ThreadImpl() = 0;
	};
}
#endif//__THREAD_IMPL_GUARD__
