[org 0x7c00]

; Move the boot drive to boot
mov [boot], dl

; Set up the stack pointer
mov bp, 0x9000
mov sp, bp

; Load the kernel from disk
call load_kernel
push ax

; Set the video mode
mov ah, 0x00
mov al, 0x13
int 0x10
pop ax

; Switch to 32-bit protected mode
call switch_to_32bit
jmp $ ; Never executed

%include "boot/gdt.asm"
%include "boot/switch-to-32bit.asm"

[bits 16]
load_kernel:
    ; Load the kernel from disk
    mov bx, kernel_offset
    mov dh, 31
    mov dl, [boot]
    call disk_load
    ret

[bits 32]
init_kernel:
    ; Call the kernel
    call kernel_offset

    ; Stay here when the kernel returns control to us (if ever)
    jmp $



; Set the kernel offset
kernel_offset equ 0x1000

; Store the boot drive in memory
boot db 0

; Load 'num_sectors' sectors from drive 'drive_num' into the buffer pointed by 'buffer_ptr'
disk_load:
    pusha

    ; Save the value of 'num_sectors' that we will overwrite with the read command
    push dx

    ; Set the values of the registers required by the BIOS read function
    mov ah, 0x02   ; Read sectors function
    mov al, dh
    mov cl, 0x02   ; First available sector
    mov ch, 0x00   ; Cylinder
    mov dh, 0x00   ; Head number
    

    ; Perform the read operation, storing the data in the buffer pointed by 'buffer_ptr'
    int 0x13       ; BIOS interrupt
    jc disk_error  ; Jump if carry flag is set (i.e., an error occurred)

    ; Check if the expected number of sectors was read
    pop dx
    cmp al, dh
    jne sectors_error

    popa
    ret

disk_error:
    ; Print error message and code
    mov bx, DISK_ERROR_MSG
    call print16
    mov dh, ah
    call print16_hex
    jmp disk_loop

sectors_error:
    ; Print error message
    mov bx, SECTORS_ERROR_MSG
    call print16

disk_loop:
    jmp $

DISK_ERROR_MSG: db "Disk read error", 0
SECTORS_ERROR_MSG: db "Incorrect number of sectors read", 0


; This subroutine prints a null-terminated string in 16-bit real mode
print16:
    pusha
    ; Print each character until a null byte is found

print16_hex:
    pusha
    mov cx, 0 ; Initialize index variable to 0


; Define the output string buffer for print16_hex
PRINT16_HEX_OUT:
    db '0x0000',0 ; reserve memory for our new string




; padding
times 510 - ($-$$) db 0
dw 0xaa55
