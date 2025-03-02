// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

#ifdef SWAP_HANDS_ENABLE

__attribute__ ((weak))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] =
    // The LAYOUT macro could work for this, but it was harder to figure out the
    // identity using it.

    // This is the identity layout.
/*
{
    { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} },
    { {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1} },
    { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2} },
    { {0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3} },
    { {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4} },

    { {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} },
    { {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6} },
    { {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7} },
    { {0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8} },
    { {0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9} },
};
*/

    // This is the mirror, q <-> p, w <-> o, etc...
{
 { {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} },
 { {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6} },
 { {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7} },
 { {0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8} },
 { {0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9} },

 { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} },
 { {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1} },
 { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2} },
 { {0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3} },
 { {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4} },
};

#    ifdef ENCODER_MAP_ENABLE
const uint8_t PROGMEM encoder_hand_swap_config[NUM_ENCODERS] = {1, 0};
#    endif

#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_270;
}

static void render_logo(void) {

//static const  char PROGMEM sinus[] = {
//        0,  0,192, 48,  8,  4,  2,  3,  3,  2,  4,  8, 48,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 12, 48,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 48,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 12, 16, 32, 64,192,192, 64, 32, 16, 12,  3,  0,  0,
//    };

    static const char PROGMEM raw_logo3[] = {        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,128,224, 60,  7, 30,240,  0,  0,  0,  0,  0,  0,  0,  0,128, 64,128,  0,  0,  0,  1,  2,  4,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  1, 31,112,224, 56, 14,  3,  1,  1,  2,  4,  2,  1,  0,  0,  0,  0,128,192,192,128,192,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24, 60,124,248,124, 60, 24,  0,  0,  0,  0,  0,
    };

    static const char PROGMEM raw_logo2[] = {        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64,128,  0,  0,  0,  0,  0,  0,128,224, 60,  7, 30,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64,128,  0,  0,  0,  1,  2,  4,  2,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  1, 31,112,224, 56, 14,  3,  1,  1,  1,  1,  2,  4,  2,  1,  0,  0,  0,  0,128,192,192,128,192,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24, 36, 68,136, 68, 36, 24,  0,  0,  0,  0,  0,

    };

    static const char PROGMEM raw_logo0[] = {        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64,128,  0,  0,128,224, 60,  7, 30,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64,128,  0,  0,  0,  1,  2,  4,  2,  1,  1,  1,  0,  0,  0,  0,  1, 31,112,224, 56, 14,  3,  1,  1,  1,  1,  1,  1,  1,  1,  2,  4,  2,  1,  0,  0,  0,  0,128,192,192,128,192,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24, 36, 68,136, 68, 36, 24,  0,  0,  0,  0,  0,

    };
    static const char PROGMEM raw_logo1[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x40,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x80,
    0xE0, 0x3C, 0x07, 0x1E, 0xF0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x40, 0x80, 0x00, 0x00, 0x00, 0x01,
    0x02, 0x04, 0x02, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x1F, 0x70, 0xE0, 0x38, 0x0E,
    0x03, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x02, 0x04, 0x02, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0,
    0x80, 0xC0, 0xC0, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x18, 0x24, 0x44, 0x88,
    0x44, 0x24, 0x18, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x03, 0x07, 0x0F, 0x07, 0x03, 0x01,
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
    0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFF, 0xFF, 0x60, 0x60,
    0x60, 0x60, 0x60, 0x60, 0x3F, 0x1F,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x9F, 0x9F,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0F, 0x1F, 0x30, 0x30,
    0x30, 0x30, 0x30, 0x30, 0x1F, 0x0F,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x7F, 0x7F, 0x60, 0x60, 0x60, 0x60,
    0x60, 0x60, 0x60, 0x60, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x38, 0x7C, 0xCE, 0x86,
    0x86, 0x06, 0x06, 0x0E, 0x3C, 0x38,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x38, 0x78,
    0xE0, 0xC1, 0xC1, 0xC3, 0xC3, 0xE6,
    0x7C, 0x38, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x18, 0x24, 0x44, 0x88, 0x44, 0x24,
    0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x80, 0x00, 0x80,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x80, 0x00, 0x80, 0x80,
    0x00, 0x00, 0x00, 0x03, 0x07, 0x0F,
    0x1F, 0x0F, 0x07, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x04, 0x08, 0x11,
    0x08, 0x04, 0x03, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00
    };

    //
    static uint8_t current_frame = 0;
    static uint32_t anim_timer = 0;
    static int8_t step = 1;
    const uint8_t speed = get_current_wpm();

    if(speed>0) {
        if (timer_elapsed32(anim_timer) > 190 || (timer_elapsed32(anim_timer) > 70 && speed > 45)|| (timer_elapsed32(anim_timer) > 30 && speed > 90)){
            oled_set_cursor( 0,0);
            anim_timer = timer_read32();
        //oled_write_raw_P(sinus, sizeof(sinus)-current_frame*7);
        
            switch(current_frame){
                case 0:
                    oled_write_raw_P(raw_logo0, sizeof(raw_logo0));
                break;
                case 1:
                    oled_write_raw_P(raw_logo1, sizeof(raw_logo1));
                break;
                case 2:
                    oled_write_raw_P(raw_logo2, sizeof(raw_logo2));
                break;
                case 3:
                    oled_write_raw_P(raw_logo3, sizeof(raw_logo3));
                break;
            }
            
            if(current_frame>=3) {
                step = -1;
            } else if(current_frame<=0) {
                step = 1;
            }
            current_frame = (current_frame + step);
        
        }
    } else {
        oled_set_cursor(0, 0);
        oled_write_raw_P(raw_logo1, sizeof(raw_logo1));
    }
}

void print_status_narrow(void) {
    oled_write_P(PSTR("\n\n"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Mod\n"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
        case 1:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Raise"), false);
            break;
        case 3:
            oled_write_P(PSTR("Lower"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    if(led_usb_state.caps_lock) {
       oled_write_ln_P(PSTR("CAPS"), false);
    } else {
       oled_write_P(PSTR("\n"), false);
    }
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return true;
}

#endif

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (index == 0) {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
    } else if (index == 1) {
        tap_code(clockwise ? KC_WH_D : KC_WH_U);
    } 
    return true;
}
#endif
