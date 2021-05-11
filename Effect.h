//
// Modified code from harj-the-dev's GauntletII project. His original code can be found here:
// https://github.com/meharjit/ledtable/tree/master/src/libs/SinzianaPanel
//
// Made by Matthew Kaye
// May 10, 2021
//
// Created for my LED 10x10 project
//


#ifndef Effect_h
#define Effect_h

#import <FastLED.h>

class Effect {

    protected:
        CRGB *leds;
        int width, height;
    
        struct CRGB& pixel(int x, int y);
        bool inXRange(int x);
        bool inYRange(int y);
    
        void clearLeds();

    public:
        Effect(CRGB *leds, int width, int height);

        virtual void start() {};

};

#endif
