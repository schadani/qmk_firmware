#include "ergodox.h"
#include "led.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"

#define BASE   0 // DEFAULT LAYER
#define NMPD   1 // SYMBOLS LAYER
#define SPEC   3 // SPECIAL LAYER

#define NUMPAD  10 // NUMPAD  KEY
#define SPECIAL 11 // SPECIAL KEY

#define MUL   20 // MOUSE UP LEFT
#define MUR   21 // MOUSE UP RIGHT
#define MDL   22 // MOUSE DOWN LEFT
#define MDR   23 // MOUSE DOWN RIGHT

#define SSH   30 // SSH LOGIN
#define SPW   31 // SUDO PASSWORD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/******* Base Layer *****************************************************************************************************
 *
 * ,------------------------------------------------------.       ,------------------------------------------------------.
 * |     ESC    |   1  |   2  |   3  |   4  |   5  |   6  |       |   7  |   8  |   9  |   0  |   -  |   =  |     `~     |
 * |------------+------+------+------+------+-------------|       |------+------+------+------+------+------+------------|
 * |     TAB    |   Q  |   W  |   E  |   R  |   T  | HOME |       | PgUp |   Y  |   U  |   I  |   O  |   P  |      \|    |
 * |------------+------+------+------+------+------|      |       |      |------+------+------+------+------+------------|
 * |   NUMPAD   |   A  |   S  |   D  |   F  |   G  |------|       |------|   H  |   J  |   K  |   L  |  ;   |      '"    |
 * |------------+------+------+------+------+------| END  |       | PgDn |------+------+------+------+------+------------|
 * |   LSHIFT   |   Z  |   X  |   C  |   V  |   B  |      |       |      |   N  |   M  |   ,  |   .  |  /   |   RSHIFT   |
 * `------------+------+------+------+------+-------------'       `-------------+------+------+------+------+------------'
 *      |  LCTL | DEL  |  SSH |  SPW | LALT |                                   | RALT |  MEH | HYPR |  DEL | RCTRL |
 *      `-----------------------------------'                                   `-----------------------------------'
 *                                          ,-------------.       ,-------------.
 *                                          | Zoom-|  (   |       |   )  | Zoom+|
 *                                   ,------|------|------|       |------+------+------.
 *                                   |      |      |  [   |       |   ]  |      |      |
 *                                   | SPC  | SPEC |------|       |------|  ENT | BKSP |
 *                                   |      |      |  {   |       |   }  |      |      |
 *                                   `--------------------'       `--------------------'
 */
[BASE] = KEYMAP(
// left hand
 KC_ESC   ,KC_1  ,KC_2  ,KC_3  ,KC_4 ,KC_5 ,KC_6
,KC_TAB   ,KC_Q  ,KC_W  ,KC_E  ,KC_R ,KC_T ,KC_HOME
,M(NUMPAD),KC_A  ,KC_S  ,KC_D  ,KC_F ,KC_G
,KC_LSFT  ,KC_Z  ,KC_X  ,KC_C  ,KC_V ,KC_B ,KC_END
,KC_LCTL  ,KC_DEL,M(SSH),M(SPW),KC_LALT
                            ,LCTL(KC_MINS) ,KC_LCBR
                                           ,KC_LPRN
                        ,KC_SPC ,M(SPECIAL),KC_LBRC
                                                                  // right hand
                                                                 ,KC_7    ,KC_8   ,KC_9   ,KC_0   ,KC_MINS ,KC_EQL   ,KC_GRV
                                                                 ,KC_PGUP ,KC_Y   ,KC_U   ,KC_I   ,KC_O    ,KC_P     ,KC_BSLS
                                                                          ,KC_H   ,KC_J   ,KC_K   ,KC_L    ,KC_SCLN  ,KC_QUOT
                                                                 ,KC_PGDN ,KC_N   ,KC_M   ,KC_COMM,KC_DOT  ,KC_SLSH  ,KC_RSFT
                                                                                  ,KC_RALT,KC_MEH ,KC_HYPR ,KC_DEL   ,KC_RCTL
                                                                 ,KC_RCBR ,LCTL(KC_EQL)
                                                                 ,KC_RPRN
                                                                 ,KC_RBRC ,KC_ENT ,KC_BSPC
    ),

/******* Numpad / Symbols Layer ***************************************************************************************
 *
 * ,-----------------------------------------------------.       ,-----------------------------------------------------.
 * |           |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |       |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |           |
 * |-----------+------+------+------+------+-------------|       |------+------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |       |      |      |   7  |   8  |   9  |   /  |           |
 * |-----------+------+------+------+------+------|      |       |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |------|       |------|      |   4  |   5  |   6  |   *  |           |
 * |-----------+------+------+------+------+------|      |       |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |       |      |      |   1  |   2  |   3  |   -  |           |
 * `-----------+------+------+------+------+-------------'       `-------------+------+------+------+------+-----------'
 *     |       |      |      |      |      |                                   |   0  |   .  |   =  |   +  |       |
 *     `-----------------------------------'                                   `-----------------------------------'
 *                                         ,-------------.       ,-------------.
 *                                         |      |      |       |      |      |
 *                                  ,------|------|------|       |------+------+------.
 *                                  |      |      |      |       |      |      |      |
 *                                  |      | SPEC |------|       |------|      |      |
 *                                  |      |      |      |       |      |      |      |
 *                                  `--------------------'       `--------------------'
 */
[NMPD] = KEYMAP(
// left hand
 KC_TRNS ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6
,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                             ,KC_TRNS ,KC_TRNS
                                                      ,KC_TRNS
                                   ,KC_TRNS ,M(SPECIAL),KC_TRNS
                                                                 // right hand
                                                                 ,KC_F7   ,KC_F8   ,KC_F9 ,KC_F10 ,KC_F11,KC_F12  ,KC_TRNS
                                                                 ,KC_TRNS ,KC_TRNS ,KC_7  ,KC_8   ,KC_9  ,KC_SLSH ,KC_TRNS
                                                                          ,KC_TRNS ,KC_4  ,KC_5   ,KC_6  ,KC_ASTR ,KC_TRNS
                                                                 ,KC_TRNS ,KC_TRNS ,KC_1  ,KC_2   ,KC_3  ,KC_MINS ,KC_TRNS
                                                                                   ,KC_0  ,KC_DOT ,KC_EQL,KC_PLUS ,KC_TRNS
                                                                 ,KC_TRNS ,KC_TRNS
                                                                 ,KC_TRNS
                                                                 ,KC_TRNS ,KC_TRNS ,KC_TRNS
),

/******* Special Layer *************************************************************************************************
 *
 * ,-------------------------------------------------------.    ,-------------------------------------------------------.
 * |             |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |    |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |             |
 * |-------------+------+------+------+------+-------------|    |------+------+------+------+------+------+-------------|
 * |             |      |      |  UP  |      |CTRL+T| PREV |    | NEXT |      |M-UPLF| M-UP |M-UPRG|      |             |
 * |-------------+------+------+------+------+------|      |    |      |------+------+------+------+------+-------------|
 * |             |CTRL+A| LEFT | DOWN | RIGHT|CTRL+F|------|    |------|      |M-LEFT|M-DOWN|MRIGHT|      |             |
 * |-------------+------+------+------+------+------| VOL  |    | VOL  |------+------+------+------+------+-------------|
 * |  CAPSLOCK   |CTRL+Z|CTRL+X|CTRL+C|CTRL+V|CTRL+S| DOWN |    | UP   |      |M-DNLF|      |M-DNRG|      |   CAPSLOCK  |
 * `-------------+------+------+------+------+-------------'    `-------------+------+------+------+------+-------------'
 *      |        |      |      |      |      |                                |      |      |      |      |        |
 *      `------------------------------------'                                `------------------------------------'
 *                                         ,-------------.     ,-------------.
 *                                         |      |      |     |      |      |
 *                                  ,------|------|------|     |------+------+------.
 *                                  |      |      |      |     |      |      |      |
 *                                  | LGUI | SPEC |------|     |------| MB1  | MB2  |
 *                                  |      |      |      |     |      |      |      |
 *                                  `--------------------'     `--------------------'
 */
