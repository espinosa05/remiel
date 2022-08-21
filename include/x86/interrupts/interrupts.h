#ifndef _X86_INTERRUPTS_H
#define _X86_INTERRUPTS_H

#include <x86/DPL.h>

#define LIDT( DESCRIPTOR_ADDR ) asm volatile ("lidt %0" : : "r" (DESCRIPTOR_ADDR))

#define MAX_IDT_ENTRIES	256

struct idt_entry {
	uint16_t offset_low;
	uint16_t code_seg;
	uint8_t reserved;
	uint8_t attributes;
	uint16_t offset_high;
}
__attribute__((packed));

struct idtr {
	uint16_t size;
	uint32_t offset;
}
__attribute__((packed));

// hardware interrupts ignore DPL
#define HARDWARE_INTERRUPT	0

// type flags
#define TASK_GATE_32		5
#define INTERRUPT_GATE_32 	0xe
#define TRAP_GATE_32		0xf

#define SET_ATTRIBUTES( TYPE, DPL ) (TYPE | DPL << 5 | 1 << 7)

#define SET_IDT_DESCRIPTOR( IDT_REGISTER, OFFSET)\
	IDT_REGISTER->size = sizeof(idt_entry) * MAX_IDT_ENTRIES;\
	IDT_REGISTER->offset = OFFSET;

#define LIDT(IDT_DESCRIPTOR_ADDRESS) asm volatile("lidt %0"::"m"(IDT_DESCRIPTOR_ADDRESS));
void set_gate_descriptor(,uint32_t handler_address, uint8_t attributes, int gate_type );

#endif // _X86_INTERRUPTS_H
