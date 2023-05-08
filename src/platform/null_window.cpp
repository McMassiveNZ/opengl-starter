#include "../window.h"

namespace ogl_starter
{

class NullWindowImpl final : public Window
{
public:
	NullWindowImpl() = default;
	~NullWindowImpl() override = default;

	NullWindowImpl(NullWindowImpl&&) = delete;
	NullWindowImpl& operator=(NullWindowImpl&&) = delete;
	NullWindowImpl(const NullWindowImpl&) = delete;
	NullWindowImpl& operator=(const NullWindowImpl&) = delete;

	void PumpMessages() override {}
	bool ShouldClose() const override { return false; }
	void* GetNativeHandle() const override { return nullptr; }

};

} // namespace starter_window

std::unique_ptr<ogl_starter::Window> oglsCreateWindow(ogl_starter::WindowCreateParams)
{
	auto result = std::make_unique<ogl_starter::NullWindowImpl>();
	return result;
}
