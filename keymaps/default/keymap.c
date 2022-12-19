#include QMK_KEYBOARD_H

#include "transactions.h"
// #include <print.h>

enum layer_number {
  _QWERTY = 0,
  _MOD,
  _FN,
  _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | `    |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Tab/Ct|   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | MOD  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   '  |  MOD |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |                    |   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/                    \-----------------------------------------'
 *                   | LCtl | LAlt |BackSP| /                      \  |Space | FN   | ESC  |
 *                   |      |      |      |/                        \ |      |      |      |
 *                   `---------------------                          ''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  MT(MOD_LCTL, KC_TAB),   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  MO(_MOD),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, MO(_MOD),
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LCTL, KC_LALT, KC_BSPC,                     KC_SPC, MO(_FN), KC_ESC
),
/* MOD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  (   |   )  |      |                    |      | Home |  End |      |      |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  [   |   ]  |      |                    | Left |  Dn  |  Up  | Right|   ;  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  {   |   }  |      |                    |      | PgUp | PgDn |      |      |      |
 * `-----------------------------------------/                    \-----------------------------------------'
 *                   |      |      |DEL   | /                      \  |ENTER |      |      |
 *                   |      |      |      |/                        \ |      |      |      |
 *                   `---------------------                          ''--------------------'
 */
[_MOD] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  _______, _______, _______, KC_LPRN, KC_RPRN, _______,                   _______, KC_HOME,  KC_END,_______, _______, KC_BSLS,
  _______, _______, _______, KC_LBRC, KC_RBRC, _______,                   KC_LEFT, KC_DOWN,   KC_UP,KC_RGHT, KC_SCLN, _______,
  _______, _______, _______, KC_LCBR, KC_RCBR, _______,                   _______, KC_PGUP, KC_PGDN,_______, _______, _______,
                             _______, _______,  KC_DEL,                   KC_ENT, _______, _______
),
/* FN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |  !   |  @   |  #   |  $   |  %   |                    |  ^   |  &   |  *   |  (   | )    |   \  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   | 0    |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * `-----------------------------------------/                    \-----------------------------------------'
 *                   |      | LGUI |      | /                      \  |      |      |      |
 *                   |      |      |      |/                        \ |      |      |      |
 *                   `---------------------                          ''--------------------'
 */
[_FN] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,  KC_F12,
   KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR,KC_LPRN, KC_RPRN, KC_BSLS,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,   KC_9,    KC_0, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
                             _______, KC_LGUI, _______,                   _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  RST |      |      |      |      |      |                    |      |      |      |      |      | RST  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |  V+  |      |      |      |      | PrtSc|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |  V-  | <<   | play |  >>  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | Mute |      |      |      |      |      |
 * `-----------------------------------------/                    \-----------------------------------------'
 *                   |      |      |      | /                      \  |      |      |      |
 *                   |      |      |      |/                        \ |      |      |      |
 *                   `---------------------                          ''--------------------'
 */
[_ADJUST] = LAYOUT(
  QK_BOOT, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, QK_BOOT,
  _______, _______, _______, _______, _______, _______,                   KC_VOLU, _______, _______,_______, _______, KC_PSCR,
  _______, _______, _______, _______, _______, _______,                   KC_VOLD, KC_MPRV, KC_MPLY,KC_MNXT, _______, _______,
  _______, _______, _______, _______, _______, _______,                   KC_MUTE, _______, _______,_______, _______, _______,
                             _______, _______, _______,                   _______, _______, _______
)
};

// Tri-layer
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _MOD, _FN, _ADJUST);
}

void suspend_power_down_user(void) {
    oled_off();
}

// sync transport
typedef struct _sync_popcat_t {
    uint8_t pressFlag;
    uint8_t pressFlag2;
} sync_popcat_t;

// force rigth side to update
bool b_sync_need_send = false;

// last keycode typed
sync_popcat_t last_popcat = {0,0};

void user_sync_popcat_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const sync_popcat_t *m2s = (const sync_popcat_t*)in_data;
    // update popcat pressflag on slave side
    last_popcat.pressFlag = m2s->pressFlag;
    last_popcat.pressFlag2 = m2s->pressFlag2;
}

