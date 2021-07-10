#include "Program.h"

cProgram::cProgram()
{
	
}
/*
void cProgram::Run()
{
	try
	{
		m_Program->Run(); //Start and run the program
	}
	//catch (Oz::Exception& exception)
	//{
	//	std::cout << "OzEngine Exception: " << exception.what() << std::endl;
	//}
	catch (std::exception& exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "An unknown object was thrown, duck!" << std::endl;
	}
}
*/

cProgram::~cProgram()
{

}

std::unique_ptr<Oz::cApplication> Oz::CreateApplication()
{
	return std::make_unique<cProgram>();
}