#pragma once

#ifdef _WIN64	// Should not compile on 32 bit systems
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
