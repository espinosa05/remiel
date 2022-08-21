#include <x86/cpu/gdt.h>

void set_gdt_entry(struct gdt_entry *entry, uint32_t base, uint32_t limit, uint8_t access_byte, uint8_t flags) {
  
  entry->limit0 = (uint16_t)(limit) & (0xffff0000);
  entry->base_0 = (uint16_t)(base) & (0xffff0000);
  entry->base_1 = (uint8_t)((base) & (0xff00 << 16)) >> 16;
  entry->access_byte = access_byte;
  entry->limit_1 = (unsigned long)((limit) & (0xfff0 << 16) >> 16);
  entry->flags = flags;
  entry->base_2 = (uint8_t)(base) & ((0x00ffffff) >> 24);
}

void set_gdt_descriptor(struct gdt_entry *gdt_address, ) {


}
