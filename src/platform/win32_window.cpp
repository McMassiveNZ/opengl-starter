#include "../window.h"

#ifndef NOMINMAX
#define NOMINMAX
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

static LRESULT CALLBACK WindowProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_CLOSE:
		{
			PostQuitMessage(0);
			break;
		}

		default:
			return DefWindowProc(window, message, wParam, lParam);
	}

	return 0;
}

namespace ogl_starter
{

class Win32WindowImpl final : public Window
{
public:
	Win32WindowImpl();

	Win32WindowImpl(const Win32WindowImpl&) = delete;
	Win32WindowImpl& operator=(const Win32WindowImpl&) = delete;

	bool init(WindowCreateParams params);
	void PumpMessages() override;
	bool ShouldClose() const override;
	void* GetNativeHandle() const override;

	HINSTANCE hInstance;
	HWND hWnd;
	bool m_close;
};

Win32WindowImpl::Win32WindowImpl()
	: hInstance(GetModuleHandle(NULL))
	, hWnd(nullptr)
	, m_close(false)
{
}

bool Win32WindowImpl::init(WindowCreateParams params)
{
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = "WindowClass";

	if (RegisterClassEx(&wc) == NULL)
	{
		MessageBox(nullptr, "Call to RegisterClass failed", NULL, MB_OK);
		return false;
	}

	hWnd = CreateWindow(
		wc.lpszClassName,
		params.name,
		WS_OVERLAPPEDWINDOW,
		params.x, params.y, params.width, params.height,
		nullptr,
		nullptr,
		hInstance,
		nullptr);

	if (hWnd == nullptr)
	{
		MessageBox(nullptr, "Call to CreateWindow failed", nullptr, MB_OK);
		return false;
	}

	ShowWindow(hWnd, SW_SHOW);
	return true;
}

void Win32WindowImpl::PumpMessages()
{
	MSG msg = {};
	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			m_close = true;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

bool Win32WindowImpl::ShouldClose() const
{
	return m_close;
}

void* Win32WindowImpl::GetNativeHandle() const
{
	return static_cast<void*>(hWnd);
}
} // namespace ogl_starter

std::unique_ptr<ogl_starter::Window> oglsCreateWindow(ogl_starter::WindowCreateParams params)
{
	auto result = std::make_unique<ogl_starter::Win32WindowImpl>();
	if (result->init(params) == false)
	{
		result = nullptr;
	}

	return result;
}