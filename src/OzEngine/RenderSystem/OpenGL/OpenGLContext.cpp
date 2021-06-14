#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "OpenGLContext.h"

namespace Oz
{
	cOpenGLContext::cOpenGLContext(GLFWwindow* _WindowHandle)
		: m_WindowHandle(_WindowHandle)
	{

	}

	void cOpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);

		//Initialise glew
		if (glewInit() != GLEW_OK)
		{
			//error is returned if glew init fails
#if _DEBUG
			OZ_CORE_CRITICAL("ERROR: Unable to initialize glew!");
#endif // _DEBUG
			throw std::exception();
		}

		OZ_CORE_INFO(glGetString(GL_VERSION));
	}

	void cOpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}