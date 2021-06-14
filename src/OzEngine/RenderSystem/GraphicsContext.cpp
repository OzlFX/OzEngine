#include "GraphicsContext.h"

#include "OzEngine/RenderSystem/OpenGL/OpenGLContext.h"

namespace Oz
{
	std::unique_ptr<cGraphicsContext> cGraphicsContext::Create(void* _Window)
	{
		return std::make_unique<cOpenGLContext>(static_cast<GLFWwindow*>(_Window));
	}
}