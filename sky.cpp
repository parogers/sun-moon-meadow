/*     
 * sun-moon-meadow - An animated, LED lit art piece
 * Copyright (C) 2019  Peter Rogers (peter.rogers@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "sky.h"
#include "skystate.h"
#include "colour.h"

#define NUM_LEDS        16
#define STRIP_PIN       8

/* Static variables */

const sky_state_t SKY_NORMAL[] = {
  {0,    20,   255,    32},
  {5,    30,   255,   255},
  {10,   60,     0,   255},
  {15,  180,   255,   255},
  {20,  380,     0,     0},
  {30,    0,     0,    64},
  {40,   20,   255,    32},
  {-1,    0,     0,     0},
};

static Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, STRIP_PIN, NEO_GRB | NEO_KHZ800);
static SkyStates states = SkyStates(SKY_NORMAL);

/* Public functions */

void sky_begin() 
{
  strip.begin();
  strip.show();
}

void sky_update(float current)
{
  sky_state_t state;

  states.get_state(current, &state);
  sky_set_colour((uint16_t)state.hue, state.saturation, state.value);
}

void sky_set_colour(uint16_t hue, byte saturation, byte value)
{
  for (int n = 0; n < NUM_LEDS; n++) {
    byte red, green, blue;
    hsv2rgb(hue, saturation, value, &red, &green, &blue);
    strip.setPixelColor(n, red, green, blue);
  }
  strip.show();
}
