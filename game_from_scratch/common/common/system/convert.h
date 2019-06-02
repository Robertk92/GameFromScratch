#ifndef __CONVERT_GUARD__
#define __CONVERT_GUARD__

#include <common/system/system.h>

namespace Common {
	class String;
	class COMMON Convert {
	public:
		static String to_string(Int32 value);
		static String to_string(Int16 value);
		static String to_string(Int8 value);
		static String to_string(UInt32 value);
		static String to_string(UInt16 value);
		static String to_string(UInt8 value);
		static String to_string(float value);
		static String to_string(double value);
		static String to_string(bool value);
	};
}
#endif//__CONVERT_GUARD__
