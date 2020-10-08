#ifdef _WIN32
	/* Windows x64/x86 */
	#define OZ_PLATFORM_WINDOWS
	/* Make sure the correct window creation is used based on the current platform */
	#ifdef OZ_PLATFORM_WINDOWS
		//#define Window DXWindow
		#define Window Oz::cOpenGLWindow
	#endif
#endif