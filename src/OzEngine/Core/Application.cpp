#include "Application.h"

namespace Oz
{
	cApplication::cApplication()
	{
		m_Running = false;
	}

	void cApplication::Run()
	{
		m_Running = true;
		while (m_Running)
		{

		}
	}

	cApplication::~cApplication()
	{

	}
}