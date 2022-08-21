#ifndef _X86_CPU_TSS_H
#define _X86_CPU_TSS_H

typedef struct {
  uint32_t ssp;
  uint16_t reserved_0 = 0;
  uint16_t iopb;
  uint16_t ldtr;
  uint16_t reserved_1 = 0;
  uint16_t gs;
  uint16_t reserved_2 = 0;
  uint16_t fs;
  uint16_t reserved_3 = 0;
  uint16_t ds;
  uint16_t reserved_4 = 0;
  uint16_t ss;
  uint16_t reserved_5 = 0;
  uint16_t cs;
  uint16_t reserved_6 = 0;
  uint16_t es;
  uint16_t reserved_7 = 0;
  uint32_t edi;
  uint32_t esi;
  uint32_t ebp;
  uint32_t esp;
  uint32_t ebx;
  uint32_t edx;
  uint32_t ecx;
  uint32_t eax;
  uint32_t eflags;
  uint32_t eip;
  uint32_t cr0;
  uint16_t ss_dpl_2;
  uint16_t reserved_8 = 0;
  uint32_t esp_dpl_2;
  uint16_t ss_dpl_1;
  uint16_t reserved_9 = 0;
  uint32_t esp_dpl_1;
  uint16_t ss_dpl_0;
  uint16_t reserved_a = 0;
  uint32_t esp_dpl_0
  uint16_t link // previous task selector
}
__attribute__((packed))
tss32_t;

#endif // _X86_CPU_TSS_H
