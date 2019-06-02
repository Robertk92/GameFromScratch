#ifndef __WINDOW_GUARD__
#define __WINDOW_GUARD__

#include <common/system/system.h>
#include <common/collections/string.h>
#include <common/window/window_options.h>
#include <common/graphics/surface.h>

namespace Common {
	enum COMMON EWindowMessageType {
		None,
		Close
	};

	struct COMMON WindowMessage {
		EWindowMessageType type;
		WindowMessage() {
			type = EWindowMessageType::None;
		}
	};

	class WindowImpl;
	class COMMON Window : public Surface {
	public:
		Window(const WindowOptions& options);
		virtual ~Window();

		void set_size(int width, int height);
		const bool is_open() const;
		void draw();
		bool poll_message(WindowMessage* msg);
		void close();

	private:
		WindowImpl* _windowImpl;
	};
}

#endif//__WINDOW_GUARD__
