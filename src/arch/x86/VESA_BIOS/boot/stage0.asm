[bits 16]
; bios_include.asm contains readable BIOS-function names
%include "bios_include.asm"
extern _entry32

PE_BIT equ		0x1

section .boot.text

; the linker will put this at address 0x7c00
global _entry16
_entry16:


	mov ah,	READ_DISK ; 0x2
	; read 32 sectors of disk (32 * 512 = 16384 bytes -> 16kb)
	mov al,	0x80
	mov bx, 0x7e00
	mov ch, 0 ; cylinder 0
	mov cl, 2 ; starting from sector 2	
	mov dh, 0 ; select head 0
	; dl is set with the drive number by the BIOS
	; so we don't tamper with it
	int DISK_SERVICE_13h
	; when the carry flag is set
	; the service routine encountered an error
	jc disk_error ; jump if the carry bit is set
	; get the resolution from user input

	cli ; clear the interrupt flag
	; load the address of the gdt descriptor (located in gdt.asm)
	lgdt [gdt_descriptor]


	; cr0 can't be set directly
	; so we modify it through eax
	mov eax, cr0 ; copy the contents
	or eax, 1 ; set the protected-mode-enable-bit (0x1)
	mov cr0, eax ; update cr0
	
	; we update IP with CS=CODE_SEGMENT_32
	jmp CODE_SEGMENT_32:_entry32 ; located entry32.asm

disk_error:
	mov eax, 0xDE ; when the disk interrupt fails we throw this error
	hlt			 
	jmp disk_error

%include "gdt.asm" ; global descriptor table

