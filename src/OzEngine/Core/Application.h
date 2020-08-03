/** Base application functionality which allows for all client programs to run **/
#ifndef _CAPPLICATION_H_
#define _CAPPLICATION_H_

//Includes
#include <iostream>
#include <memory>
#include <list>
#include <vector>

#include <glm/glm.hpp>

#include "Core.h"

namespace Oz
{
	class OZ_API cApplication
	{
	public:

		cApplication();

		void Run();

		virtual ~cApplication();

	private:

		bool m_Running;
	};

	std::unique_ptr<cApplication> CreateApplication(); //Define in the Client
}

#endif