#ifndef _X86_CPU_CPUID_H
#define _X86_CPU_CPUID_H

#include <stdint.h>
#include <x86/registers.h>
#include <stdbool.h>

#define CPUID_FUNCTION_0	0
#define CPUID_FUNCTION_1	1
#define CPUID_FUNCTION_2	2
#define CPUID_FUNCTION_3	3
#define CPUID_FUNCTION_4	4
#define CPUID_FUNCTION_5	5

#define CPUID_EXTENDED_FUNCTION_80000000H	0x80000000
#define	CPUID_EXTENDED_FUNCTION_80000001H	0x80000001
#define	CPUID_EXTENDED_FUNCTION_80000002H	0x80000002
#define	CPUID_EXTENDED_FUNCTION_80000003H	0x80000003
#define	CPUID_EXTENDED_FUNCTION_80000004H	0x80000004
#define	CPUID_EXTENDED_FUNCTION_80000005H	0x80000005
#define	CPUID_EXTENDED_FUNCTION_80000006H	0x80000006
#define	CPUID_EXTENDED_FUNCTION_80000007H	0x80000007
#define	CPUID_EXTENDED_FUNCTION_80000008H	0x80000008


void cpuid(struct i386_regs *reg);

bool is_cpuid_supported();

#endif // _X86_CPU_CPUID_H