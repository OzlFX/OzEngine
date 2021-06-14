#ifndef _OPENGLCONTEXT_H_
#define _OPENGLCONTEXT_H_

#include "OzEngine/RenderSystem/GraphicsContext.h"

struct GLFWwindow;

namespace Oz
{
	class cOpenGLContext : public cGraphicsContext
	{
	public:

		cOpenGLContext(GLFWwindow* _WindowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:

		GLFWwindow* m_WindowHandle;

	};
}

#endif