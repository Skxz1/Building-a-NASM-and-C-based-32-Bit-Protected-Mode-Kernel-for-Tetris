[bits 16]
switch_to_32bit:
    cli ; Disable interrupts
    lgdt [global_descriptor_table] ; Load the GDT descriptor
    mov eax, cr0
    or eax, 0x1 ; Set 32-bit mode bit in cr0
    mov cr0, eax
    jmp CODE_SEG:init_32bit ; Far jump using a different segment

[bits 32]
init_32bit: ; We are now using 32-bit instructions
    mov ax, DATA_SEG ; Update the segment registers
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000 ; Set the stack right at the top of the free space
    mov esp, ebp

    call init_kernel ; Call a well-known label with useful code
