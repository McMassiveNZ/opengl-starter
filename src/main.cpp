#include "window.h"
#include "opengl.h"

constexpr int CW_USEDEFAULT = 0x80000000;

auto main() -> int
{
	auto window = oglsCreateWindow({
		.x = CW_USEDEFAULT,
		.y = CW_USEDEFAULT,
		.width = CW_USEDEFAULT,
		.height = CW_USEDEFAULT,
		.name = "Starter OpenGL"
	});

	auto renderer = oglsCreateOpenGL({
		.nativeWindowHandle = window->GetNativeHandle(), 
		.versionMajor = 4, 
		.versionMinor = 6
	});
		
	while (!window->ShouldClose())
	{
		window->PumpMessages();

		renderer->ClearBuffers();
		renderer->DrawScene();
		renderer->SwapBuffers();
	}

	return 0;
}
