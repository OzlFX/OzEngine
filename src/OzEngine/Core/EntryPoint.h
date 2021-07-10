/** ENTRY POINT which allows for any program using the engine to run when on Windows **/
#ifndef _ENTRYPOINT_H_
#define _ENTRYPOINT_H_

#include <OzEngine/Core/Base.h>
#include <OzEngine/Core/Application.h>

#ifdef _WINDOWS

//extern std::unique_ptr<Oz::cApplication> Oz::CreateApplication();

int main(int argc, char** argv)
{
	Oz::cLog::Init();
	//-------------------------------
	auto Game = Oz::CreateApplication();
	Game->Run();
}

#endif // _WINDOWS
#endif