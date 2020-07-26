/** Define dll import/export system if on Windows **/
/** BUILD_DLL is only defined in engine **/

#ifndef _CCORE_H_
#define _CCORE_H_

#ifdef _WINDOWS
	#ifdef BUILD_DLL
		#define OZ_API __declspec(dllexport)
	#else
		#define OZ_API __declspec(dllimport)
	#endif
#else
	#error Oz Engine only supports windows
#endif
#endif