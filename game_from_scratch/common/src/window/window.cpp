#include <common/window/window.h>
#include <common/window/window_impl.h>
#include <common/diagnostics/assertion.h>

#if defined (_WIN32) || defined(_WIN64)
	#include <common/window/windows/win_window_impl.h>
#elif defined(__APPLE__)
	not_implemented();
#elif defined(__linux__)
	not_implemented();
#else
	not_implemented();
#endif

Common::Window::Window(const WindowOptions& options) : Surface(options.width, options.height) {
#if defined (_WIN32) || defined(_WIN64)
	_window = new WinWindowImpl(options, this);
#elif defined(__APPLE__)
	not_implemented();
#elif defined(__linux__)
	not_implemented();
#else
	not_implemented();
#endif
}

Common::Window::~Window() {
	if (_window != nullptr) {
		delete _window;
	}
}

void Common::Window::set_size(int width, int height) {
	ensure(_window != nullptr);
	_window->set_size(width, height);
}

const bool Common::Window::is_open() const {
	return _window->is_open();
}

void Common::Window::draw() {
	ensure(_window != nullptr && "Failed to draw window, window is nullptr");
	_window->draw();
}

bool Common::Window::poll_message(WindowMessage* msg) {
	return _window->poll_message(msg);
}

void Common::Window::close() {
	if (_window != nullptr) {
		delete _window;
	}
	_window = nullptr;
}
