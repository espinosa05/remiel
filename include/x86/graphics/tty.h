#ifndef _X86_GRAPHICS_TTY_H
#define _X86_GRAPHICS_TTY_H

#include <stdint.h>
#include <x86/VGA/VGA.h>
#include <x86/VESA/VESA.h>
#include <gfx/colors/colors.h>
#include <remiel/types/remiel_types.h>
// each graphics adapter needs atleast one function
// to print a character with an offset into the framebuffer
// so the other functions can make use of it through
// the tty_controller_t structure


#define TOP_LEFT_CORNER 0

struct color
{
  uint32_t black;
  uint32_t blue;
  uint32_t green;
  uint32_t cyan;
  uint32_t red;
  uint32_t magenta;
  uint32_t brown;
  uint32_t white;
  uint32_t gray;
  uint32_t light_blue;
  uint32_t light_green;
  uint32_t light_cyan;
  uint32_t light_red;
  uint32_t light_magenta;
  uint32_t yellow;
  uint32_t bright_white;
};


typedef struct
{
  uint8_t color_depth;
  int set_fg;
  int set_bg;
  uint16_t cursor_position;
  int rows;
  int cols;
  uint16_t fb_size;
  struct color colors;
	// functions will implicitly use putc
  function_ptr_t putc;
  function_ptr_t cls;	
}
tty_controller_t;


// The kernel will reference the teletype
// structure for tty output
void tty_puts(const char* cstr);

// set the needed members to vesa ones
void set_vesa_device(tty_controller_t *tty);

// set the needed members to vga ones
void set_vga_device(tty_controller_t *tty);


#endif // _X86_GRAPHICS_TTY_H
