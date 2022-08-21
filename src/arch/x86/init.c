// freestanding libs
#include <stdint.h>
// remiel libs
#include <remiel/types/remiel_types.h>
#include <remiel/init.h>
#include <remiel/sections/sections.h>
#include <remiel/kernel_status.h>
#include <x86/registers.h>
#include <x86/cpu/cpu.h>
#include <x86/cpu/cpuid.h>
#include <x86/graphics/tty.h>

// TODO try making this not extern
extern tty_controller_t tty;


_init KERNEL_STATUS kernel_init() {

  struct i386_regs regs[MAX_CPUID_FUNCTIONS];
  // get data from the cpu with this struct
  cpu_info_t x86_features;
  int max_cpuid_function_number;
  // array of function pointers for each
  // cpuid function to process the data
  void_function_ptr_t get_cpuid_data[MAX_CPUID_FUNCTIONS];
  // clear the screen
  tty.set_bg = tty.colors.black;
  tty.set_fg = tty.colors.yellow;
  tty.cls();

  if( !is_cpuid_supported() ) {
    save_tty_colors(tty);
		tty.set_fg = tty.color.light_red;
    tty_puts("cpuid is not supported\n");
		tty_puts("possible 386/486 detected\n")
		restore_tty_colors(tty);
	} 
	else {
    // cpuid with EAX set to 0 returns the highest cpuid function number
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

  return status;
}
