#include <x86/cpu/flags.h>

asm (".globl get_flags_register_value"
    "get_flags_register_value:"
    "pushl %ebp"
    "mov %esp, %ebp"
    "pushfd"
    "popl %eax"
    "popfd"
    "popl %ebp"
    "ret");

asm (".globl set_flags_register_value"
    "set_flags_register_value:"
    "call get_flags_register_value"
    "pushl %ebp"
    "mov %esp, %ebp"
    "mov -4(%rbp), %eax"
    "pushl %eax"
    "popfd"
    "popl %eax"
    "popl %ebp"
    "ret");
