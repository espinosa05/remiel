// freestanding libs
#include <stdint.h>

// remiel libs
#include <x86/graphics/tty.h>
#include <x86/VGA/VGA.h>
#include <x86/VESA/VESA.h>
#include <gfx/modes/video_modes.h>
#include <remiel/types/remiel_types.h>
#include <fmt/fmt.h>

extern tty_controller_t tty;


void tty_puts(const char* cstr) {

	static uint16_t newline = 1;
	static uint16_t offset = 0;

	while(*cstr) {
		if(*fmt == '\n') {
			newline++;
			tty.cursor_position = newline * tty.cols;
		}
		else if(*cstr == '\t') {
			while((offset % TABSIZE) > 0) {
				offset++;
		}
    else if(*cstr == '\\') {
		  tty.putc('\'); 
      offset++;
    }
		else {
			tty.putc(*cstr, tty.cursor_position);
			offset++;
		}
	  cstr++;
	}

}


void set_vesa_device(tty_controller_t *tty, graphics_mode_t *vesa_mode) {
	// TODO: write the functions and give the addresses

	/*
	fmt_tty = tty_addr;

	(*fmt_tty) = {
			.color_depth = bpp;
			.cls = vesa_cls;
			._putc = vesa_putc;
	};*/

}

void set_vga_device(tty_controller_t *tty, graphics_mode_t *graphics_mode) {
	 
		tty->color_depth			= vga_mode->color_depth;
		tty->cursor_position  = TOP_LEFT_CORNER;
		tty->putc             = vga_tty_putc;
		tty->cls              = vga_tty_cls;
		tty->rows             = graphics_mode->vga.rows;
		tty->cols             = graphics_mode->vga.cols;
		tty->fb_size          = graphics_mode->vga.buff_size;

		tty->colors.black     = vga_black;
		tty->colors.blue      = vga_blue;
		tty->colors.green     = vga_green;
		tty->colors.cyan      = vga_cyan;
		tty->colors.red       = vga_red;
		tty->colors.magenta   = vga_magenta;
		tty->colors.brown			= vga_brown;
		tty->colors.white			= vga_white;
		tty->colors.gray			= vga_gray;
		tty->colors.light_blue    = vga_light_blue;
		tty->colors.light_green   = vga_light_green;
		tty->colors.light_cyan    = vga_light_cyan;
		tty->colors.light_red	    = vga_light_red;
		tty->colors.light_magenta	= vga_light_magenta;
		tty->colors.yellow			  = vga_yellow;
		tty->colors.bright_white	= vga_bright_white;

}
