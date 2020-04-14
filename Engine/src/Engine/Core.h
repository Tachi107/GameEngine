#pragma once

#ifdef _WIN32
	#ifdef ENGINE_BUILD_SHARED
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif
#elif defined(__GNUC__)
	#ifdef ENGINE_BUILD_SHARED
		#define ENGINE_API __attribute__((visibility("default")))
	#else
		#define ENGINE_API
	#endif
#endif
