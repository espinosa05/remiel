#ifndef _V86_H
#define _V86_H

#include <stdarg.h> /* thank god this is freestanding */
#include <stdint.h>


uint16_t v86_int(uint8_t vector, ...);


#endif /* _V86_H */
