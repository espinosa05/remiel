; VBE-info Structure
; when getting a mode from the VESA-bios we supply a pointer (ES:CX) to this structure
; later we use the stack to push the address onto it so the C function can get it 
; from there


vesa_info_block_structure:
	.attributes:				dw 0
	.window_a:					db 0
	.window_b:					db 0
	.granularity:				dw 0
	.window_size:				dw 0
	.segment_a:					dw 0
	.segment_b:					dw 0
	.win_func_ptr:				dd 0
	.pitch:						dw 0
	.width:						dw 0
	.height:					dw 0
	.w_byte:					db 0
	.y_byte:					db 0
	.planes:					db 0
	.bit_per_pixel:				db 0
	.banks:						db 0
	.memory_model:				db 0
	.bank_size:					db 0
	.image_pages:				db 0
	.reserved:					db 0
	.red_mask:					db 0
	.red_pos:					db 0
	.green_mask:				db 0
	.green_pos:					db 0
	.blue_mask:					db 0
	.blue_pos:					db 0
	.reserved_mask:				db 0
	.reserved_pos:				db 0
	.direct_color_attributes:	db 0
	.frame_buffer:				dd 0
	.offscreen_mem_off:			dd 0
	.offscreen_mem_size:		dw 0
	times (206) 				db 0
vbe_struct_end:

