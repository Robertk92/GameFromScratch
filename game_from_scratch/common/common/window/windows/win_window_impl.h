#ifndef __WIN_WINDOW_IMPL_GUARD__
#define __WIN_WINDOW_IMPL_GUARD__
#if defined(_WIN32) 

#include <common/system/system.h>
#include <common/window/window_impl.h>

namespace Common {
	class Surface;
	class COMMON WinWindowImpl : public WindowImpl {
	public:
		WinWindowImpl(const WindowOptions& windowOptions, Surface* surface);
		virtual ~WinWindowImpl();

		void set_size(int width, int height) override;
		void draw() override;
		bool poll_message(WindowMessage* msg) override;
		bool is_open() override;
		
	private:
		UInt32 _sleepMs;
		Surface* _surface;
		UInt32 _fps;
		UInt32 _framesThisSecond;
		HWND _hwnd;
		LARGE_INTEGER _startingTime;
		LARGE_INTEGER _frequency;
	};
}

#endif//defined(_WIN32) || defined(_WIN64)
#endif//__WIN_WINDOW_IMPL_GUARD__
