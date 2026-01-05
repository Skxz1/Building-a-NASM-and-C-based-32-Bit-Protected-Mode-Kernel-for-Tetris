#include "idt.h"
#include "../kernel/util.h"

// Declare IDT (Interrupt Descriptor Table) gate and register arrays
idt_gate_t my_idt[idt_entry];
idt_register_t my_idt_reg;

// Function to set an IDT gate
void set_idt_gate(int n, uint32_t handler) {
    my_idt[n].low_offset = low_16(handler);
    my_idt[n].sel = KERNEL_CS;
    my_idt[n].always0 = 0;
    my_idt[n].flags = 0x8E;
    my_idt[n].high_offset = high_16(handler);
}

// Function to load the IDT
void load_idt() {
    my_idt_reg.base = (uint32_t) &my_idt;
    my_idt_reg.limit = idt_entry * sizeof(idt_gate_t) - 1;
    /* The IDT is loaded by executing the "lidt" instruction with the address of the IDT register */
    asm volatile("lidt (%0)" : : "r" (&my_idt_reg));
}
