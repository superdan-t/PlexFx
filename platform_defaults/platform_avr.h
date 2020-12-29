/**
 * Default types for AVR architecture (Arduino)
 * 
 * Types are only 8-bit to improve speed/memory usage on microcontrollers
 * 
 * Since more than 256 LEDs is theoretically possible, a solution to switch to
 * 16-bit indices is planned. However, consider that a single Arduino may
 * struggle with so many LEDs, both with memory and processing power.
 */

#define PLEXFX_PLATFORM_AVR

#include <stdint.h>

namespace PlexFx {
	typedef uint8_t ID;
	typedef uint8_t Index;
}