void keyboard_post_init_user(void) {
    // callback for tranport sync data
    transaction_register_rpc(USER_SYNC_POPCAT, user_sync_popcat_slave_handler);
}

void housekeeping_task_user(void) {
    // only for master side
    if (!is_keyboard_master()) return;

    // only if a new char was typed
    if (!b_sync_need_send) return;

    // send the char to the slave side : sync is done
    if (transaction_rpc_send(USER_SYNC_POPCAT, sizeof(last_popcat), &last_popcat)) {
        b_sync_need_send = false;
    }
}


//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE
/* 32 * 14 os logos */
static const char PROGMEM windows_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00, 0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const char PROGMEM mac_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

#define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, may need fixing

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
  // return rotation;
  return OLED_ROTATION_270;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;

volatile bool isBarking = false;
volatile bool isSneaking = false;
volatile bool isJumping  = false;
volatile bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            // print("jumping");
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (isBarking) {
            // print("barking");
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if (isSneaking) {
            // print("sneaking");
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            // print("sitting");
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            // print("walking");
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            // print("running");
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }

    /* this fixes the screen on and off bug */
    // if (current_wpm > 0) {
        // oled_on();
        // anim_sleep = timer_read32();
    // } else if (timer_elapsed32(anim_sleep) > SLEEP_TIMER) {
        // oled_off();
    // }
}

/* KEYBOARD PET END */

// Popcat stuff here
#define POPTIME 2
#define POP_IDLE_TIME 800

uint8_t current_idle_frame = 0;
uint16_t pop_anim_timer = 0;

