/** ENTRY POINT which allows for any program using the engine to run when on Windows **/
#ifndef _ENTRYPOINT_H_
#define _ENTRYPOINT_H_

#ifdef _WINDOWS

#include <OzEngine/Core/Base.h>

//extern std::unique_ptr<Oz::cApplication> Oz::CreateApplication();

int main(int argc, char** argv)
{
	//Only use as a test
	Oz::cLog::Init();
	//-------------------------------
	auto Game = Oz::CreateApplication();
	Game->Run();
}

#endif // _WINDOWS
#endif