#ifndef _X86_FARPOINTER_H
#define _X86_FARPOINTER_H

#include <stdint.h>

typedef struct
{
	uint16_t base;
	uint16_t offset;
}
__attribute__((packed))far_ptr_t;


 __attribute__((always_inline)) inline uint32_t
translate_far_ptr(far_ptr_t far)
{
	return (far.base + far.offset);
}


#endif // _X86_FARPOINTER_H
