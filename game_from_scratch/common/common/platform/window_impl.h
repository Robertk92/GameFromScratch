#ifndef __WINDOW_IMPL_GUARD__
#define __WINDOW_IMPL_GUARD__

#include <common/system/system.h>
#include <common/platform/window_options.h>

namespace Common {
	class COMMON WindowImpl {
	public:
		WindowImpl(const WindowOptions& windowOptions) { }
		virtual ~WindowImpl() { }

		virtual void set_size(int width, int height) = 0;
	};
}

#endif //__WINDOW_IMPL_GUARD__
