#include "OpenGLWindow.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Oz
{
	cOpenGLWindow::cOpenGLWindow(const std::string& _Title,
		uint32_t _Width, uint32_t _Height, bool _Fullscreen) 
		: cWindow(_Title, _Width, _Height, _Fullscreen)
	{
		//Setup GLFW
		if (glfwInit() != GLFW_TRUE)
		{
			//error is returned if glfw init fails
#if _DEBUG
			OZ_CORE_CRITICAL("ERROR: Unable to initialize glfw!");
#endif // _DEBUG
			throw std::exception();
		}

		SetFullscreen(_Fullscreen);

		//Create GLFW Window
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Context = cGraphicsContext::Create(m_Window);
		m_Context->Init();

		///Look into using glfwSetWindowUserPointer
		SetVSync(true); //Temp setting for VSync
	}

	void cOpenGLWindow::SetFullscreen(bool _Fullscreen)
	{
		if (IsFullscreen() == _Fullscreen)
			return;

		//_Fullscreen ? m_Windowed = nullptr : m_Windowed = glfwGetPrimaryMonitor();
	}

	void cOpenGLWindow::OnUpdate()
	{
		m_Context->SwapBuffers(); //Swap the window buffers after clearing has occured
		glfwPollEvents(); //Poll incoming events to the window
	}

	void cOpenGLWindow::SetVSync(bool _Enabled)
	{
		if (_Enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_VSync = _Enabled;
	}

	bool cOpenGLWindow::IsVSync() const
	{
		return m_VSync;
	}

	cOpenGLWindow::~cOpenGLWindow()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}
}