// freestanding libs
#include <stdint.h>

// remiel libs
#include <remiel/string.h>
#include <remiel/init.h>
#include <remiel/sections/sections.h>
#include <remiel/kernel_status.h>
#include <x86/registers.h>
#include <x86/cpu/cpu.h>
#include <x86/cpu/cpuid.h>
#include <x86/graphics/tty.h>

extern tty_controller_t tty;


_init KERNEL_STATUS
kernel_init()
{
	struct i386_regs regs[6];
	// get data from the cpu with this struct
	cpu_info_t x86_info;
	int max_cpuid_num;

	tty.set_bg = tty.colors.black;
	tty.set_fg = tty.colors.yellow;
	tty.cls();
	

	regs[0].eax = CPUID_FUNCTION_0;
	cpuid(&regs[0]);
	max_cpuid_num = regs[0].eax;

	// array of function pointers for each
	// cpuid function to process the data
	cpuid_output_converter_t *get_cpuid_data;
		
	set_cpuid_functions(get_cpuid_data);
	
	for(int i = 0; i <= max_cpuid_num; i++)
	{
		get_cpuid_data[i](&x86_info, &regs[i]);
	}

		

	tty_puts(x86_info.vendor_string);
	tty_puts("\n");

	if(is_cpuid_supported())
	{
		tty_puts("features: cpuid");
		
	}
	else
	{
			
	}

	return 0;
}

