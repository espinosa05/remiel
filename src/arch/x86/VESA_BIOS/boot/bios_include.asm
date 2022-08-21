; yeah, i don't want to forget, what the bootloader does
; after a few weeks so  i made this for readablility

; the BIOS loads us at 0000:7c00
ORIGIN equ	0x7c00

; a floppy disk sector is 512 bytes long
SECTOR_SIZE equ 512

; BIOS routines
DISK_SERVICE_13h equ	0x13
VIDEO_SERVICE_10h equ	0x10

; function names for AH
READ_DISK equ 2
SET_VGA_MODE equ 0
TEST_EDD equ  0x41
READ_DISK_EDD equ 0x42

VGA_MODE_3 equ 3

; VESA function prefix

; VESA function names
GET_VESA_CONTROLLER_INFO equ 0
GET_VESA_MODE_INFO equ 1

