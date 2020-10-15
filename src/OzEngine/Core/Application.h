/** Base application functionality which allows for all client programs to run **/
#ifndef _CAPPLICATION_H_
#define _CAPPLICATION_H_

//Includes
#include "Base.h"
#include "Core.h"

namespace Oz
{
	class cWindow;
	class cOpenGLWindow;

	class OZ_API cApplication
	{
	public:

		cApplication();

		std::weak_ptr<Window> GetWindow() { return m_Window; } //Get the window
		cApplication& GetApplication() { return *s_Self; } //Get current application instance

		void Run(); //Run the application
		void Close(); //Close the application

		virtual ~cApplication();

	private:
		//Vars for the application
		bool m_Running; //Run check
		bool m_Minimised = false; //Minimised check

		std::shared_ptr<Window> m_Window; //Window
		cApplication* s_Self = nullptr; //Instance of the application
	};

	std::unique_ptr<cApplication> CreateApplication(); //Define in the Client
}

#endif