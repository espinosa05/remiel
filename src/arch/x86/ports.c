#include <x86/io/ports.h>
#include <stdint.h>


uint8_t
inb(uint16_t port)
{
	uint8_t data;
	asm volatile ("inb %1, %0":"=a"(data): "Nd" (port));
	
	return data;
}



 void outb(uint16_t port, uint8_t data) {

    asm volatile ("outb %0, %1" :: "r" (data),"Nd" (port)) ;

    return;
}

uint16_t
inw(uint16_t port)
{
	uint16_t data;
	asm volatile("inw %1, %0" : "=a"(data): "Nd" (port));
	
	return data;
}


void
outw(uint16_t port, uint16_t data)
{
	asm volatile("outw %0, %1" :: "a"(data), "Nd" (port));
}


uint32_t
inl(uint16_t port)
{
	uint32_t data;
	asm volatile("inl %1, %0" : "=a"(data): "Nd" (port));
	
	return data;
}


void
outl(uint16_t port, uint32_t data)
{
	asm volatile("outl %0, %1" :: "r"(data), "Nd" (port));
}
