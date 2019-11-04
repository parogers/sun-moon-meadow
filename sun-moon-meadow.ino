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

#include <Servo.h>
#include "colour.h"
#include "sky.h"

#define SERVO_PIN       3
#define SERVO_SLOW_CW   90
#define SERVO_SLOW_CCW  96

Servo servo;

void setup() 
{
  Serial.begin(9600);
  sky_begin();

  servo.attach(SERVO_PIN);
  //servo.write(SERVO_SLOW_CW);
  //delay(1000);
  servo.detach();
}

void loop() 
{
  float current = millis()/1000.0;
  //servo.write(95);

  sky_update(current);

  #if 0
  servo.write(SERVO_SLOW_CW);
  delay(2000);
  servo.write(SERVO_SLOW_CCW);
  delay(2000);
  #endif
}
