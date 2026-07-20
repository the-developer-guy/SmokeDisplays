/*
  SmokeDisplay-Stag6.cpp - Library for salvaged smoke displays.
  Created by DURUCZ Béla, July 2, 2026.
*/

#include "Arduino.h"
#include "SmokeDisplay.h"
#include "6pin-2.5digit-6num.h"


uint32_t segmentValues[24] = {DISPLAY_1_B_PINS, DISPLAY_1_C_PINS,
    DISPLAY_2_A_PINS, DISPLAY_2_B_PINS, DISPLAY_2_C_PINS, DISPLAY_2_D_PINS, DISPLAY_2_E_PINS, DISPLAY_2_F_PINS, DISPLAY_2_G_PINS,
    DISPLAY_3_A_PINS, DISPLAY_3_B_PINS, DISPLAY_3_C_PINS, DISPLAY_3_D_PINS, DISPLAY_3_E_PINS, DISPLAY_3_F_PINS, DISPLAY_3_G_PINS,
    DISPLAY_THUNDER_PINS, DISPLAY_DROPLET_PINS,
    DISPLAY_NUM_1_PINS, DISPLAY_NUM_2_PINS, DISPLAY_NUM_3_PINS, DISPLAY_NUM_4_PINS, DISPLAY_NUM_5_PINS, DISPLAY_NUM_6_PINS};

uint32_t segments[3][10] = {
    {0, DISPLAY_1_NUM_1, 0, 0, 0, 0, 0, 0, 0, 0},
    {DISPLAY_2_NUM_0, DISPLAY_2_NUM_1, DISPLAY_2_NUM_2, DISPLAY_2_NUM_3, DISPLAY_2_NUM_4, 
        DISPLAY_2_NUM_5, DISPLAY_2_NUM_6, DISPLAY_2_NUM_7, DISPLAY_2_NUM_8, DISPLAY_2_NUM_9},
    {DISPLAY_3_NUM_0, DISPLAY_3_NUM_1, DISPLAY_3_NUM_2, DISPLAY_3_NUM_3, DISPLAY_3_NUM_4, 
        DISPLAY_3_NUM_5, DISPLAY_3_NUM_6, DISPLAY_3_NUM_7, DISPLAY_3_NUM_8, DISPLAY_3_NUM_9}
};

DisplayStag6::DisplayStag6(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF) { 
    pins[0] = pinA;
    pins[1] = pinB;
    pins[2] = pinC;
    pins[3] = pinD;
    pins[4] = pinE;
    pins[5] = pinF;
}

void DisplayStag6::begin() {
    clearPins();
    currentSegment = 0;
    displayBits = 0;
}

void DisplayStag6::set(int value) {
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

void DisplayStag6::setNumber(int value) {
    displayBits &= (~DISPLAY_NUMBERS_BITMASK);
    switch(value) {
        case 1:
            displayBits |= DISPLAY_NUM_1_BITMASK;
            break;
        case 2:
            displayBits |= DISPLAY_NUM_2_BITMASK;
            break;
        case 3:
            displayBits |= DISPLAY_NUM_3_BITMASK;
            break;
        case 4:
            displayBits |= DISPLAY_NUM_4_BITMASK;
            break;
        case 5:
            displayBits |= DISPLAY_NUM_5_BITMASK;
            break;
        case 6:
            displayBits |= DISPLAY_NUM_6_BITMASK;
            break;
    }
}

void DisplayStag6::thunderOn() {
    displayBits |= DISPLAY_THUNDER_BITMASK;
}

void DisplayStag6::dropletOn() {
    displayBits |= DISPLAY_DROPLET_BITMASK;
}

void DisplayStag6::thunderOff() {
    displayBits &= (~DISPLAY_THUNDER_BITMASK);
}

void DisplayStag6::dropletOff() {
    displayBits &= (~DISPLAY_DROPLET_BITMASK);
}

void DisplayStag6::update() { 
    clearPins();

    currentSegment++;
    if(currentSegment >= 24) {
        currentSegment = 0;
    }

    if(displayBits & ((1ul)<<currentSegment)){
        setSegment(currentSegment);
    }
}

void DisplayStag6::clearPins() {
    for(int i = 0; i < 6; i++) {
        pinMode(pins[i], INPUT);
        digitalWrite(pins[i], LOW);
    }
}

void DisplayStag6::setSegment(int segment){
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