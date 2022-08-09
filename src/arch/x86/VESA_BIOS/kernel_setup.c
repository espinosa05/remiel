// freestanding libraries
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
// custom libraries
#include <x86/farpointer.h>
#include <x86/graphics/tty.h>
#include <x86/VGA/VGA.h>
#include <x86/VESA/VESA.h>
#include <remiel/sections/sections.h>
#include <remiel/init.h>
#include <remiel/kernel_status.h>
#include <x86/io/ports.h>
#include <x86/cpu/cpu.h>
// console controller
tty_controller_t tty;


_init void
kernel_setup(far_ptr_t vesa_info_block_far)
{
	
	struct vesa_info_block *vesa_info; 
	cpu_info_t cpu_info;
	KERNEL_STATUS kernel_exit;

	// console driver setup
	if (translate_far_ptr(vesa_info_block_far) == 0) // vga device
	{
		vesa_info = NULL;
		set_vga_device(&tty);	
	}	
	else
	{
		vesa_info =
			(struct vesa_info_block*)translate_far_ptr(vesa_info_block_far);
		set_vesa_device(&tty);
	}

	// clear the screen and set it to blue with white text
	kernel_init();
	while(1) // we shouldn't reach this
	{
		asm volatile("hlt");
	}
}

