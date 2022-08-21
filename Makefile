#=============================================================================#
#		File:				Makefile																											#
#		Author:			Francisco Fischer																							#
#		Copyright:	(c) 2022 Campus Berufsbildung																	# 
#=============================================================================#

# type make to see a detailed description on how this build system is used

# later we might port it to different platforms
# so we should layout this config

# ARCH=`cat arch.conf`
# ARCH_DIR=`cat arch_dir.conf`

# temporary directory for build process
TMP_DIR=.tmp/

# the build directory
BUILD_DIR=build/

# NASM doesn't like relative paths
NASM_INCLUDE_DIR=src/arch/x86/VESA_BIOS/boot
VESA_BIOS_LINK_DIR=src/arch/x86/VESA_BIOS/linker_scripts/

# GNU binutils
_CC=gcc
_LD=ld

# for 16 bit code
# WATCOM_CC=/opt/watcom/binl/wcc
# WATCOM_FLAGS=-3 -ecc 

# 32-bit pentium-II optimized C compiler
CCi686=/home/espi/i686-elf-tools-linux/bin/i686-elf-$(_CC)

# 32-bit pentium-II linker
LDi686=/home/espi/i686-elf-tools-linux/bin/i686-elf-$(_LD)

# initial kernel flags
KERNEL_FLAGS=-Wall -ffreestanding -fno-builtin -mgeneral-regs-only\
			-nostdlib  -I./include  

# emulator
QEMU=qemu-system-i386
QEMU_FLAGS=-cpu `cat .conf/cpu`  -monitor stdio -m 1024  -no-shutdown\
			 

OBJ=$(TMP_DIR)stage0.o\
	$(TMP_DIR)stage1.o\
	$(TMP_DIR)kernel_setup.o\
	$(TMP_DIR)ports.o\
	$(TMP_DIR)interrupts.o\
	$(TMP_DIR)key_board.o\
	$(TMP_DIR)input_buffer.o\
	$(TMP_DIR)gdt.o\
	$(TMP_DIR)cpu.o\
	$(TMP_DIR)cpuid.o\
	$(TMP_DIR)string.o\
	$(TMP_DIR)tty.o\
	$(TMP_DIR)VGA.o\
	$(TMP_DIR)init.o\
	$(TMP_DIR)farpointer.o\
	$(TMP_DIR)initial_gdt.o\
	$(TMP_DIR)initial_idt.o

help:
	cat .conf/usage.txt

deps:
	cat .conf/deps.txt

clean:
	rm -rf $(TMP_DIR)
	
all: $(TMP_DIR) $(BUILD_DIR) $(BUILD_DIR)kernel.img
	
install-deps:


$(BUILD_DIR)kernel.img: $(TMP_DIR)boot.bin
	dd if=/dev/zero of=$@ bs=512 count=1024000
	dd if=$^ of=$@ conv=notrunc bs=512 count=1024000

# Dependency build
$(TMP_DIR):
	mkdir $@

$(BUILD_DIR):
	mkdir $@

$(TMP_DIR)boot.bin: $(OBJ)
	$(LDi686) -T$(VESA_BIOS_LINK_DIR)kernel_link.ld  $^ -e _entry16 -o $@

$(TMP_DIR)stage0.o: src/arch/x86/VESA_BIOS/boot/stage0.asm
	nasm -f elf -I$(NASM_INCLUDE_DIR) $^	-o $@

$(TMP_DIR)initial_idt.o: src/arch/x86/VESA_BIOS/boot/initial_idt.asm
	nasm -f elf -I$(NASM_INCLUDE_DIR) $^ -o $@

$(TMP_DIR)initial_gdt.o: src/arch/x86/VESA_BIOS/boot/initial_gdt.asm
	nasm -f elf -I$(NASM_INCLUDE_DIR) $^ -o $@

$(TMP_DIR)vesa_info_block.asm: src/arch/x86/VESA_BIOS/boot/vesa_info_block.asm
	nasm -f elf -I$(NASM_INCLUDE_DIR) $^ -o $@

$(TMP_DIR)stage1.o: src/arch/x86/VESA_BIOS/boot/stage1.asm
	nasm -f elf -I$(NASM_INCLUDE_DIR) $^ -o $@

$(TMP_DIR)kernel_setup.o: src/arch/x86/VESA_BIOS/kernel_setup.c
	$(CCi686) $(KERNEL_FLAGS) -O2 $^ -c -o $@ 

$(TMP_DIR)string.o: lib/string.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

$(TMP_DIR)cpu.o: src/arch/x86/cpu.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

$(TMP_DIR)cpuid.o: src/arch/x86/cpuid.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

$(TMP_DIR)interrupts.o: src/arch/x86/interrupts.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

$(TMP_DIR)gdt.o: src/arch/x86/gdt.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

$(TMP_DIR)init.o: src/arch/x86/init.c
	$(CCi686) $(KERNEL_FLAGS)  $^ -c -o $@ 

$(TMP_DIR)VGA.o: src/arch/x86/VGA/VGA.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

$(TMP_DIR)ports.o: src/arch/x86/ports.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

$(TMP_DIR)apic.o: src/arch/x86/apic.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

$(TMP_DIR)8259.o: src/arch/x86/8259.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

$(TMP_DIR)flags.o: src/arch/x86/flags.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

$(TMP_DIR)key_board.o: src/arch/x86/drivers/key_board.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

$(TMP_DIR)input_buffer.o: src/arch/x86/input_buffer.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

$(TMP_DIR)farpointer.o: src/arch/x86/farpointer.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

$(TMP_DIR)tty.o: src/arch/x86/tty.c
	$(CCi686) $(KERNEL_FLAGS) $^ -c -o $@

# emulate the cpu 
run: $(BUILD_DIR)kernel.img
	$(QEMU) $(QEMU_FLAGS) -drive file=$^ 

