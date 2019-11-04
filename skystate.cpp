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

#include <Arduino.h>
#include "skystate.h"

SkyStates::SkyStates(const sky_state_t *states) {
  set_states(states);
}

void SkyStates::set_states(sky_state_t *states) 
{
  this->states = states;
  
  num_states = 0;
  while (states[num_states].time != -1) num_states++;
}

int SkyStates::find_index(float tm)
{
  int n = 0;
  while (states[n].time <= tm) {
    n++;
  }
  return n-1;
}

void SkyStates::get_state(float tm, sky_state_t *state)
{
  state->time = tm;

  // Wrap the time to the list of states available
  // (assume the states repeat endlessly after the last)
  float last_time = states[num_states-1].time;
  tm = fmod(tm, last_time);

  // Interpolate between the previous state and the next state
  int n = find_index(tm);
  float tm1 = states[n].time;
  float tm2 = states[n+1].time;
  float dt = tm2 - tm1;

  float p = (tm - tm1) / dt;

  float start_hue = fmod(states[n].hue, 360);
  state->hue = start_hue + (states[n+1].hue - start_hue)*p;
  state->saturation = states[n].saturation + (states[n+1].saturation - states[n].saturation)*p;
  state->value = states[n].value + (states[n+1].value - states[n].value)*p;
}
