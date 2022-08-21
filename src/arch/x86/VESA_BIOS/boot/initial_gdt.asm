section .boot
gdt_size equ (gdt_end - gdt_start) - 1


; realative offset to gdt_start
global INITIAL_DATA_SEGMENT_32
INITIAL_DATA_SEGMENT_32 equ code - gdt_start

; relative offset to gdt_start
global INITLAL_CODE_SEGMENT_32
INITIAL_CODE_SEGMENT_32 equ code - gdt_start

; the gdtr needs this structure
global initial_gdt_descriptor
initial_gdt_descriptor:
	dw	gdt_size ; limit
	dd	gdt_start ; base

gdt_start:
; each gdt-entry is a QUAD-WORD long (8 bytes)
null:
	dq	0

code:
	dw	0xffff ; limit bit 0 - 15
	dw  0 ; base bit 0 - 15
	db	0 ; base bit 16 - 23
	; access byte for the segment
	db 0x9a
	; flags
	; and limit bit 16 - 20
	db 0xcf
	db 0 ; base bit 24 - 31

data:
	dw	0xffff ; limit bit 0 - 15
	dw	0 ; base bit 0 - 15
	db	0 ; base bit 16 - 23
	; access byte for the segment
	db  0x92
	; flags
	; and limit bit 16 - 20
	db 0xcf 
	db 0 ; base bit 24 - 31

gdt_end:

