/** Base application functionality which allows for all client programs to run **/
#ifndef _CAPPLICATION_H_
#define _CAPPLICATION_H_

//Includes
#include "Base.h"
#include "Core.h"
#include "OzEngine/Core/Window/Window.h"

int main(int argc, char** argv);

namespace Oz
{
	class OZ_API cApplication
	{
	public:

		cApplication();

		Window& GetWindow() { return *m_Window; } //Get the window
		static cApplication& GetApplication() { return *s_Self; } //Get current application instance

		virtual ~cApplication();

	private:
		
		void Run(); //Run the application
		void Close(); //Close the application

		//Vars for the application
		bool m_Running; //Run check
		bool m_Minimised = false; //Minimised check

		std::unique_ptr<Window> m_Window; //Window
		static cApplication* s_Self; //Instance of the application

		friend int ::main(int argc, char** argv);
	};

	std::unique_ptr<cApplication> CreateApplication(); //Define in the Client
}

#endif