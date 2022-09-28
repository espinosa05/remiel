// freestanding libraries
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
// custom libraries
#include <x86/farpointer.h>
#include <x86/graphics/tty.h>
#include <x86/VGA/VGA.h>
#include <x86/VESA/VESA.h>
#include <remiel/sections/sections.h>
#include <remiel/init.h>
#include <remiel/kernel_status.h>
#include <remiel/attributes.h>
#include <x86/asm.h>
#include <x86/io/ports.h>
#include <x86/interrupts/interrupts.h>
#include <x86/cpu/cpu.h>
#include <x86/cpu/cpuid.h>
#include <x86/cpu/gdt.h>

tty_controller_t tty;

_Noreturn _init void kernel_setup(farptr_t vesa_info_block) {
  
  KERNEL_STATUS kernel_status;
  uint32_t eflags_register;

  struct gdt_entry gdt[MAX_GDT_ENTRIES];
  struct gdtr gdt_register;
  
  struct idt_entry idt[MAX_IDT_ENTRIES];
  struct idtr idt_register;
  function_ptr_t isr[MAX_IDT_ENTRIES];

  struct i386_regs regs[MAX_CPUID_FUNCTIONS];
  cpu_info_t x86_features;
  int max_cpuid_function_number;
  void_function_ptr_t get_cpuid_data[MAX_CPUID_FUNCTIONS];

  SET_NOREORDER(); // GCC may wants to optimize the asm statements and reorder them.
                   // we don't want that.
                   // given, that the entrypoint is inside this function and GCC puts this at the top
                   // the GAS directive should apply to the whole kernel until we disable it.
  eflags_register = get_flags_register_value();

  if( is_flag_set(EFLAGS_ID) ) {
    save_tty_colors(tty);
		tty.set_fg = tty.color.light_red;
		restore_tty_colors(tty);
	} 
	else {
    regs[0].eax = CPUID_FUNCTION_0;
    cpuid(&regs[0]);
    max_cpuid_function_number = regs[0].eax;

    // go through all cpuid functions and extract the needed information
    // from the register struct
    for(int i = 1; i <= max_cpuid_function_number; i++) {
      regs[i].eax = i;
      cpuid(&regs);
      get_cpuid_data[i](&x86_features, &regs[i]);
    }
  }

  set_gdt_entry(&gdt[NULL_DESCRIPTOR], 0, 0, 0);
  set_gdt_entry(&gdt[KERNEL_CODE_DESCRIPTOR], 0, 0xfffff, DPL0_CODE);
  set_gdt_entry(&gdt[KERNEL_DATA_DESCRIPTOR], 0, 0xfffff, DPL0_DATA);
  set_gdt_entry(&gdt[USER_CODE_DESCRIPTOR], 0, 0xfffff, DPL3_CODE);
  set_gdt_entry(&gdt[USER_DATA_DESCRIPTOR], 0, 0xfffff, DPL3_DATA);
  set_gdt_entry(&gdt[TASK_STATE_DESCRIPTOR], 0 , 0, 0);
  
  set_gdt_descriptor(&gdt_register, gdt);

  LGDT(gdt_register, gdt);
  
  LONG_JUMP(KERNEL_CODE_SEGMENT_SELECTOR,"reload_gdt");

  ASM_LABEL("reload_gdt");


  set_gate_descriptor(&idt[1], empty_service_routine, INTERRUPT_GATE_32);

  SET_IDT_DESCRIPTOR(idt_register, idt);
  LIDT(idt_register);
  
  if (x86_features.has_apic) {
    init_APIC(); // IMPLEMENT
  }
  else {
    remap_8259_PIC(); // IMPLEMENT
  }

  STI();
  
  kernel_status = kmain();

  // kernel_init shouldn't exit
	while(1) {
    asm volatile("movl %0, %eax"::"r"(kernel_status));
    HLT();
	}
}

