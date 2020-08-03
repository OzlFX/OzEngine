/** Window management system to handle creation of window **/
#ifndef _WINDOW_H_
#define _WINDOW_H_

//Includes
#include <OzEngine/Core/Core.h>
#include <OzEngine/Core/PrecompiledHeader/ozpch.h>

namespace Oz
{
	struct sWindowProperties
	{
		std::string m_Title;
		unsigned int m_Width;
		unsigned int m_Height;

		CreateWindow(const std::string& _Title = "Oz Engine Game",
					 unsigned int _Width = 1280, )
					 unsigned int _Height = 720, )
					 {
						
					 }
	};

	class OZ_API cWindow
	{
	public:

	private:

	};
}

#endif