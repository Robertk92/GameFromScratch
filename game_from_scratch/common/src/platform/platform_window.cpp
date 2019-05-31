#include <common/platform/platform_window.h>
#include <common/platform/window_impl.h>
#include <common/diagnostics/assertion.h>

#if defined (_WIN32) || defined(_WIN64)
	#include <common/platform/windows/win_window_impl.h>
#elif defined(__APPLE__)
	not_implemented();
#elif defined(__linux__)
	not_implemented();
#else
	not_implemented();
#endif

Common::PlatformWindow::PlatformWindow(const WindowOptions& options) {
#if defined (_WIN32) || defined(_WIN64)
	_window = new WinWindowImpl(options);
#elif defined(__APPLE__)
	not_implemented();
#elif defined(__linux__)
	not_implemented();
#else
	not_implemented();
#endif
}

Common::PlatformWindow::~PlatformWindow() {
	if (_window != nullptr) {
		delete _window;
	}
}

void Common::PlatformWindow::set_size(int width, int height) {
	ensure(_window != nullptr);
	_window->set_size(width, height);
}
