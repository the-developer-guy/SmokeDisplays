/*

*/

#include "SmokeDisplay.h"

// Create an instance of the display.
DisplaySolo4 display(A0, A1, A2, A3, A4, A5);

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

    // Example on using the thunder and droplet icons.
    if (on) {
      display.dropletOff();
      display.batteryOn();
      display.percentOff();

    } else {
      display.dropletOn();
      display.batteryOff();
      display.percentOn();
    }
    on = !on;
  }
}
