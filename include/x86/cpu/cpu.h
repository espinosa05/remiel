#ifndef _X86_CPU_CPU_H
#define _X86_CPU_CPU_H

#include <stdbool.h>
#include <x86/registers.h>
#include <x86/cpu/flags.h>

#define ECX_APIC	(1 << 21)


typedef struct
{
	char vendor_string[13];
  bool has_fpu;
	bool has_vme;
	bool has_de;
	bool has_pse;
	bool has_tsc;
	bool has_msr;
	bool has_pae;
	bool has_mce;
	bool has_cx8;
	bool has_apic;
	bool has_sep;
	bool has_pge;
	bool has_mca;
	bool has_cmov;
	bool has_pat;
	bool has_pse_36;
	bool has_psn;
	bool has_cflsh;
	bool has_ds;
	bool has_acpi;
	bool has_mmx;
	bool has_fxsr;
	bool has_sse;
	bool has_sse2;
	bool has_sse3;
	bool has_ss;
	bool has_htt;
	bool has_tm;
	bool has_pbe;
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

bool is_flag_set(int flag);

#define HLT() asm volatile("hlt")
// flags register macros
#define STI() asm volatile("sti")
#define CLI() asm volatile("cli")
#define STD() asm volatile("std")
#define CLD() asm volatile("cld")
#define PUSHFD() asm volatile("pushfd")
#define POPFD() asm volatile("popfd")

#endif // _X86_CPU_CPU_H
