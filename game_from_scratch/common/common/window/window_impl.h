#ifndef __WINDOW_IMPL_GUARD__
#define __WINDOW_IMPL_GUARD__

#include <common/system/system.h>
#include <common/window/window_options.h>

namespace Common {
	class Surface;
	class WindowMessage;
	class COMMON WindowImpl {
	public:
		WindowImpl(const WindowOptions& windowOptions, Surface* surface) { }
		virtual ~WindowImpl() { }

		virtual void set_size(int width, int height) = 0;
		virtual bool poll_message(WindowMessage* msg) = 0;
		virtual void draw() = 0;
	};
}

#endif //__WINDOW_IMPL_GUARD__
