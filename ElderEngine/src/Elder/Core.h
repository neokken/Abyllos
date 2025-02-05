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




#ifdef ELD_DEBUG
	#define ELD_ASSERT(x, ...) { if(!(x)) { ELD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ELD_CORE_ASSERT(x, ...) { if(!(x)) { ELD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ELD_ASSERT(x, ...)
	#define ELD_CORE_ASSERT(x, ...)
#endif 
