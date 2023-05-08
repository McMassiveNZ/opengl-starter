#pragma once

#include <memory>

namespace ogl_starter
{

struct WindowCreateParams
{
	int x;
	int y;
	int width;
	int height;
	const char* name;
};

class Window
{
public:
	virtual ~Window() = default;
	virtual void PumpMessages() = 0;
	virtual bool ShouldClose() const = 0;
	virtual void* GetNativeHandle() const = 0;

	template< typename T >
	T NativeHandle() const
	{
		return static_cast<T>(GetNativeHandle());
	}
};

}

std::unique_ptr<ogl_starter::Window> oglsCreateWindow(ogl_starter::WindowCreateParams params);
