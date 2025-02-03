#pragma once

#ifdef ELD_PLATFORM_WINDOWS
	#ifdef ELD_BUILD_DLL
		#define ELDER_API __declspec(dllexport)
	#else
		#define ELDER_API __declspec(dllimport)
	#endif
#else
	#error ElderEngine support windows only
#endif