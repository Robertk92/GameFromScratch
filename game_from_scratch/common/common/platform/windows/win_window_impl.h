#ifndef __WIN_WINDOW_IMPL_GUARD__
#define __WIN_WINDOW_IMPL_GUARD__
#if defined(_WIN32) || defined(_WIN64)

#include <common/system/system.h>
#include <common/platform/window_impl.h>

namespace Common {
	class Surface;
	class COMMON WinWindowImpl : public WindowImpl {
	public:
		WinWindowImpl(const WindowOptions& windowOptions, Surface* surface);
		virtual ~WinWindowImpl();

		void set_size(int width, int height) override;
		void draw(Surface* surface);

	private:
		HWND _hwnd;
	};
}

#endif//defined(_WIN32) || defined(_WIN64)
#endif//__WIN_WINDOW_IMPL_GUARD__
