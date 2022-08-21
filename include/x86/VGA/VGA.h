#ifndef _X86_VGA_VGA_H
#define _X86_VGA_VGA_H

#include <stdint.h>

#define VGA_TEXT_BUFFER 0xb8000
#define VGA_GFX_BUFFER	0xa0000

#define DISABLE_CURSOR()

#define TTY_SET_COLOR(FG, BG)\
	(FG | BG << 4)

#define TOP_LEFT_CORNER 0

void vga_tty_putc(char c, uint16_t off);

void vga_tty_cls();

enum vga_colors
{
	vga_black,
	vga_blue,
	vga_green,
	vga_cyan,
	vga_red,
	vga_magenta,
	vga_brown,
	vga_white,
	vga_gray,
	vga_light_blue,
	vga_light_green,
	vga_light_cyan,
	vga_light_red,
	vga_light_magenta,
	vga_yellow,
	vga_bright_white
};

#endif // _X86_VGA_VGA_H
