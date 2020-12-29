#pragma once

#ifndef PLEXFX_PLATFORM
	#if __SIZEOF_POINTER__ == 8 || __SIZEOF_POINTER__ == 4 || _WIN32 || _WIN64
		#define PLEXFX_PLATFORM 2
	#else
		#define PLEXFX_PLATFORM 1
	#endif
#endif

#if PLEXFX_PLATFORM == 1
	#include "PlatformDefaults/PlatformAVR.h"
#elif PLEXFX_PLATFORM == 2
	#include "PlatformDefaults/PlatformX86.h"
#else
	#error "PlexFx: Couldn't detect platform"
#endif

#define PLEXFX_TYPE_INDEX PLEXFX_TYPE_BOUND
namespace PlexFx {
	typedef PLEXFX_TYPE_BOUND Index;
	typedef PLEXFX_TYPE_FXID ID;
}
