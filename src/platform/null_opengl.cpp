#include "../opengl.h"

namespace ogl_starter
{
class NullOpenGLImpl final : public OpenGL
{
public:
	~NullOpenGLImpl() override = default;
	NullOpenGLImpl(const NullOpenGLImpl&) = delete;
	NullOpenGLImpl& operator=(const NullOpenGLImpl&) = delete;

	NullOpenGLImpl(NullOpenGLImpl&&) = default;
	NullOpenGLImpl& operator=(NullOpenGLImpl&&) = default;

	void ClearBuffers() override {}
	void SwapBuffers() override {}
	void DrawScene() override {}
};
} // namespace ogl_starter

std::unique_ptr<ogl_starter::Window> oglsCreateWindow(ogl_starter::OpenGLCreateParams)
{
	auto result = std::make_unique<ogl_starter::NullOpenGLImpl>();
	return result;
}
