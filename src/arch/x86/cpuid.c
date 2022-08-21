// freestanding libs
#include <stdbool.h>
// custom libs
#include <x86/cpu/cpuid.h>
#include <x86/cpu/cpu.h>
#include <x86/cpu/flags.h>
#include <remiel/types/remiel_types.h>

void cpuid(struct i386_regs *reg) { 
  
  asm volatile("cpuid" : "=a"(reg->eax), "=b"(reg->ebx), "=c"(reg->ecx), "=d"(reg->edx) : "a"(reg->eax));
}

bool is_cpuid_supported() {

  uint32_t eflags_reg_val;
  
  SAVE_FLAGS();
  asm volatile("pushfd\n\tpopl %0":"=r"(eflags_reg_val));

  // set the flag
  eflags_reg_val |= EFLAGS_ID; // (1 << 21)

  asm volatile("push %0"::"r"(eflags_reg_val));
  asm volatile("popfd");
  asm volatile("pushfd\n\tpopl %0":"=r"(eflags_reg_val)); 
  // check if the flag has been updated
  if ((eflags_reg_val & EFLAGS_ID)) {
    return true;
  }
    
  RESTORE_FLAGS();

  return false; 
}
