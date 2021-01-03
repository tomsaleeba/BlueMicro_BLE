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
#include <bluefruit.h> // only for Serial.println calls
#include "keymap.h"

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
        KEYMAP2ARRAY(KEYMAP(
        KC_7,    KC_8,    KC_9,    KC_NO,
        KC_4,    KC_5,    KC_6,    KC_NO,
        KC_1,    KC_2,    KC_3,    KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO
        ));

void printKeysToSerial(uint8_t* currentReport)
{
  bool something_printed = false;
  for (int i = 0; i < 8; i++) {
    uint8_t v = currentReport[i];
    if (v > 0) {
      Serial.println(v);
      something_printed = true;
    }
  }
  if (something_printed) {
    Serial.println("-------------");
  }
}

void process_combos(uint8_t* currentReport)
{
  printKeysToSerial(currentReport);
  uint8_t firstKey = currentReport[1];
  uint8_t secondKey = currentReport[2];
  // FIXME how to impl well?
  if (firstKey == KC_1 && secondKey == KC_2) {
    currentReport[1] = KC_A;
    currentReport[2] = 0;
  }
  // FIXME can we *only* match the longest combo?
}

void setupKeymap() {}
