#ifndef __TIMER_GUARD__
#define __TIMER_GUARD__

#include <common/system/system.h>

namespace Common {
	class Timespan;
	class COMMON Timer {
	public:
		Timer(const Timespan& interval);
	};
}
#endif//__TIMER_GUARD__
