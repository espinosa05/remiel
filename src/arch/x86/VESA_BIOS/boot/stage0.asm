[bits 16]
; bios_include.asm contains readable BIOS-function names
%include "bios_include.asm"
; externally linked symbols
extern _entry32
extern initial_gdt_descriptor
extern initial_idt_descriptor
extern halt_cpu
extern INITIAL_CODE_SEGMENT

; constants
PE_BIT equ		0x1
EDD_NOT_SUPPORTED equ 0xedd
DISK_ERROR equ 0xde

section .boot

; the linker will put this at address 0x7c00 
global _entry16
_entry16:

	; the BIOS sets DL with the current
	; drive number.
	; it must be saved for later use
  mov [drive_number], dl
  
  ; first we need to check if the BIOS supports EDD
  mov ah, TEST_EDD ; 0x41
  mov bx, 0x55aa
  mov dl, [drive_number]
  int DISK_SERVICE_13h
  jc edd_not_supported
  
  mov ah, READ_DISK_EDD ; 0x42
  mov ds:si, DWORD DAP ; pointer to DAP
  mov dl, [drive_number]
  int DISK_SERVICE_13h
  jc edd_not_supported
  
  mov ah, SET_VGA_MODE
  mov al, VGA_MODE_3
  int VIDEO_SERVICE_10h

  cli ; clear the interrupt flag
  
  ; dereference the descriptor address(located in initial_gdt.asm)
  lgdt [initial_gdt_descriptor]
  ; dereference the descriptor address(located in initial_idt.asm)
  lidt [initial_idt_descriptor]

  ; CR0 can't be set directly
  ; so we modify it through EAX
  mov eax, cr0 ; copy the contents
  or eax, PE_BIT ; set the protected-mode-enable-bit (0x1)
  mov cr0, eax ; update CR0

  ; we update IP(_entry32) with (CS=INITIAL_CODE_SEGMENT)
  jmp DWORD INITIAL_CODE_SEGMENT:_entry32 ; located entry32.asm

edd_not_supported:
  
  mov eax, EDD_NOT_SUPPORTED ; 0xEDD  
  jmp halt_cpu

disk_error:
  mov eax, DISK_ERROR ; 0xDE
  jmp halt_cpu

; data storage
drive_number: db 0

; the DISK ADDRESS PACKET
DAP:
  db 0x10     ; must be set to 0x10
  db 0        ; unused
  dw 0x80     ; 128 sectors()
.buffer:
  dw 0x7e00   ; offset of the buffer where the sectors get loaded
  dw 0        ; segment
  dd 0
  dw 1
