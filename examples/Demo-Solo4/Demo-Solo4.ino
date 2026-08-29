/*
Test application for Vapsolo Quads 80000 "disposable" vape display module.
Module ID: LZ-13WO7

Pinout:

A0  A       BATT       -   -
A1  B               | | | | |
A2  C                  -   -
A3  D               | | | | |
A4  E                  -   -
A5  F       DROPLET             %

*/

#include "SmokeDisplay.h"

// Create an instance of the display.
DisplaySolo4 display(A0, A1, A2, A3, A4, A5);

uint32_t displayUpdateTask, countTask;
int numberValue = 0;
int numberSegment = 0;
bool on = false;
int trit = 0;

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

    // Example on using the battery, droplet and percent icons.
    trit++;
    switch(trit) {
      default:
        trit = 0;
      case 0:
        display.batteryRed();
        display.dropletGreen();
        break;
      case 1:
        display.batteryGreen();
        display.dropletOff();
        break;
      case 2:
        display.batteryOff();
        display.dropletRed();
    }

    if (on) {
      display.percentOff();
    } else {
      display.percentOn();
    }
    on = !on;
  }
}
