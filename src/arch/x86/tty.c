#include <x86/graphics/tty.h>
#include <remiel/types/remiel_types.h>
#include <x86/VGA/VGA.h>
#include <x86/VESA/VESA.h>
#include <fmt/fmt.h>
#include <remiel/init.h>
#include <stdarg.h>
#include <stdint.h>

extern tty_controller_t tty;


void
tty_puts(const char* fmt)
{
	static uint16_t offset = 0;
	uint16_t newline = 0;

	do
	{
		if(*fmt == '\n')
		{
			newline++;
			offset = newline * 80;
		}
		else if(*fmt == '\t')
		{
			while((offset % TABSIZE) > 0)
			{
				offset++;
			}
			offset++;
		}
		else
		{
			tty.putc(*fmt, offset); // if no format was given, we simply
			offset++;
			
		}
		fmt++;
	}
	while (*fmt != 0);
	
}


void
set_vesa_device(tty_controller_t *tty)
{
	// TODO: write the functions and give the addresses
	
	/*
	fmt_tty = tty_addr;
	
	(*fmt_tty) = {
			.color_depth = bpp;
			.cls = vesa_cls;
			._putc = vesa_putc;
	};*/

}


void
set_vga_device(tty_controller_t *tty)
{
		// for now, we only accept int 0x10 ah 0, al 2
		// as a mode (25x80 tty mode) so we lock it at
		// 4 bits
		tty->color_depth 			= 4;
		tty->putc 					= vga_tty_putc;
		tty->cls					= vga_tty_cls;
		tty->rows					= 25;
		tty->cols					= 80;
		tty->fb_size 				= tty->cols * tty->cols;

		tty->colors.black			= vga_black;
		tty->colors.blue			= vga_blue;
		tty->colors.green			= vga_green;
		tty->colors.cyan 			= vga_cyan;
		tty->colors.red 			= vga_red;
		tty->colors.magenta 		= vga_magenta;
		tty->colors.brown 			= vga_brown;
		tty->colors.white 			= vga_white;
		tty->colors.gray 			= vga_gray;
		tty->colors.light_blue 		= vga_light_blue;
		tty->colors.light_green 	= vga_light_green;
		tty->colors.light_cyan 		= vga_light_cyan;
		tty->colors.light_red 		= vga_light_red;
		tty->colors.light_magenta 	= vga_light_magenta;
		tty->colors.yellow 			= vga_yellow;
		tty->colors.bright_white 	= vga_bright_white;
}
