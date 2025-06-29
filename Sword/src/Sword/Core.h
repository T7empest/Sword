#pragma once

#ifdef SW_PLATFORM_WINDOWS
	#ifdef SW_BUILD_DLL
		#define SWORD_API __declspec(dllexport)
	#else
		#define SWORD_API __declspec(dllimport)
	#endif
#else
#error Only windows is supported!
#endif

#define BIT(x) (1 << x)