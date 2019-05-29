#pragma once

#include <assert.h>
#include <limits.h>

#define ENSURE(condition) assert(condition)
#define ENSURE_INTMUL_NO_OVERFLOW(a, b) ENSURE(a <= INT_MAX / b && "Mul operation overflow");
#define ENSURE_UINTMUL_NO_OVERFLOW(a, b) ENSURE(a <= UINT_MAX / b && "Mul operation overflow");

#define NOT_IMPLEMENTED() ENSURE(false && "Not implemented")
#define BAD_CODE(reason) ENSURE(false && reason)									


							
