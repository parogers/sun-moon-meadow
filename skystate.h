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

#ifndef __SKY_STATE_H__
#define __SKY_STATE_H__

typedef struct
{
  float time;
  int hue;
  int saturation;
  int value;

} sky_state_t;

class SkyStates
{
public:
  const sky_state_t *states;
  int num_states;
  
  SkyStates(const sky_state_t *states);

  void set_states(sky_state_t *states);

  // Returns the index of the state that comes immediately before the given time
  // (note this function handles wrapping from last state to first state)
  int find_index(float tm);

  void get_state(float tm, sky_state_t *state);
};

#endif
