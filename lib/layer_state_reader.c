
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "hana.h"

#define L_BASE 0
#define L_GAME (1 << 1)
#define L_GAMEALT (1 << 2)
#define L_GAMEALT_GAME (L_GAMEALT | L_GAME)
#define L_NAV (1 << 3)
#define L_NAV_GAME (L_NAV | L_GAME)
#define L_NAV_GAMEALT (L_NAV | L_GAME | L_GAMEALT)
#define L_SYM (1 << 4)
#define L_SYM_GAME (L_SYM | L_GAME)
#define L_SYM_GAMEALT (L_SYM | L_GAME | L_GAMEALT)
#define L_ADJUST (1 << 5)
#define L_ADJUST_TRI (L_ADJUST | L_SYM | L_NAV)
#define L_ADJUST_TRI_GAME (L_ADJUST | L_SYM | L_NAV | L_GAME)
#define L_ADJUST_TRI_GAMEALT (L_ADJUST | L_SYM | L_NAV | L_GAME | L_GAMEALT)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "LAYERBase ");
    break;
  case L_GAME:
    snprintf(layer_state_str, sizeof(layer_state_str), "LAYERGame  ");
    break;
  case L_GAMEALT:
  case L_GAMEALT_GAME:
    snprintf(layer_state_str, sizeof(layer_state_str), "LAYERGAlt  ");
    break;
  case L_NAV:
  case L_NAV_GAME:
  case L_NAV_GAMEALT:
    snprintf(layer_state_str, sizeof(layer_state_str), "LAYERNav  ");
    break;
  case L_SYM:
  case L_SYM_GAME:
  case L_SYM_GAMEALT:
    snprintf(layer_state_str, sizeof(layer_state_str), "LAYERSym   ");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
  case L_ADJUST_TRI_GAME:
  case L_ADJUST_TRI_GAMEALT:
    snprintf(layer_state_str, sizeof(layer_state_str), "LAYERMacro");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "LAYERUndef-%u", layer_state);
  }

  return layer_state_str;
}
