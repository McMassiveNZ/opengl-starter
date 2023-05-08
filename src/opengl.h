#pragma once

#include <memory>

namespace ogl_starter
{
class Window;

struct OpenGLCreateParams
{
	void* nativeWindowHandle;
	int versionMajor;
	int versionMinor;
};

class OpenGL
{
public:
	virtual ~OpenGL() = default;
	virtual void ClearBuffers() = 0;
	virtual void SwapBuffers() = 0;

	virtual void DrawScene() = 0;
};

} // namespace ogl_starter

std::unique_ptr<ogl_starter::OpenGL> oglsCreateOpenGL(ogl_starter::OpenGLCreateParams params);