#ifndef __MEMORY_GUARD__
#define __MEMORY_GUARD__

#include <common/diagnostics/assertion.h>
#include <cstdlib>
#include <common/system/system.h>

class COMMON Memory {
public:
	static void* Malloc(size_t sizeInBytes) {
		void* allocAdr = malloc(sizeInBytes);
		ensure(allocAdr != nullptr && "Memory allocation failed");
		return allocAdr;
	}
};

#endif
