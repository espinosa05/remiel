#ifndef _X86_INTERRUPTS_CONTROLLER_8259_H
#define _X86_INTERRUPTS_CONTROLLER_8259_H

#define MASTER_PIC_COMMAND	0x20
#define MASTER_PIC_DATA		0x21
#define SLAVE_PIC_COMMAND	0xa0
#define SLAVE_PIC_DATA		0xa1

#define PIC_EOI			0x20
#define DISABLE_8259	0xff

// initialization command words
#define ICW_1	
#define ICW_2	
#define ICW_3	
#define ICW_4	

// operating command words
#define OCW_1	
#define OCW_2	
#define OCW_3	

#endif // _X86_INTERRUPTS_CONTROLLER_8259_H
