#ifndef _REMIEL_TYPES_REMIEL_TYPES
#define _REMIEL_TYPES_REMIEL_TYPES

// i know this is unsafe but as long as i
// don't fuck up the actual function call
// with the correct parameters, we're safe
typedef void (*void_function_ptr_t) ();
typedef uint8_t (*uint8_function_ptr_t) ();
typedef uint16_t (*uint16_function_ptr_t) ();
typedef uint32_t (*uint32_function_ptr_t) ();

#endif 
