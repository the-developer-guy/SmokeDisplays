/*
  Digital dice from D2 to D100.
  Display: Stag Bar 180k puff 6in1 "disposable" vape display module.
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

#define MODE_MINUS  (8)
#define MODE_PLUS   (10)
#define DICE_ROLL   (9)
#define MODE_COUNT  (9)

bool minusPressed();
bool plusPressed();
bool rollPressed();

// Create an instance of the display.
DisplayStag6 display(2, 3, 4, 5, 6, 7);

uint32_t displayUpdateTask, buttonTask;
uint8_t modes[MODE_COUNT] = {2, 3, 4, 6, 8, 10, 12, 20, 100};

int minusLastState = HIGH;
int plusLastState = HIGH;
int rollLastState = HIGH;

void setup() {
  display.begin();
  Serial.begin(115200);

  pinMode(MODE_MINUS, INPUT_PULLUP);
  pinMode(MODE_PLUS, INPUT_PULLUP);
  pinMode(DICE_ROLL, INPUT_PULLUP);

  displayUpdateTask = micros();
  buttonTask = millis();
}

void loop() {

  // Call display.update() frequently to prevent flickering!
  if (micros() > displayUpdateTask) {
    displayUpdateTask += 200;
    display.update();
  }

  if(millis() > buttonTask) {
    buttonTask += 50;

    if(minusPressed()) {
      Serial.println("-");
    }

    if(plusPressed()) {
      Serial.println("+");
    }

    if(rollPressed()) {
      Serial.println("roll");
    }
  }
}

bool minusPressed(){
  int minusCurrentState = digitalRead(MODE_MINUS);
  bool retval = false;
  if(minusCurrentState == LOW && minusLastState == HIGH) {
    retval = true;
  }
  minusLastState = minusCurrentState;

  return retval;
}

bool plusPressed() {
  int plusCurrentState = digitalRead(MODE_PLUS);
  bool retval = false;
  if(plusCurrentState == LOW && plusLastState == HIGH) {
    retval = true;
  }
  plusLastState = plusCurrentState;

  return retval;
}

bool rollPressed() {
  int rollCurrentState = digitalRead(DICE_ROLL);
  bool retval = false;
  if(rollCurrentState == LOW && rollLastState == HIGH) {
    retval = true;
  }
  rollLastState = rollCurrentState;

  return retval;
}
