#if defined(_WIN32) 
#include <common/window/windows/win_window_impl.h>
#include <common/platform_utility/win_utility.h>
#include <common/window/window.h>
#include <common/diagnostics/assertion.h>
#include <common/system/convert.h>
#include <common/graphics/surface.h>
#include <windows.h>

using namespace Common;

namespace __WndWindowGlobal {
	bool isWndWindowOpen;
	WindowMessage* msg;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	if (__WndWindowGlobal::msg != nullptr) {
		switch (message)
		{
		case WM_CREATE:
			break;
		case WM_ERASEBKGND:
			return (LRESULT)1;
		case WM_QUIT:
			PostQuitMessage(0);
			__WndWindowGlobal::isWndWindowOpen = false;
			__WndWindowGlobal::msg->type = EWindowMessageType::Close;
			break;
		case WM_CLOSE:
			PostQuitMessage(0);
			__WndWindowGlobal::isWndWindowOpen = false;
			__WndWindowGlobal::msg->type = EWindowMessageType::Close;
			break;
		default:
			break;
		}
	}
	else {
		if (message == WM_CLOSE) {
			PostQuitMessage(0);
		}
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

Common::WinWindowImpl::WinWindowImpl(const WindowOptions& windowOptions, Surface* surface) : WindowImpl(windowOptions, surface) {
	this->_surface = surface;
	__WndWindowGlobal::isWndWindowOpen = true;
	_sleepMs = 0;
	_hwnd = NULL;

	WNDCLASSEX wc = { };
	
	HINSTANCE hInstance = GetModuleHandle(0);

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = L"DesktopApp";
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	ensure(RegisterClassEx(&wc) && "Failed to create window: RegisterClassEx failed");

	int xPos = (GetSystemMetrics(SM_CXSCREEN) - windowOptions.width) / 2;
	int yPos = (GetSystemMetrics(SM_CYSCREEN) - windowOptions.height) / 2;

	_hwnd = CreateWindowEx(
		0,
		L"DesktopApp",
		WinUtility::to_wchar_ptr(windowOptions.title.c_str()),
		WS_OVERLAPPEDWINDOW,
		xPos, 
		yPos, 
		windowOptions.width, 
		windowOptions.height,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ensure(_hwnd != NULL && "Failed to create window");

	ShowWindow(_hwnd, 1);
	UpdateWindow(_hwnd);
	SetForegroundWindow(_hwnd);
}

Common::WinWindowImpl::~WinWindowImpl() {
	if (_hwnd != NULL) {
		DestroyWindow(_hwnd);
	}
}

void Common::WinWindowImpl::set_size(int width, int height) {
	not_implemented();
}

void Common::WinWindowImpl::draw() {
	HDC hdc = GetDC(_hwnd);
	RECT winRect;

	GetWindowRect(_hwnd, &winRect);

	Size width = winRect.right - winRect.left;
	Size height = winRect.bottom - winRect.top;

	HBITMAP bmp = CreateCompatibleBitmap(hdc, width, height);
	//CreateCompatibleDC(hdc);
	SelectObject(hdc, bmp);

	BITMAPV4HEADER imageheader;
	imageheader.bV4Size = sizeof(BITMAPV4HEADER);
	imageheader.bV4Width = width;
	imageheader.bV4Height = -((int)height);
	imageheader.bV4Planes = 1;
	imageheader.bV4BitCount = 32;
	imageheader.bV4V4Compression = BI_BITFIELDS;
	imageheader.bV4SizeImage = 0;
	imageheader.bV4XPelsPerMeter = 0;
	imageheader.bV4YPelsPerMeter = 0;
	imageheader.bV4ClrUsed = 0;
	imageheader.bV4ClrImportant = 0;
	imageheader.bV4BlueMask = 0xFFU;
	imageheader.bV4GreenMask = 0xFF00U;
	imageheader.bV4RedMask = 0xFF0000U;
	imageheader.bV4AlphaMask = 0xFF000000U;

	for (Size y = 0; y < _surface->height() / 2; ++y) {
		for (Size x = 0; x < _surface->width() / 2; ++x) {
			_surface->set_pixel(x, y, rand());
		}
	}

	const UInt32* buffer = _surface->buffer();
	SetDIBitsToDevice(hdc,
		0,
		0,
		width,
		height,
		0,
		0,
		0,
		height,
		&buffer[0],
		reinterpret_cast<const BITMAPINFO*>(&imageheader),
		DIB_RGB_COLORS);

	BitBlt(hdc, 0, 0, width, height, hdc, 0, 0, SRCCOPY);

	DeleteObject(bmp);
	ReleaseDC(_hwnd, hdc);
}

bool Common::WinWindowImpl::poll_message(WindowMessage* msg) {
	MSG winMsg;
	__WndWindowGlobal::msg = msg;
	if (PeekMessage(&winMsg, NULL, 0, 0, PM_REMOVE) > 0) {
		TranslateMessage(&winMsg);
		DispatchMessage(&winMsg);
		return msg->type != EWindowMessageType::None;
	}
	return false;
}

bool Common::WinWindowImpl::is_open() {
	return __WndWindowGlobal::isWndWindowOpen;
}

#endif//#if defined(_WIN32) || defined(_WIN64)