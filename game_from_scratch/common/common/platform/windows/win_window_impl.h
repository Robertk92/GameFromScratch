#ifndef __WIN_WINDOW_IMPL_GUARD__
#define __WIN_WINDOW_IMPL_GUARD__
#if defined(_WIN32) || defined(_WIN64)

#include <common/system/system.h>
#include <common/platform/window_impl.h>

namespace Common {
	class COMMON WinWindowImpl : public WindowImpl {
	public:
		WinWindowImpl(const WindowOptions& windowOptions);
		virtual ~WinWindowImpl();

		void set_size(int width, int height) override;

	private:
		HWND _hwnd;
	};
}

#endif//defined(_WIN32) || defined(_WIN64)
#endif//__WIN_WINDOW_IMPL_GUARD__
