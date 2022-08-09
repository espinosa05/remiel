#ifndef _X86_CPU_CPU_H
#define _X86_CPU_CPU_H

#include <stdbool.h>
#include <x86/registers.h>
#include <x86/cpu/flags.h>

#define ECX_APIC	(1 << 21)


typedef struct
{
	char vendor_string[13];
	bool fpu;
	bool vme;
	bool de;
	bool pse;
	bool tsc;
	bool msr;
	bool pae;
	bool mce;
	bool cx8;
	bool apic;
	bool sep;
	bool pge;
	bool mca;
	bool cmov;
	bool pat;
	bool pse_36;
	bool psn;
	bool cflsh;
	bool ds;
	bool acpi;
	bool mmx;
	bool fxsr;
	bool sse;
	bool sse2;
	bool sse3;
	bool ss;
	bool htt;
	bool tm;
	bool pbe;
}
cpu_info_t;

typedef void (*cpuid_output_converter_t) (cpu_info_t *, struct i386_regs *);

// CPUID functions to extract information from the
// register output 

// CPUID.EAX = 0
void get_vendor_string(cpu_info_t *cpuinfo, struct i386_regs *regs);
// CPUID.EAX = 1
void get_cpu_features(cpu_info_t *cpuinfo, struct i386_regs *regs);
// CPUID.EAX = 2
void get_tlb_cache_info(cpu_info_t *cpuinfo, struct i386_regs *regs);
// CPUID.EAX = 3
void RESERVED(cpu_info_t *cpuinfo, struct i386_regs *regs);
// CPUID.EAX = 4
void get_cache_type(cpu_info_t *cpuinfo, struct i386_regs *regs);
// CPUID.EAX = 5
void get_monitor_gran(cpu_info_t *cpuinfo, struct i386_regs *regs);


void set_cpuid_functions(cpuid_output_converter_t *get_cpuid_data);

void print_vendor_string(const char *vendor_string);

void print_cpu_features(cpu_info_t *cpuinfo);

flags_register_t check_flag(int flag);

#define HLT() asm volatile("hlt")
// flags register macros
#define STI() asm volatile("sti")
#define CLI() asm volatile("cli")
#define STD() asm volatile("std")
#define CLD() asm volatile("cld")

#endif // _X86_CPU_CPU_H
