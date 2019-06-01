#include <common/graphics/surface.h>
#include <common/system/memory.h>

Common::Surface::Surface(int width, int height) {
	this->_width = width;
	this->_height = height;
	_rgbBuffer = (UInt32*)Memory::alloc(width * height * sizeof(UInt32));
	for (Size i = 0; i < width * height; ++i) {
		_rgbBuffer[i] = 0x00000000;
	}
}

Common::Surface::~Surface() {
	if (_rgbBuffer != nullptr) {
		Memory::release(_rgbBuffer);
	}
}

Size Common::Surface::width() const {
	return _width;
}

Size Common::Surface::height() const {
	return _height;
}

const UInt32* Common::Surface::buffer() const {
	return _rgbBuffer;
}

void Common::Surface::set_pixel(int x, int y, UInt32 value) {
	_rgbBuffer[x + _width * y] = value;
}
