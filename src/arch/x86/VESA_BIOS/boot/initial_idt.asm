; we kinda want the CPU to shut up so we supply an empty interrupt descriptor table
section .boot
global initial_idt_descriptor
idt_descriptor:
  dw (idt_end - initial_idt) - 1
  dd initial_idt

; zero the entire idt
initial_idt:
  times 256 dw 0
idt_end:

  
