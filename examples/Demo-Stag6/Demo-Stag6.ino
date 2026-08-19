/*
  Test application for Stag Bar 180k puff 6in1 "disposable" vape display module.
  Pinout:

  2 3 4 5 6 7
  A B C D E F
     -   -
  | | | | | ⚡
     -   -
  | | | | | 💧
     -   -
       4
     5   3
     6   2
       1 
*/

#include "SmokeDisplay.h"

// Create an instance of the display.
DisplayStag6 display(2, 3, 4, 5, 6, 7);

uint32_t displayUpdateTask, countTask;
int numberValue = 0;
int numberSegment = 0;
bool on = false;

void setup() {
  display.begin();

  displayUpdateTask = micros();
  countTask = millis();
}

void loop() {

  // Call display.update() frequently to prevent flickering!
  if (micros() > displayUpdateTask) {
    displayUpdateTask += 200;
    display.update();
  }

  if (millis() > countTask) {
    countTask += 500;

    // Example to set a value on the 2.5 digit 7-segment display.
    display.set(numberValue);
    numberValue++;
    if (numberValue > 199) {
      numberValue = 0;
    }

    // Example to set a number on the 6-number display. 0 means no active number.
    display.setNumber(numberSegment);
    numberSegment++;
    if (numberSegment > 6) {
      numberSegment = 0;
    }

    // Example on using the thunder and droplet icons.
    if (on) {
      display.dropletOff();
      display.thunderOn();

    } else {
      display.dropletOn();
      display.thunderOff();
    }
    on = !on;
  }
}
