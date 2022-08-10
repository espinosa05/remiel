section .init
extern kernel_setup

global _entry32
_entry32:
	; we can't set the segment registers directly
	; so we do it through ax
	mov ax, 0x10
	mov ds, ax
	mov ss, ax
	mov es, ax
	xor ax, ax
	; we will use this later for access to the TIB
	; (Thread Information Block)
	mov fs, ax
	; this always stays zero
	mov gs, ax

	mov es:di, eax
	; es:di holds the address of the vbe structure
	;mov es:di, DWORD vesa_info_block_structure
	mov esp, _stack_top
	push DWORD es:di
	call kernel_setup
	
hlt:
hlt
jmp hlt
;
; set the initial stack
section .bss
_stack_bottom:
	resb (1024 * 2) ; reserve 16 KB for the stack pointer
_stack_top:
section .init

%include "vga_struct.asm"
%include "vbe_struct.asm"
