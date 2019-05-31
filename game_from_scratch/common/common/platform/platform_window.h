#ifndef __PLATFORM_WINDOW_GUARD__
#define __PLATFORM_WINDOW_GUARD__

#include <common/system/system.h>
#include <common/collections/string.h>
#include <common/platform/window_options.h>

namespace Common {
	class WindowImpl;
	class COMMON PlatformWindow {
	public:
		PlatformWindow(const WindowOptions& options);
		virtual ~PlatformWindow();

		void set_size(int width, int height);
		
	private:
		WindowImpl* _window;
	};
}

#endif//__PLATFORM_WINDOW_GUARD__
