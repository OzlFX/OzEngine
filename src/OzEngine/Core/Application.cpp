#include "Application.h"
#include <OzEngine/Utilities/Log.h>

#include <GLFW/glfw3.h>

namespace Oz
{
	cApplication* cApplication::s_Self = nullptr;

	cApplication::cApplication()
	{
		m_Running = true;
		s_Self = this;

		m_Window = Oz::cWindow::Create<Window>();
	}

	void cApplication::Run()
	{
		OZ_CORE_WARN("Initialised Log!");
		OZ_INFO("Welcome!");
		
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