#include "Application.h"
#include <OzEngine/Utilities/Log.h>
#include <OzEngine/Core/Window/OpenGLWindow.h>

namespace Oz
{
	cApplication* cApplication::s_Self = nullptr;

	cApplication::cApplication()
	{
		m_Running = true;
		s_Self = this;
	}

	void cApplication::Run()
	{
		OZ_CORE_WARN("Initialised Log!");
		OZ_INFO("Welcome!");
		m_Window = Oz::cWindow::Create<Window>();
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

	void cApplication::Close()
	{
		m_Running = false;
	}

	cApplication::~cApplication()
	{

	}
}