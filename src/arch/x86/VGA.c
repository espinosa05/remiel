#include <x86/VGA/VGA.h>
#include <x86/graphics/tty.h>
extern tty_controller_t tty;

void
vga_tty_putc(char c, uint16_t off)
{
		uint8_t *VGA_TXT = (uint8_t *)_25_80_TEXT_BUFFER;

		VGA_TXT += off * 2;
		*VGA_TXT = c;
		VGA_TXT++;
		*VGA_TXT = TTY_SET_COLOR( tty.set_fg , tty.set_bg );
}


void 
vga_tty_cls()
{
	
	for(int i = 0; i <= tty.fb_size; i++)
	{
		tty.putc('\0', i);
	}

}

