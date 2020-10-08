#ifndef _OPENGLWINDOW_H_
#define _OPENGLWINDOW_H_

#include "Window.h"
#include <gl/GL.h>
#include <GLFW/glfw3.h>

namespace Oz
{
	class cOpenGLWindow : public cWindow
	{
	public:

		cOpenGLWindow(const std::string& _Title = "Oz Engine Game",
			uint32_t _Width = 1280,
			uint32_t _Height = 720, bool _Fullscreen = false);

		void SetFullscreen(bool _Fullscreen);

		std::string GetName() const { return m_Title; }
		uint32_t GetWidth() const { return m_Width; }
		uint32_t GetHeight() const { return m_Height; }
		bool IsFullscreen() const { return m_Fullscreen; }

		virtual ~cOpenGLWindow();

	private:

		GLFWwindow* m_Window;
		GLFWmonitor* m_Windowed;

	};
}

#endif // !_OPENGLWINDOW_H_