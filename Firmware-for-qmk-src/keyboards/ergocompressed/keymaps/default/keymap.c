#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#define CO_PA M(0)
#define EMAIL M(1)
#define URL M(2)
#define ESC_CSESC M(3)
#define ONE_IP M(4)
#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM 250

#ifdef DEBOUNCE
#undef DEBOUNCE
#endif
#define DEBOUNCE 3



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------------------------------.           ,----------------------------------------------------.
 * |Esc/C+S+Esc| 1/IP |   2  |   3  |   4  |   5  |  +=  |           |  L1  |   6  |   7  |   8  |   9  |   0  |     -_   |
 * |--------+------+------+------+------+---------+------|           |------+------+------+------+------+------+----------|
 * |     |\    |   Q  |   W  |   E  |   R  |   T  |Mo(L1)|           |  [{  |   Y  |   U  |   I  |   O  |   P  |    ]}    |
 * |-----------+------+------+------+------+------+------|           |------+------+------+------+------+------+----------|
 * |     Tab   |   A  |   S  |   D  |   F  |   G  |W+PBrk|           | Menu |   H  |   J  |   K  |   L  |  ;:  |    '"    |
 * |-----------+------+------+------+------+------+------|           |------+------+------+------+------+------+----------|
 * | OSM LShift|   Z  |   X  |   C  |   V  |   B  |Hyper |           |Win+R |   N  |   M  |   ,  |   .  |  /?  |OSM RShift|
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+----------'
 *   |OSM LCtrl|  GrV |Co/Pa |@gmai | /r/mk|                                        | Left | Down |  Up  |Right |OSM RCtrl|
 *   `------------------------------------'                                         `------------------------------------'
 *                                           ,-------------.       ,------------.
 *                                           | PgUp | PgDn |       | Home | End |
 *                                  ,--------|------|------|       |------+-------+---------.
 *                                  |OSM LAlt|PrnScr| Home |       | PgUp | PaBrk |OSM AltGr|
 *                                  |--------+------+------|       |------+-------+---------|
 *                                  | BkSp   | Del  | LGui |       | RGui | Enter |  Space  |
 *                                  `----------------------'       `------------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergocompressed_82(  // layer 0 : default
        // left hand
        ESC_CSESC,       ONE_IP,       KC_2,   KC_3,   KC_4,   KC_5,   KC_EQL,
        KC_NUBS,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   MO(SYMB),
        KC_TAB,          KC_A,         KC_S,   KC_D,   KC_F,   KC_G,   RGUI(KC_BRK),
        OSM(MOD_LSFT),   KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_MEH,
        OSM(MOD_LCTL),KC_GRV,CO_PA, EMAIL,URL,
                                                              KC_HOME, KC_END,
                                               OSM(MOD_LALT), KC_PSCR, KC_INSERT,
                                               KC_BSPC      , KC_DEL , KC_LGUI,
        // right hand
             TG(SYMB),    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             KC_LBRC,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_RBRC,
             KC_APP,     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             LWIN(KC_R),  KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          OSM(MOD_RSFT),
                                  KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,         OSM(MOD_RCTL),
             KC_PGUP,        KC_PGDN,
             KC_CAPS,KC_BRK,OSM(MOD_RALT),
             KC_RGUI,KC_ENTER, KC_SPACE
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Version|  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |      |           |      | Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |Debug |      |       |      | Reset|      |
 *                                 |------|------|------|       |------|------|------|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergocompressed_82(
       // left hand
       M(10)  ,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,KC_TRNS,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                               KC_TRNS,DEBUG,KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
       KC_TRNS, KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS, RESET, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |      |           |      |      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+----------.
 *                                 |      |      |      |       |      |      |          |
 *                                 |------|------|------|       |------|------|----------|
 *                                 |      |      |      |       |      |      |BrwserBack|
 *                                 `--------------------'       `------------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergocompressed_82(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
								  KC_TRNS, KC_TRNS, KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};
static uint16_t key_timer;
#define TIMEOUT 250 //Dual function macro threshold

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
	case 0: { //Copy Paste
            if (record->event.pressed) {
                key_timer = timer_read(); //start timer on keypress
            }
            else { // What to do when released 
                if (timer_elapsed(key_timer) > TIMEOUT) { //if held longer 
                    return MACRO( D(LCTL), T(C), U(LCTL), END  );
                }
                else { // if just tapped
                    return MACRO( D(LCTL), T(V), U(LCTL), END  );
                }
		}
	break;}
       case 3: {//ESC Ctrl+Shift+Esc (task manager in windows)
            if (record->event.pressed) {
                key_timer = timer_read(); 
            }
            else { 
                if (timer_elapsed(key_timer) > TIMEOUT) { 
                    return MACRO( D(LCTL), D(LSFT),T(ESC),U(LSFT), U(LCTL), END  );
                }
                else {
                    return MACRO( T(ESC), END  );
                }
                }
        break;}
       case 4: { //1 on tap and if held longer continues to write rest of the ip 192.168.0.
            if (record->event.pressed) {
                key_timer = timer_read(); 
           	return MACRO(T(1),END); //on keypress we immediatly type 1 not to wait until it times out 
		}
            else { 
                if (timer_elapsed(key_timer) > TIMEOUT) { // only matters if held longer 
                    SEND_STRING("92.168.0.");
                }
                }
        break;}

        case 1:
        if (record->event.pressed) { //Email
          SEND_STRING ("@gmail.com");
        }
        break;
        case 2:
        if (record->event.pressed) {
          SEND_STRING ("http://reddit.com/r/MechanicalKeyboards");
        }
        break;

        case 10:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
	case 3:
	    ergodox_right_led_3_on();
        default:
            // none
            break;
    }

};
