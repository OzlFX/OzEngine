#include "Window.h"

namespace Oz
{
	//Create new defined window with window properties
	cWindow::cWindow(const std::string& _Title,
		uint32_t _Width,
		uint32_t _Height, bool _Fullscreen): m_Title(_Title), m_Width(_Width), m_Height(_Height), m_Fullscreen(_Fullscreen)
	{

	}
}