#ifndef _SECTIONS_SECTIONS_H
#define _SECTIONS_SECTIONS_H
	
// macros for sections; so i don't need to type the 
// __attribute__((section(".section"))) bullshit

#define _init __attribute__((section(".init")))

// kernel modules sit in high memory under the kernel.
// #define __MODULE__ __attribute__((section("module"))) 

#endif // _SECTIONS_SECTIONS_H
