section .init
; externally linked symbols
extern kernel_setup
extern INITIAL_DATA_SEGMENT

global _entry32
_entry32:
	; we can't set the segment registers directly
	; so we do it through ax
	mov ax, INITIAL_DATA_SEGMENT ; relative offset inside th
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
	; mov es:di, DWORD vesa_info_block_structure
	mov esp, _stack_top
	push DWORD es:di
	call kernel_setup

global halt_cpu
halt_cpu:
  cli ; if the flag is not set we disable it
  hlt
  jmp halt_cpu ; just for safety measures

; set the initial stack
section .bss
_stack_bottom:
	resb (1024 * 4) ; reserve 4 KB for the stack pointer
_stack_top:


