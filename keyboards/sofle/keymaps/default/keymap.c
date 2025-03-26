// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include <stdio.h>

#include QMK_KEYBOARD_H

// Light combinations
#define SET_LAYER_ID(hsv) 	\
	{0, 32, hsv}

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define KC_QWERTY PDF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | [    |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Enter  /       \Space \  | Bspc | RAlt | RAISE|  \   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,       KC_3,         KC_4,         KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,       KC_E,         KC_R,         KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_EQL,
  KC_LBRC,  LSFT_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), LT(_LOWER, KC_G),      LT(_RAISE, KC_H), RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN),  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,       KC_C,         KC_V,         KC_B,    KC_MUTE,     XXXXXXX,KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH, RSFT_T(KC_BSLS),
              KC_LCTL, KC_LALT, KC_LGUI, TL_LOWR, KC_ENT,                          RALT_T(KC_SPC), RSFT_T(KC_BSPC), TL_UPPR, XXXXXXX, XXXXXXX
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   6  | Home |  Up  |  End |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |UG_TOGG|hue^ |sat ^ | bri ^|      |      |-------.    ,-------|   ^  | Left | Down | Rigth|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | mode |hue dn|sat d |bri dn|      |      |-------|    |-------|   {  |   }  |   [  |   ]  |   (  |   )  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Enter  /       \Space \  | Del  | RAlt | RAISE|  \   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______, KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,  KC_PERC,                     KC_PGUP, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_F12, 
  UG_TOGG, UG_HUEU,UG_SATU, UG_VALU,  _______, KC_CAPS,                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, 
  UG_NEXT, UG_HUED,UG_SATD, UG_VALD, _______, _______, _______,       _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN,
                    _______, _______, _______, _______, _______,       _______, KC_DEL, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |      |      |                    |      | PgUp |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | PgDwn| Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Enter  /       \Space \  | Del  | RAlt | RAISE|  \   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_HOME,   KC_UP, KC_END,C(KC_BSPC), KC_BSPC,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                        KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
  _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), XXXXXXX,  _______,       _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, _______,
  //  _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,

                         _______, _______, _______, _______, _______,       _______, KC_DEL, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX,  XXXXXXX ,XXXXXXX,  XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT , XXXXXXX,KC_QWERTY,KC_QWERTY,CG_TOGG,  XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                       XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

#ifdef RGBLIGHT_ENABLE
//char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_BLUE)
);

// _LOWER,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_lower_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);
// _RAISE,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_raise_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_MAGENTA)
);

// _ADJ,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_adjust_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_GOLD)
);

// Caps,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_caps_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {12, 4, HSV_RED}, 
    {16+5, 6, HSV_RED} 
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
	layer_lower_lights,
    layer_raise_lights,
    layer_adjust_lights,
    layer_caps_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
    led_t led_usb_state = host_keyboard_led_state();
	rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY) && layer_state_cmp(default_layer_state,_QWERTY));
	rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(4, led_usb_state.caps_lock);

    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
	rgblight_mode(10);// haven't found a way to set this in a more useful way
}
#endif
