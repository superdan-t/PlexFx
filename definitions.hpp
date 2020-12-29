#pragma once

#ifndef PLEXFX_PLATFORM
	#ifdef ARDUINO
		#define PLEXFX_PLATFORM 1
	#else
		#define PLEXFX_PLATFORM 2
	#endif
#endif

#if PLEXFX_PLATFORM == 1
	#include "platform_defaults/platform_avr.h"
#elif PLEXFX_PLATFORM == 2
	#include "platform_defaults/platform_32_64.h"
#endif
