#include "OpenGLWindow.h"

namespace Oz
{
	cOpenGLWindow::cOpenGLWindow(const std::string& _Title,
		uint32_t _Width,
		uint32_t _Height, bool _Fullscreen) : cWindow(_Title, _Width, _Height, _Fullscreen)
	{
		//Setup GLFW
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		SetFullscreen(_Fullscreen);

		//Create GLFW Window
		m_Window = glfwCreateWindow(GetWidth(), GetHeight(), GetTitle().c_str(), m_Windowed, NULL);
	}

	void cOpenGLWindow::SetFullscreen(bool _Fullscreen)
	{
		if (IsFullscreen() == _Fullscreen)
			return;

		_Fullscreen ? m_Windowed = NULL : m_Windowed = glfwGetPrimaryMonitor();
	}

	cOpenGLWindow::~cOpenGLWindow()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}
}