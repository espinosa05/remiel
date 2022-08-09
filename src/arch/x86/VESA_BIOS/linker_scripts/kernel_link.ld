OUTPUT_FORMAT("binary")

SECTIONS
{	
	. = 0x7c00;
	
	.boot : { *(.boot.text) }
	
	. = 0x7dfe;	/* 510th byte offset */

	.mbr : {

		SHORT(0xaa55); /* BOOT SIGNATURE */
	
	}
	.init : { *(.init) }
	
	/* Page aligned sections */
	.text : ALIGN(0x1000) { *(.text) }
	
	.rodata : ALIGN(0x1000) { *(.rodata) }
	
	.data : ALIGN(0x1000) { *(.data) }
	
	.bss : ALIGN(0x1000) { *(.bss) }	

}
