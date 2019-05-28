#ifndef __MEMORY_GUARD__
#define __MEMORY_GUARD__

#include <common/diagnostics/assertion.h>
#include <common/system/system.h>

class COMMON Memory {
public:
	static void* alloc(size_t sizeInBytes) {
		void* allocAdr = malloc(sizeInBytes);
		ENSURE(allocAdr != nullptr && "Memory allocation failed");
		return allocAdr;
	}
};

#endif
