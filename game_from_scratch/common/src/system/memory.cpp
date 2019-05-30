
#include <common/system/memory.h>
#include <common/diagnostics/assertion.h>
#include <stdlib.h>
#include <string.h>

void* Common::Memory::alloc(Size sizeInBytes) {
	void* mem = malloc(sizeInBytes);
	ensure(mem != nullptr && "Memory allocation failed");
	return mem;
}

void Common::Memory::release(void* ptr) {
	ensure(ptr != nullptr && "Attempting to free a nullptr");
	free(ptr);
}

void* Common::Memory::move(void* source, void* destination, Size sizeInBytes) {
	void* dest = memmove(destination, source, sizeInBytes);
	ensure(dest == destination && "Memory move failed");
	return dest;
}

void* Common::Memory::copy(void* source, void* destination, Size sizeInBytes) {
	void* dest = memcpy(destination, source, sizeInBytes);
	ensure(dest == destination && "Memory copy failed");
	return dest;
}
