#if defined(_WIN32) || defined(_WIN64)
#include <common/platform/windows/win_window_impl.h>
#include <common/platform/windows/win_utility.h>
#include <common/platform/platform_window.h>
#include <common/diagnostics/assertion.h>
#include <common/system/convert.h>
#include <common/graphics/surface.h>
#include <windows.h>

using namespace Common;
int fps = 0;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1000, 1000, NULL);
		break;
	case WM_ERASEBKGND:
		return (LRESULT)1; 
	case WM_PAINT: {
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_TIMER:
		if (wParam == 1000) {
			Out::log(Convert::to_string(fps));
			fps = 0;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}

Common::WinWindowImpl::WinWindowImpl(const WindowOptions& windowOptions, Surface* surface) 
	: WindowImpl(windowOptions, surface) {
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

	MSG msg;
	while (true) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			draw(surface);
		}
	}
}

Common::WinWindowImpl::~WinWindowImpl() {
	if (_hwnd != NULL) {
		DestroyWindow(_hwnd);
	}
}

void Common::WinWindowImpl::set_size(int width, int height) {
	not_implemented();
}

void Common::WinWindowImpl::draw(Surface* surface) {
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

	for (Size y = 0; y < surface->height()/2; ++y) {
		for (Size x = 0; x < surface->width()/2; ++x) {
			surface->set_pixel(x, y, 0x0000FF00);
		}
	}
	
	//surface->set_pixel(0,39, 0x00FF0000);
	/*for (Size y = 2+39; y < surface->height() - 2; ++y) {
		surface->set_pixel(0, y, 0x0000FF00);
	}*/

	const UInt32* buffer = surface->buffer();

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
	fps++;
}

#endif//#if defined(_WIN32) || defined(_WIN64)