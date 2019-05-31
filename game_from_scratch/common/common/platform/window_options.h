#ifndef __WINDOW_OPTIONS_GUARD__
#define __WINDOW_OPTIONS_GUARD__

#include <common/system/system.h>
#include <common/collections/string.h>

namespace Common {
	struct COMMON WindowOptions {
		int width;
		int height;
		String title;
	};
}

#endif //__WINDOW_OPTIONS_GUARD__

