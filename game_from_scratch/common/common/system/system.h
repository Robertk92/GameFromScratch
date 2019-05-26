#ifndef __SYSTEM_GUARD_H
#define __SYSTEM_GUARD_H

#include <stdint.h>

#define COMMON __declspec(dllexport)

template<typename T>
struct COMMON IsPointer { static const bool value = false; };

template<typename T>
struct COMMON IsPointer<T*> { static const bool value = true; };

#endif
