#include <x86/cpu/idt.h>
#include <x86/cpu/gdt.h>


void set_idt_entry(struct idt_entry *idt_descriptor, void (*handler_address_32) (void), uint8_t attributes) {
  
  idt_descriptor->offset_low = ((0xffff << 16) & handler_address_32);
  idt_descriptor->code_segment_selector = KERNEL_CODE_SEGMENT_SELECTOR;
  idt_descriptor->reserved = 0;
  idt_descriptor->attributes = attributes;
  idt_descriptor->offset_high = (~(0xffff << 16) & handler_address_32);
}

void set_idt_descriptor(struct idtr *idt_register, struct idt_entry *table_address, uint16_t sizeof_idt) {
  
  idtr->limit = (uint32_t)table_address;
  idtr->limit = sizeof_idt;
  i
}


