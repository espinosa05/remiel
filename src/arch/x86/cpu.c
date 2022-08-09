#include <x86/cpu/cpu.h>
#include <x86/cpu/flags.h>
#include <x86/cpu/cpuid.h>
#include <x86/registers.h>
#include <x86/graphics/tty.h>
#include <x86/VGA/VGA.h>
#include <x86/VESA/VESA.h>

extern tty_controller_t tty;


void
set_cpuid_functions(cpuid_output_converter_t *get_cpuid_data)
{
	
	get_cpuid_data[CPUID_FUNCTION_0] = 	get_vendor_string;	
	get_cpuid_data[CPUID_FUNCTION_1] =	get_cpu_features;
	get_cpuid_data[CPUID_FUNCTION_2] =	get_tlb_cache_info;
	get_cpuid_data[CPUID_FUNCTION_3] =	RESERVED;
	get_cpuid_data[CPUID_FUNCTION_4] =	get_cache_type;
	get_cpuid_data[CPUID_FUNCTION_5] =	get_monitor_gran;
}

void
get_vendor_string(cpu_info_t *cpuinfo, struct i386_regs *reg)
{

	cpuinfo->vendor_string[0] = (char)(reg->ebx);
	cpuinfo->vendor_string[1] = (char)(reg->ebx >> 8);
	cpuinfo->vendor_string[2] = (char)(reg->ebx >> 16);
	cpuinfo->vendor_string[3] = (char)(reg->ebx >> 24);

	cpuinfo->vendor_string[4] = (char)(reg->edx);
	cpuinfo->vendor_string[5] = (char)(reg->edx >> 8);
	cpuinfo->vendor_string[6] = (char)(reg->edx >> 16);
	cpuinfo->vendor_string[7] = (char)(reg->edx >> 24);
	
	cpuinfo->vendor_string[8] = (char)(reg->ecx);
	cpuinfo->vendor_string[9] = (char)(reg->ecx >> 8);
	cpuinfo->vendor_string[10] = (char)(reg->ecx >> 16);
	cpuinfo->vendor_string[11] = (char)(reg->ecx >> 24);
	cpuinfo->vendor_string[12] = 0;
}

void
get_cpu_features(cpu_info_t *cpuinfo, struct i386_regs *regs)
{
	cpuinfo->apic = (regs->ecx & ECX_APIC);
	
}

void
get_tlb_cache_info(cpu_info_t *cpuinfo, struct i386_regs *regs)
{

}

void
RESERVED(cpu_info_t *cpuinfo, struct i386_regs *regs)
{

}

void
get_cache_type(cpu_info_t *cpuinfo, struct i386_regs *regs)
{

}

void
get_monitor_gran(cpu_info_t *cpuinfo, struct i386_regs *regs)
{

}

void
print_vendor_string(const char* vendor_string)
{
	uint32_t old_bg = tty.set_bg, old_fg = tty.set_fg;
	
	tty.set_fg = tty.colors.light_blue;

	tty_puts(vendor_string);

	tty.set_bg = old_bg;
	tty.set_fg = old_fg;
	
}

// check if a specific flag is set
flags_register_t
check_flag(int flag)
{
	
	asm volatile("pushfl");	
	asm volatile("popl %eax");
	asm volatile("andl %0, %%eax"::"d"(flag));
	asm volatile("movl %%eax, %0":"=r"(flag));

	if(flag)
	{
		return set;
	}

	return not_set;
}
