#ifndef _VESA_VESA_H
#define _VESA_VESA_H

#include <stdint.h>

#define NO_VESA_DEVICE 0

__attribute__((packed)) struct vesa_info_block
{
	uint16_t		attributes;
	uint8_t			window_a;
	uint8_t			window_b;
	uint16_t		granularity;
	uint16_t		window_size;
	uint16_t		segment_a;
	uint16_t		segment_b;
	uint32_t		win_func_ptr;
	uint16_t		pitch;
	uint16_t		width;
	uint16_t		height;
	uint8_t			w_byte;
	uint8_t			y_byte;
	uint8_t			planes;
	uint8_t			bits_per_pixel;
	uint8_t			banks;
	uint8_t			memory_model;
	uint8_t			bank_size;
	uint8_t			image_pages;
	uint8_t			reserved_0;
	uint8_t			red_mask;
	uint8_t			red_pos;
	uint8_t			green_mask;
	uint8_t			green_pos;
	uint8_t			blue_mask;
	uint8_t			blue_pos;
	uint8_t			reserved_mask;
	uint8_t			reserved_pos;
	uint8_t			direct_color_attributes;
	uint32_t		frame_buffer;
	uint32_t		offscreen_mem_off;
	uint32_t		offscreen_mem_size;
	uint8_t			reserved_1[205];
};

typedef void * vesa_color_t;	// we don't assume color depth



#endif // VESA_VESA_H