[SPEC] = KEYMAP(
// left hand
 KC_TRNS  ,KC_F13    ,KC_F14    ,KC_F15    ,KC_F16    ,KC_F17    ,KC_F18
,KC_TRNS  ,KC_TRNS   ,KC_TRNS   ,KC_UP     ,KC_TRNS   ,LCTL(KC_T),KC_MPRV
,M(NUMPAD),LCTL(KC_A),KC_LEFT   ,KC_DOWN   ,KC_RIGHT  ,LCTL(KC_F)
,KC_CAPS  ,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),LCTL(KC_S),KC_VOLD
,KC_TRNS  ,KC_TRNS   ,KC_TRNS  ,KC_TRNS    ,KC_TRNS
                                                        ,KC_TRNS ,KC_TRNS
                                                                 ,KC_TRNS
                                                ,KC_LGUI,KC_TRNS ,KC_TRNS
                                                             // right hand
                                                             ,KC_F19  ,KC_F20  ,KC_F21  ,KC_F22  ,KC_F23  ,KC_F24  ,KC_TRNS
                                                             ,KC_MNXT ,KC_TRNS ,M(MUL)  ,KC_MS_U ,M(MUR)  ,KC_TRNS ,KC_TRNS
                                                                      ,KC_TRNS ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_TRNS ,KC_TRNS
                                                             ,KC_VOLU ,KC_TRNS ,M(MDL)  ,KC_TRNS ,M(MDR)  ,KC_TRNS ,KC_CAPS
                                                                               ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                             ,KC_TRNS ,KC_TRNS
                                                             ,KC_TRNS
                                                             ,KC_TRNS ,KC_BTN1 ,KC_BTN2
    )
};

const uint16_t PROGMEM fn_actions[] = {
     // the faux shift keys are implemented as macro taps
     [NUMPAD] = ACTION_MACRO_TAP(NUMPAD)
    ,[SPECIAL] = ACTION_MACRO_TAP(SPECIAL)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {

      case SSH: // SSH MACRO
          return MACRODOWN(T(S),T(S),T(H),T(SPC),T(D), T(A), T(N), T(I), T(E), T(L), D(LSFT), T(2), U(LSFT), T(S), T(E), T(R), T(V), T(E), T(R), T(ENT), END);
      case SPW: // SUDO PASSWORD MACRO
          return MACRODOWN(T(I), T(N), T(S), T(J), T(C), T(T), T(K), T(0), D(LSFT), T(3), U(LSFT), T(ENT), END);

        // LAYER MACROS #######################################################

        case NUMPAD:
        if (record->event.pressed) {
            layer_on(NMPD);
        } else {
            layer_off(NMPD);
        }
        break;
        //
        case SPECIAL:
        if (record->event.pressed) {
            layer_on(SPEC);
        } else {
            layer_off(SPEC);
            }
        break;

        // MOUSE MACROS #######################################################

        case MUL: // MOUSE UP LEFT
        if (record->event.pressed) {
            mousekey_on(KC_MS_UP);
            mousekey_on(KC_MS_LEFT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_UP);
            mousekey_off(KC_MS_LEFT);
            mousekey_send();
        }
        break;

        case MUR: // MOUSE UP RIGHT
        if (record->event.pressed) {
            mousekey_on(KC_MS_UP);
            mousekey_on(KC_MS_RIGHT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_UP);
            mousekey_off(KC_MS_RIGHT);
            mousekey_send();
        }
        break;

        case MDL: // MOUSE DOWN LEFT
        if (record->event.pressed) {
            mousekey_on(KC_MS_DOWN);
            mousekey_on(KC_MS_LEFT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_DOWN);
            mousekey_off(KC_MS_LEFT);
            mousekey_send();
        }
        break;

        case MDR: // MOUSE DOWN RIGHT
        if (record->event.pressed) {
            mousekey_on(KC_MS_DOWN);
            mousekey_on(KC_MS_RIGHT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_DOWN);
            mousekey_off(KC_MS_RIGHT);
            mousekey_send();
        }
        break;
        //
        default:
            // NONE
            break;
    }

    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// LED CONTROL ################################################################
void matrix_scan_user(void) {
    // L/R SHIFT / CAPS RED LED ON
    if((keyboard_report->mods & MOD_BIT(KC_LSFT))
    || (keyboard_report->mods & MOD_BIT(KC_RSFT))
    || (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK))) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }

    // NUMPAD LAYER GREEN LED ON
    if(layer_state & (1UL<<NMPD)) {
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_off();
    }

    // MEDIA LAYER BLUE LED ON
    if(layer_state & (1UL<<SPEC)) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
};
