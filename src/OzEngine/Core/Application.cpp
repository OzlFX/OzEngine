#include "Application.h"
#include <OzEngine/Utilities/Log.h>

namespace Oz
{
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