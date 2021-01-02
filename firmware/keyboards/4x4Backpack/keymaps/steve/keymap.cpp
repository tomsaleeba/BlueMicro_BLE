/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
  {{
    {KC_Q,     KC_W,     KC_E,     KC_NO,},
    {KC_A,     KC_S,     KC_D,     KC_NO,},
    {KC_NO,    KC_X,     KC_C,     KC_NO,},
    {KC_LALT,  LAYER_1,  KC_LCTRL, KC_SPACE}
  }};


void setupKeymap() {
  uint32_t tap[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
    KC_NO,    KC_NO,    KC_NO,     KC_NO,
    KC_NO,    KC_NO,    KC_NO,     KC_NO,
    KC_Z,     KC_NO,    KC_NO,     KC_NO,
    KC_NO,    KC_NO,    KC_NO,     KC_NO
  );

  uint32_t hold[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
    KC_NO,    KC_NO,    KC_NO,     KC_R,
    KC_NO,    KC_NO,    KC_NO,     KC_F,
    KC_LSHIFT,KC_NO,    KC_NO,     KC_V,
    KC_NO,    KC_NO,    KC_NO,     KC_NO
  );

  uint32_t singletap[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
    KC_NO,    KC_NO,    KC_NO,     KC_R,
    KC_NO,    KC_NO,    KC_NO,     KC_F,
    KC_NO,    KC_NO,    KC_NO,     KC_V,
    KC_NO,    KC_NO,    KC_NO,     KC_NO
  );

  uint32_t doubletap[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
    KC_NO,    KC_NO,    KC_NO,     KC_T,
    KC_NO,    KC_NO,    KC_NO,     KC_G,
    KC_NO,    KC_NO,    KC_NO,     KC_B,
    KC_NO,    KC_NO,    KC_NO,     KC_NO
  );

  uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
    KC_ESC,   KC_UP,    KC_TAB,    KC_T,
    KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_G,
    KC_M,     KC_L,     KC_I,      KC_O,
    LAYER_1,  KC_NO,    KC_NO,     KC_ENTER
  );

  /*
   * add the other layers
   */
  for (int row = 0; row < MATRIX_ROWS; ++row) {
    for (int col = 0; col < MATRIX_COLS; ++col) {
      matrix[row][col].addActivation(
          _L0, Method::MT_TAP, tap[row][col]);
      matrix[row][col].addActivation(
          _L0, Method::MT_HOLD, hold[row][col]);
      matrix[row][col].addActivation(
          _L0, Method::DT_TAP, singletap[row][col]);
      matrix[row][col].addActivation(
          _L0, Method::DT_DOUBLETAP, doubletap[row][col]);
      matrix[row][col].addActivation(
          _L1, Method::PRESS, layer1[row][col]);
    }
  }
}

// Rage2
// alt: rush
// 1-9: weapons