/* Render popcat */
static void render_popcat(void) {
  // 'pop cat1', 43x32px
  static const char PROGMEM popCat1[]  = {
    0,  0,  0,  0,192, 64, 64,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64, 32,160, 64,128,  0,  0,  0,  0,  0,  0, 31, 96,158,126,254,252,251,230, 46, 24, 24,152,136,204, 66,130,  2,  2,  2,  1,  0, 64,175, 79,  0,255,  0,  0,  0,  0,  0,  0,  0,  0,  1,  6, 56,241,243,240,248, 28,  4,  0,  0,  1, 49, 16, 16,  0,  0,  0, 36, 36, 16, 16,  0,128,  1,194, 60,  0,  0,  0,  0,  0,  0,  0,192, 49, 15, 15, 12,  6,  0,128,192,224,240,248,248,252,252,252,252,252,254,254,193, 60,194,  1,  0,
    0,  0,128, 64, 48, 12,  3,  0,  0,  0,  0,  0,  0,  0,  7, 31,127,255,255,255,255,255,255,255,255,255,255,255,248,  7,248,  0,224, 30,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,255,255,255,255,255,255,255,255,254,255,  0,
  };
  // 'pop cat2', 43x32px
  static const char PROGMEM popCat2[]  = {
    0,  0,128,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64,160, 32,192,  0,  0,  0,  0,  0,  0,  7,124,192, 60,252,253,249,226,  4,  4,  8,  8, 72,100, 36, 34,  2,  2,130,162,163,131,131,136,152,  1, 30, 32, 64,128,  0,  0,  0,  0,  1,  2, 28, 49,243,243, 56,  0,  0,  0,  0,240,252,254,254,255,255,255,255,255,255,255,255,255,254,252,120,  1,254,  0,  0,  0,  0,  0,  0,192, 33, 31,  7,  0,  0,  0,  0,193,195,135,135,143,159,159,159,159,159,159,143, 79,199, 33, 16, 14,  1,
    0,  0,192, 48, 12,  3,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,255,255,255,255,255,255,255,255,255,255,240,207, 56,192,  0,  0,248,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,255,255,255,255,255,255,255,255,255,255,255,248,255,  0,  0,
  };

  static const char PROGMEM popCat3[]  = {
    0,  0,  0,192, 48,144,144,160, 32,192,128,128,  0,  0,  0,  0,  0,128,128,128,128,128, 64, 32, 16,200,232, 16,224,  0,  0,  0,  0,  0,  0,  7, 24,103,159, 63,127,254, 57, 11,  6,  6, 38, 34,115, 80, 32,  0,  0,  0,  0,  0, 16, 43, 19,  0, 63, 64,128,  0,  0,  0,  0,  0,  0,  0,  1, 14,124,252,252, 62,135,  1,  0,  0,  0, 12,  4,  4,  0,  0,  0,  9,  9,132,132, 64, 32,128,112, 15,  0,  0,  0,  0,  0,  0,192, 48, 12,  3,  3,  3,  1,  0,224,240,248,252,254,254,255,255,255,255,255,255,255,240, 15,240,  0,  0,
    0,128, 96, 16, 12,  3,  0,  0,  0,  0,  0,  0,  0,  0,  1,  7, 31,255,255,255,255,255,255,255,255,255,255,255,254,129,254,  0,224, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,  0,
  };

  oled_set_cursor(0,10);
  if (last_popcat.pressFlag){
    if (last_popcat.pressFlag2) {
      oled_write_raw_P(popCat2, sizeof(popCat2));
      last_popcat.pressFlag2--;
    } else {
      oled_write_raw_P(popCat1, sizeof(popCat1));
      last_popcat.pressFlag--;
    }
    anim_sleep = timer_read();
  } else {
    // idle
    if(timer_elapsed(pop_anim_timer) > POP_IDLE_TIME) {
        pop_anim_timer = timer_read();
        current_idle_frame = (current_idle_frame + 1) % 2;
        if (current_idle_frame == 1) {
          oled_write_raw_P(popCat3, sizeof(popCat3));  
        } else {
          oled_write_raw_P(popCat1, sizeof(popCat1));
        }         
    }

    // if(timer_elapsed(anim_sleep) > SLEEP_TIMER) {
        // oled_off();
    // }
  }
}

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();

    /* KEYBOARD PET VARIABLES END */

    if (!is_keyboard_master()) {
        // oled_clear();
        oled_set_cursor(0,1);
        oled_write_ln(read_layer_state(), false);

        render_popcat();
    } else {
        // oled_clear();
        oled_set_cursor(0, 0);
        if (keymap_config.swap_lctl_lgui) {
            oled_write_raw_P(mac_logo, sizeof(mac_logo));
        } else {
            oled_write_raw_P(windows_logo, sizeof(windows_logo));
        }
        oled_set_cursor(1,3);
        uint8_t n = get_current_wpm();
        char    wpm_counter[4];
        wpm_counter[3] = '\0';
        wpm_counter[2] = '0' + n % 10;
        wpm_counter[1] = (n /= 10) % 10 ? '0' + (n) % 10 : (n / 10) % 10 ? '0' : '0';
        wpm_counter[0] = n / 10 ? '0' + n / 10 : '0';
        oled_write_P(PSTR("WPM"), false);
        oled_set_cursor(1,4);
        oled_write(wpm_counter, false);

        render_luna(0, 13);

        if (last_popcat.pressFlag){
          if (last_popcat.pressFlag2) {
            last_popcat.pressFlag2--;
          } else {
            last_popcat.pressFlag--;
          }
        }
    }
    return false;
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /* KEYBOARD PET STATUS START */
    case KC_LCTL:
    case KC_RCTL:
        // print("seeing ctrl");
        if (record->event.pressed) {
            // print("sneak");
            isSneaking = true;
        } else {
            isSneaking = false;
        }
        break;
    case KC_SPC:
        // print("seeing space");
        if (record->event.pressed) {
            // print("jump");
            isJumping  = true;
            showedJump = false;
        } else {
            isJumping = false;
        }
        break;
    case KC_LSFT:
    case KC_RSFT:
        // print("seeing shift");
        if (record->event.pressed) {
            // print("bark");
            isBarking = true;
        } else {
            isBarking = false;
        }
        break;

        /* KEYBOARD PET STATUS END */
  }
  
  if (record->event.pressed) {
    // print("key pressed");
    // master : store keycode to sent to the other side to be process_key
    if (last_popcat.pressFlag == 0) {
      last_popcat.pressFlag = last_popcat.pressFlag2 = POPTIME;
      b_sync_need_send    = true;
    }
#ifdef OLED_ENABLE
    set_keylog(keycode, record);

    // if (pressFlag == 0) {
      // pressFlag = pressFlag2 = POPTIME;
    // }
#endif
    // set_timelog();
  }
  return true;
}
