#ifndef _REMIEL_SYSTEM_H
#define _REMIEL_SYSTEM_H

#include <stdint.h>

// idk i wrote this in assembly... i felt quirky
extern void _optimized_memset_32(uint8_t src, void *dst, uint32_t iterations);

extern void _optimized_memcpy_32(void *src, void *dst, uint16_t buffer_size)

#define memset _optimized_memset_32
#define memcpy _optimized_memcpy_32

#endif // _REMIEL_SYSTEM_H
