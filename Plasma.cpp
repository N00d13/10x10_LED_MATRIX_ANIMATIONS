//
// Modified code from harj-the-dev's GauntletII project. His original code can be found here:
// https://github.com/meharjit/ledtable/tree/master/src/libs/SinzianaPanel
//
// Made by Matthew Kaye
// May 10, 2021
//
// Created for my LED 10x10 project
//

#import "Effect.h"

class Plasma : public Effect {
    
public:


// This section created an array with the led array coordinates. Can be modified to any matrix arrangment with this XY map generator:
// https://macetech.github.io/FastLED-XY-Map-Generator/

    const uint8_t kMatrixWidth = 10;
    const uint8_t kMatrixHeight = 10;

    #define NUM_LEDS (kMatrixWidth * kMatrixHeight)
    #define LAST_VISIBLE_LED 99

    uint8_t XY (uint8_t x, uint8_t y) {
        if ( (x >= kMatrixWidth) || (y >= kMatrixHeight) ) {
          return (LAST_VISIBLE_LED + 1);
        }
      
        const uint8_t XYTable[] = {
           9,  10,  29,  30,  49,  50,  69,  70,  89,  90,
           8,  11,  28,  31,  48,  51,  68,  71,  88,  91,
           7,  12,  27,  32,  47,  52,  67,  72,  87,  92,
           6,  13,  26,  33,  46,  53,  66,  73,  86,  93,
           5,  14,  25,  34,  45,  54,  65,  74,  85,  94,
           4,  15,  24,  35,  44,  55,  64,  75,  84,  95,
           3,  16,  23,  36,  43,  56,  63,  76,  83,  96,
           2,  17,  22,  37,  42,  57,  62,  77,  82,  97,
           1,  18,  21,  38,  41,  58,  61,  78,  81,  98,
           0,  19,  20,  39,  40,  59,  60,  79,  80,  99
        };
      
        uint8_t i = (y * kMatrixWidth) + x;
        uint8_t j = XYTable[i];
        return j;
    }

    int getX (uint8_t i){
      int j = i/10;
      int k = 0;
      if (i<100){
          k = i - (j*10);
      } else {
          k = 10;
      }
      return k;
    }

    int getY (uint8_t i){
      int j = i/10;
      return j;
    }
    
    Plasma(CRGB *leds, int width, int height) : Effect(leds, width, height) {
    }
    
    void start() {
        for (uint16_t time = 0, cycles = 0; cycles < 2608; time += 128, cycles++) { //Cycle is amount of time the animation runs. A higher number is a longer runtime for the animation. This runs for ~30 seconds
          //Should be a number divisable by 256 so animations resets without interupption
            calcFrame(time);
        }
        LEDS.clear();
    }
    //sin(distance(x, y, (128 * sin(-t) + 128), (128 * cos(-t) + 128)) / 40.74)s
    // v = sin(10 * (x * sin(time / 2) + y * cos(time / 3)) + time)
    
    void calcFrame(int time) {
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                int16_t v = 0;
                uint16_t wibble = sin8(time);
                v += sin16(x * wibble * 8 + time);
                v += cos16(y * (128 - wibble) * 4 + time);
                v += sin16(y * x * cos8(-time) / 2);

                
                uint16_t ledLocation = XY(x,y);
                int xLocation = getX(ledLocation);
                int yLocation = getY(ledLocation);
                
                pixel(xLocation, yLocation) = CHSV((v >> 8) + 127, 255, 255);
            }
        }
        LEDS.show();
        
    }
    
    uint8_t sin8(uint16_t x) {
        return (sin16(x) >> 8) + 128;
    }
    
    uint8_t cos8(uint16_t x) {
        return (cos16(x) >> 8) + 128;
    }

};
