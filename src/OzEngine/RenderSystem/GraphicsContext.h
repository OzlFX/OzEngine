#ifndef _GRAPHICSCONTEXT_H_
#define _GRAPHICSCONTEXT_H_

#include <Windows.h>
#include <memory>

#include "OzEngine/Utilities/Log.h"

namespace Oz
{
	class cGraphicsContext
	{
	public:

		virtual ~cGraphicsContext() = default;

		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

		static std::unique_ptr<cGraphicsContext> Create(void* _Window);
	};
}

#endif