#include <OzEngine/Core/OzEngine.h>
#include <OzEngine/Core/EntryPoint.h>

class cProgram : public Oz::cApplication
{
public:

	cProgram() {}

	~cProgram() {}
};

std::unique_ptr<Oz::cApplication> Oz::CreateApplication()
{
	return std::make_unique<cProgram>();
}