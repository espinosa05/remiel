#ifndef _X86_CPU_GDT_H
#define _X86_CPU_GDT_H

#include <stdint.h>


#define MAX_GDT_ENTRIES 5

// gdt array indecies
#define NULL_DESCRIPTOR         0
#define KERNEL_CODE_DESCRIPTOR  1
#define KERNEL_DATA_DESCRIPTOR  2
#define USER_CODE_DESCRIPTOR    3
#define USER_DATA_DESCRIPTOR    4
#define TASK_STATE_DESCRIPTOR   5

// offsets
#define KERNEL_CODE_SEGMENT_SELECTOR (KERNEL_CODE_DESCRIPTOR  * sizeof(gdt_entry_t))
#define KERNEL_DATA_SEGMENT_SELECTOR (KERNEL_DATA_DESCRIPTOR  * sizeof(gdt_entry_t))
#define USER_CODE_SEGMENT_SELECTOR   (USER_CODE_DESCRIPTOR    * sizeof(gdt_entry_t))
#define USER_DATA_SEGMENT_SELECTOR   (USER_DATA_DESCRIPTOR    * sizeof(gdt_entry_t))
#define TASK_STATE_SEGMENT_SELECTOR  (TASK_STATE_DESCRIPTOR   * sizeof(gdt_entry_t))

// flags
#define _PROTECTED_MODE     0
#define _32_BIT_GDT_ENTRY   (1 << 2)
#define _PAGE_GRANULARITY   (1 << 3)

// common flag combinations

#define DPL0_CODE
#define DPL0_DATA
#define DPL1_CODE
#define DPL1_DATA
#define DPL2_CODE
#define DPL2_DATA
#define DPL3_CODE
#define DPL3_DATA

struct gdtr {
  uint16_t limit;
  uint32_t base;
}


struct gdt_entry {
  uint16_t limit_0;
  uint16_t base_0;
  uint8_t base_1;
  uint8_t access_byte;
  unsigned int limit_1 : 4;
  unsigned int flags : 4;
  uint8_t base_2;
}
__attribute__((packed));

void set_gdt_entry(gdt_entry_t *entry, uint32_t base, uint32_t limit, uint8_t access_byte, uint8_t flags);

#endif // _X86_CPU_GDT_H

