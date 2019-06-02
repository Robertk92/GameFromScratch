#ifndef __TIMESPAN_GUARD__
#define __TIMESPAN_GUARD__

#include <common/system/system.h>

namespace Common {
	class COMMON Timespan {
	public:
		Timespan(UInt32 milliseconds);
		static Timespan FromSeconds(double seconds);

		const UInt32 milliseconds() const;
		const double seconds();

		bool operator>(const Timespan& rhs);
		bool operator<(const Timespan& rhs);
		bool operator>=(const Timespan& rhs);
		bool operator<=(const Timespan& rhs);
		bool operator==(const Timespan& rhs);
		bool operator!=(const Timespan& rhs);

	private:
		UInt32 _ms;
	};
}

#endif//__TIMESPAN_GUARD__
