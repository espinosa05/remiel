#ifndef X86_REGISTERS_H
#define X86_REGISTERS_H
#include <stdint.h>
 struct i386_regs {
         union {
                 uint16_t di;
                 uint32_t edi;
         };
         union {
                 uint16_t si;
                 uint32_t esi;
         };
         union {
                 uint16_t bp;
                 uint32_t ebp;
         };
         union {
                 uint16_t sp;
                 uint32_t esp;
         };
         union {
                 struct {
                         uint8_t bl;
                         uint8_t bh;
                 } __attribute__ (( packed ));
                 uint16_t bx;
                 uint32_t ebx;
         };
         union {
                 struct {
                         uint8_t dl;
                         uint8_t dh;
                 } __attribute__ (( packed ));
                 uint16_t dx;
                 uint32_t edx;
         };
         union {
                 struct {
                         uint8_t cl;
                         uint8_t ch;
                 } __attribute__ (( packed ));
                 uint16_t cx;
                 uint32_t ecx;
         };
         union {
                 struct {
                         uint8_t al;
                         uint8_t ah;
                 } __attribute__ (( packed ));
                 uint16_t ax;
                 uint32_t eax;
         };
 } __attribute__ (( packed ));

#endif /* X86_REGISTERS_H */
