#ifndef __ASSERTION_GUARD__
#define __ASSERTION_GUARD__

#include <common/system/system.h>
#include <stdlib.h>

#if defined(NDEBUG) 
	#define break_fatal() abort();
#else
	#ifdef _MSC_VER
		#define break_fatal() __debugbreak();
	#elif defined __GNUC__
		#define break_fatal() __builtin_trap();
	#elif defined __clang__
		#if __has_builtin(__builtin_debugtrap)
			#define break_fatal()__builtin_debugtrap();
		#else
			#define BREAK_SIGNAL_FALLBACK
		#endif
	#endif
	#if defined BREAK_SIGNAL_FALLBACK
		#include <signal.h>
		#if defined(SIGTRAP)
			#define break_fatal() raise(SIGTRAP);
		#else
			#define break_fatal() raise(SIGABRT);
		#endif
	#endif
#endif

#define ensure(expression) 										\
	if(!(expression)) {											\
		Common::Out::error(#expression, __FILE__, __LINE__);	\
		break_fatal();											\
	}															\
	
#define ensure_malloc_success(mallocFunc) ensure(mallocFunc != nullptr && "Memory allocation failed");
#define ensure_intmul_no_overflow(a, b) ensure(a <= INT_MAX / b && "Mul operation overflow");
#define ensure_uintmul_no_overflow(a, b) ensure(a <= UINT_MAX / b && "Mul operation overflow");

#define not_implemented() ensure(false && "Not implemented")
#define bad_code(reason) ensure(false && reason)

#endif //__ASSERTION_GUARD__