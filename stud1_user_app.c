//------------------------------------------------------------------------------
//
// stud1_user_app.c
//
// STUD-1 User Application
//
//------------------------------------------------------------------------------

#include "stud1_capi.h"

int c = 0x41;
char s[1];

void show_char(void) {
    int h;
    
    LCD_SET_CURSOR(2,1);
    prints("0x");
    LCD_SET_CURSOR(2,3);
    h = (c & 0xF0) >> 4;
    print_hex(h);
    LCD_SET_CURSOR(2,4);
    h = c & 0x0F;
    print_hex(h);
    LCD_SET_CURSOR(2,5);
    prints(" = ");
    LCD_SET_CURSOR(2,8);
    s[0] = c;
    prints(s);
}

//------------------------------------------------------------------------------
// user_app_initialize(void)
//
// This function is called from stud1_main.asm when the STUD-1 board has been
// initialized and is ready for processing.
//------------------------------------------------------------------------------
void user_app_initialize(void) {
    
    LCD_SET_CURSOR(1,1);
    prints("Rotate left knob");
    show_char();
    
}


//------------------------------------------------------------------------------
// user_app_process_sample(void)
//
// This function is called from stud1_proc.asm each time an ADC interrupt
// occurs. The function needs to be fast enough to process and return before
// next interrupt occurs. The function is intended for processing the input
// samples from the ADC and send the processed output to the DAC.
//------------------------------------------------------------------------------
void user_app_process_sample(void) {
    
    // Just pass input signals through.
    proc_left_out  = proc_left_in;
    proc_right_out = proc_right_in;

}

//------------------------------------------------------------------------------
// user_app_handle_push1(void)
//
// This function is called from stud1_main.asm when rotary encoder 1 has been
// pushed.
//------------------------------------------------------------------------------
void user_app_handle_push1(void) {
    //
}

//------------------------------------------------------------------------------
// user_app_handle_cw1(void)
//
// This function is called from stud1_main.asm when rotary encoder 1 has been
// turned clockwise.
//------------------------------------------------------------------------------
void user_app_handle_cw1(void) {
    c = ++c & 0xFF;
    show_char();    
}

//------------------------------------------------------------------------------
// user_app_handle_ccw1(void)
//
// This function is called from stud1_main.asm when rotary encoder 1 has been
// turned counter-clockwise.
//------------------------------------------------------------------------------
void user_app_handle_ccw1(void) {
    c = --c & 0xFF;
    show_char();
}

//------------------------------------------------------------------------------
// user_app_handle_cw2(void)
//
// This function is called from stud1_main.asm when rotary encoder 2 has been
// turned clockwise.
//------------------------------------------------------------------------------
void user_app_handle_cw2(void) {
    //
}

//------------------------------------------------------------------------------
// user_app_handle_ccw2(void)
//
// This function is called from stud1_main.asm when rotary encoder 2 has been
// turned counter-clockwise.
//------------------------------------------------------------------------------
void user_app_handle_ccw2(void) {
    //
}


