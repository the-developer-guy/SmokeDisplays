/*
  SmokeDisplay.h - Library for salvaged smoke displays.
  Created by DURUCZ Béla, July 1, 2026.
*/

#ifndef SMOKE_DISPLAY_H
#define SMOKE_DISPLAY_H

class DisplayStag6
{
  public:
    DisplayStag6(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF);
    void begin();
    void set(int value);
    void setNumber(int value);
    void setThunder(bool on);
    void setDroplet(bool on);
    void update();
  private:
    uint32_t displayBits;
    int pins[6];
    int currentSegment;
    void clearPins();
    void setSegment(int segment);
};

#endif

