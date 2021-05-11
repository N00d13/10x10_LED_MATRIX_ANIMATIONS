//
// Modified code from harj-the-dev's GauntletII project. His original code can be found here:
// https://github.com/meharjit/ledtable/tree/master/src/libs/SinzianaPanel
//
// Made by Matthew Kaye
// May 10, 2021
//
// Created for my LED 10x10 project
//

#include "Effect.h"

Effect::Effect(CRGB *leds, int width, int height): leds(leds), width(width), height(height) {}

bool Effect::inXRange(int x) {
    return x >= 0 && x < width;
}

bool Effect::inYRange(int y) {
    return y >= 0 && y < height;
}

struct CRGB& Effect::pixel(int x, int y) {
    if (y & 1) {
        return leds[(y * width) + width - x - 1];
    } else {
        return leds[(y * width) + x];
    }
}

void Effect::clearLeds() {
    memset8(leds, 0, width * height * 3);
}
