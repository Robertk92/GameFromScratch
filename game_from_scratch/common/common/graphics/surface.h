#ifndef __SURFACE_GUARD__
#define __SURFACE_GUARD__

#include <common/system/system.h>

namespace Common {
	class COMMON Surface {
	public:
		Surface(int width, int height);
		virtual ~Surface();

		Size width() const;
		Size height() const;
		const UInt32* buffer() const;

		void set_pixel(int x, int y, UInt32 value);

	private:
		UInt32* _rgbBuffer;
		Size _width;
		Size _height;
	};
}

#endif//__SURFACE_GUARD__
