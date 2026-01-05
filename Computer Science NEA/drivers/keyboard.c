#include "../cpu/isr.h"
#include "../kernel/util.h"

int scancode;

void print_letter(uint8_t scancode) {
    switch (scancode) {

        case 0x39:          // space bar arrow key
            fall();
            break;

        case 0x4b:          // left arrow key
            shiftleft();
            break;
        
        case 0x50:             // down arrow key
            shiftdown();
            break;

        case 0x4d :             //right arrow key
            shiftright();
        break;

        case 0x48:              // up arrow key  
            shiftup();
            shiftdown();
            Rotate();
            draw_tetrimino();
        break;
    }
}

static void keyboard_callback(registers_t *regs) {
    uint8_t scancode = port_byte_in(0x60);
    print_letter(scancode);

}

void init_keyboard() {
    register_interrupt_handler(IRQ1, keyboard_callback);
}

