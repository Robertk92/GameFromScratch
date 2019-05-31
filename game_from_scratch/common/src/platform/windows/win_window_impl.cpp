#if defined(_WIN32) || defined(_WIN64)
#include <common/platform/windows/win_window_impl.h>
#include <common/platform/windows/win_utility.h>
#include <common/platform/platform_window.h>
#include <common/diagnostics/assertion.h>
#include <windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = (L"Hello, Windows desktop!");

	switch (message)
	{
	case WM_PAINT: {
		hdc = BeginPaint(hWnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + BLACK_BRUSH));
		// blit begin
		HDC hDC = GetDC(hWnd);

		HBRUSH brush = CreateSolidBrush(RGB(200, 170, 20));
		SelectObject(hDC, brush);


		Ellipse(hDC, 0 + 100, 100 - 100, 100 - 100, 0 + 100);

		DeleteObject(brush);
		ReleaseDC(hWnd, hDC);

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}

Common::WinWindowImpl::WinWindowImpl(const WindowOptions& windowOptions) : WindowImpl(windowOptions) {
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
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

Common::WinWindowImpl::~WinWindowImpl() {

}

void Common::WinWindowImpl::set_size(int width, int height) {
	not_implemented();
}

#endif//#if defined(_WIN32) || defined(_WIN64)