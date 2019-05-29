#pragma once

#include <assert.h>
#include <limits.h>

#define ensure(condition) assert(condition)
#define ensure_intmul_no_overflow(a, b) ensure(a <= INT_MAX / b && "Mul operation overflow");
#define ensure_uintmul_no_overflow(a, b) ensure(a <= UINT_MAX / b && "Mul operation overflow");

#define not_implemented() ensure(false && "Not implemented")
#define bad_code(reason) ensure(false && reason)									


							
