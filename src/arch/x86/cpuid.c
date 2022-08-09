// freestanding libs
#include <stdbool.h>

// custom libs
#include <x86/cpu/cpuid.h>
#include <x86/asm.h>
#include <x86/cpu/cpu.h>
#include <x86/cpu/flags.h>
#include <remiel/types/remiel_types.h>

void
cpuid(struct i386_regs *reg)
{	
	asm volatile("cpuid"
			// save the output to
			// the register struct
			:"=a"
			(reg->eax),
			"=b"
			(reg->ebx),
			"=c"
			(reg->ecx),
			"=d"
			(reg->edx)
			// cpuid takes mostly
			// eax as parameter
			// but in rare cases it takes both
			// eax and ebx
			:"a"
			(reg->eax));
}

bool
is_cpuid_supported()
{

	
}
