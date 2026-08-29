/*
  SmokeDisplay-VapSolo4-bicolor.cpp - Library for salvaged smoke displays.
  Created by DURUCZ Béla, August 29, 2026.
*/

#include "Arduino.h"
#include "SmokeDisplay.h"
#include "6pin-2.5digit-bicolor.h"

#define SEGMENT_COUNT (21)

static uint32_t segmentValues[SEGMENT_COUNT] = {DISPLAY_1_B_PINS, DISPLAY_1_C_PINS,
    DISPLAY_2_A_PINS, DISPLAY_2_B_PINS, DISPLAY_2_C_PINS, DISPLAY_2_D_PINS, DISPLAY_2_E_PINS, DISPLAY_2_F_PINS, DISPLAY_2_G_PINS,
    DISPLAY_3_A_PINS, DISPLAY_3_B_PINS, DISPLAY_3_C_PINS, DISPLAY_3_D_PINS, DISPLAY_3_E_PINS, DISPLAY_3_F_PINS, DISPLAY_3_G_PINS,
    DISPLAY_BATT_RED_PINS, DISPLAY_BATT_GREEN_PINS,
    DISPLAY_DROPLET_RED_PINS, DISPLAY_DROPLET_GREEN_PINS,
    DISPLAY_PERCENT_PINS};

static uint32_t segments[3][10] = {
    {0, DISPLAY_1_NUM_1, 0, 0, 0, 0, 0, 0, 0, 0},
    {DISPLAY_2_NUM_0, DISPLAY_2_NUM_1, DISPLAY_2_NUM_2, DISPLAY_2_NUM_3, DISPLAY_2_NUM_4, 
        DISPLAY_2_NUM_5, DISPLAY_2_NUM_6, DISPLAY_2_NUM_7, DISPLAY_2_NUM_8, DISPLAY_2_NUM_9},
    {DISPLAY_3_NUM_0, DISPLAY_3_NUM_1, DISPLAY_3_NUM_2, DISPLAY_3_NUM_3, DISPLAY_3_NUM_4, 
        DISPLAY_3_NUM_5, DISPLAY_3_NUM_6, DISPLAY_3_NUM_7, DISPLAY_3_NUM_8, DISPLAY_3_NUM_9}
};

DisplaySolo4::DisplaySolo4(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF) { 
    pins[0] = pinA;
    pins[1] = pinB;
    pins[2] = pinC;
    pins[3] = pinD;
    pins[4] = pinE;
    pins[5] = pinF;
}

void DisplaySolo4::begin() {
    clearPins();
    currentSegment = 0;
    displayBits = 0;
}

void DisplaySolo4::set(int value) {
    displayBits = displayBits & (~DISPLAY_SEGMENTS_BITMASK);
    if(value > 199 || value < 0) {
        return;
    }

    int tempValue = value;
    int digit1 = tempValue / 100;
    tempValue -= digit1 * 100;
    int digit2 = tempValue / 10;
    tempValue -= digit2 * 10;
    int digit3 = tempValue;

    if(value >= 100) {
        displayBits |= segments[0][digit1];
    }
    if(value >= 10) {
        displayBits |= segments[1][digit2];
    }
    displayBits |= segments[2][digit3];
}

void DisplaySolo4::batteryRed() {
    displayBits &= (~DISPLAY_BATTERY_GREEN_BITMASK);
    displayBits |= DISPLAY_BATTERY_RED_BITMASK;
}

void DisplaySolo4::batteryGreen() {
    displayBits &= (~DISPLAY_BATTERY_RED_BITMASK);
    displayBits |= DISPLAY_BATTERY_GREEN_BITMASK;
}

void DisplaySolo4::dropletRed() {
    displayBits &= (~DISPLAY_DROPLET_GREEN_BITMASK);
    displayBits |= DISPLAY_DROPLET_RED_BITMASK;
}

void DisplaySolo4::dropletGreen() {
    displayBits &= (~DISPLAY_DROPLET_RED_BITMASK);
    displayBits |= DISPLAY_DROPLET_GREEN_BITMASK;
}

void DisplaySolo4::percentOn() {
    displayBits |= DISPLAY_PERCENT_BITMASK;
}

void DisplaySolo4::batteryOff() {
    displayBits &= (~(DISPLAY_BATTERY_RED_BITMASK | DISPLAY_BATTERY_GREEN_BITMASK));
}

void DisplaySolo4::dropletOff() {
    displayBits &= (~(DISPLAY_DROPLET_RED_BITMASK | DISPLAY_DROPLET_GREEN_BITMASK));
}

void DisplaySolo4::percentOff() {
    displayBits &= (~DISPLAY_PERCENT_BITMASK);
}

void DisplaySolo4::update() { 
    clearPins();

    currentSegment++;
    if(currentSegment >= SEGMENT_COUNT) {
        currentSegment = 0;
    }

    if(displayBits & ((1ul)<<currentSegment)){
        setSegment(currentSegment);
    }
}

void DisplaySolo4::clearPins() {
    for(int i = 0; i < 6; i++) {
        pinMode(pins[i], INPUT);
        digitalWrite(pins[i], LOW);
    }
}

void DisplaySolo4::setSegment(int segment){
    uint32_t pinValue = segmentValues[segment];

    for(int i = 0; i < 6; i++) {
        uint32_t currentPin = (pinValue >> (i*2)) & 0b11;
        if(currentPin & 0b10) {
            pinMode(pins[i], OUTPUT);
            if(currentPin & 0b01) {
                digitalWrite(pins[i], HIGH);
            }
        }
    }
}
