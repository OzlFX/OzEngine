/** Client program which inherits from Application in order to run **/
#ifndef _CPROGRAM_H_
#define _CPROGRAM_H_

#include <OzEngine/Core/OzEngine.h>

class cProgram : public Oz::cApplication
{
public:

	cProgram();

	~cProgram();
};

#endif