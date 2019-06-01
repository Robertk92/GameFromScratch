#ifndef __MEMORY_GUARD__
#define __MEMORY_GUARD__

#include <common/system/system.h>

namespace Common {
	class COMMON Memory {
	public:
		static void* alloc(Size sizeInBytes);
		static void release(void* ptr);
		static void* move(void* source, void* destination, Size sizeInBytes);
		static void* copy(void* source, void* destination, Size sizeInBytes);
		static void* set(void* destination, int value, Size sizeInBytes);
	};
}
#endif //__MEMORY_GUARD__