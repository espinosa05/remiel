#ifndef _X86_CPU_FLAGS_H
#define _X86_CPU_FLAGS_H

#include <x86/cpu/cpu.h>
#include <stdint.h>

#define FLAGS_CF 1
#define FLAGS_PF (1 << 2)
#define FLAGS_AF (1 << 4)
#define FLAGS_ZF (1 << 6)
#define FLAGS_SF (1 << 7)
#define FLAGS_TF (1 << 8)
#define FLAGS_IF (1 << 9)
#define FLAGS_DF (1 << 10)
#define FLAGS_OF (1 << 11)
#define FLAGS_IOPL (1 << 12)
#define FLAGS_NT (1 << 14)

#define EFLAGS_RF (1 << 16)
#define EFLAGS_VM (1 << 17)
#define EFLAGS_AC (1 << 18)
#define EFLAGS_VIF (1 << 19)
#define EFlAGS_VIP (1 << 20)
#define EFLAGS_ID (1 << 21)

// i don't know if this actually works but let's just pretend it does

#define SAVE_FLAGS() PUSHFD()
#define RESTORE_FLAGS() POPFD()

uint32_t get_flags_register_value();
#endif // _X86_CPU_FLAGS_H
