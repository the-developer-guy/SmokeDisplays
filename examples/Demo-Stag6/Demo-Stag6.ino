#include "SmokeDisplay.h"

DisplayStag6 display(2, 3, 4, 5, 6, 7);
uint32_t task, task2;
int num = 0;
bool on = false;

void setup() {
  display.begin();
  task = micros();
  task2 = millis();
  Serial.begin(115200);
}

void loop() {
    if(micros() > task) {
      task += 200;
      display.update();
    }

    if(millis() > task2) {
      task2 += 1000;
      num++;
      if(num > 6) {
        num = 1;
      }
      display.setNumber(num);
      display.set(num);
      display.setDroplet(on);
      display.setThunder(!on);
      on = !on;
    }
    
    
}
