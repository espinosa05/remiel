#ifndef _X86_ASM_H
#define _X86_ASM_H

// i find asm blocks with labels to be quite unreadable
#define ASM_LABEL(label) asm (label":")


// GNU-assembler directives

// we need the compiler to shut the fuck up
// and stop messing with the code.
// it ends up looking really ugly but i don't know how to do it
// otherwise :/
#define SET_REORDER() asm volatile(".set reorder\n\t")
#define SET_NOREORDER() asm volatile(".set noreorder\n\t")

#endif // _X86_ASM_H
