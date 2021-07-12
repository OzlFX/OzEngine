#ifndef _OPENGLWINDOW_H_
#define _OPENGLWINDOW_H_

#include "Window.h"
#include "OzEngine/RenderSystem/GraphicsContext.h"

struct GLFWwindow;
struct GLFWmonitor;

namespace Oz
{

	class cOpenGLWindow : public cWindow
	{
	public:

		cOpenGLWindow(const std::string& _Title = "Oz Engine Game",
			uint32_t _Width = 1280,
			uint32_t _Height = 720, bool _Fullscreen = false);

		void OnUpdate() override;

		void SetFullscreen(bool _Fullscreen) override;

		std::string GetTitle() const override { return m_Title; }
		uint32_t GetWidth() const override { return m_Width; }
		uint32_t GetHeight() const override { return m_Height; }
		bool IsFullscreen() const override { return m_Fullscreen; }

		//Window Attributes
		void SetEventCallback() override { OZ_CORE_INFO("Unused currently since its not implimented"); }
		void SetVSync(bool _Enabled) override;
		bool IsVSync() const override;

		void* GetNativeWindow() const override { return m_Window; }

		virtual ~cOpenGLWindow();

	private:

		GLFWwindow* m_Window;
		//GLFWmonitor* m_Windowed = nullptr;

		std::unique_ptr<cGraphicsContext> m_Context;

	};
}

#endif // !_OPENGLWINDOW_H_