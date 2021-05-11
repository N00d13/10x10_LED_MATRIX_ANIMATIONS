//
// Includes some modified code from harj-the-dev's GauntletII project. His original code can be found here:
// https://github.com/meharjit/ledtable/tree/master/src/libs/SinzianaPanel
//
// This also includes modified code from other projects that are referenced when used
//
// Made by Matthew Kaye
// May 10, 2021
//
// Created for my LED Matrix 10x10 project
// This projects shuffles through animations, displaying effects such as plasmas, texts, light twinkles and others. In total it includes 11 cool animations.
//

#include <FastLED.h>
#include <FastLED_NeoMatrix.h>
#include <Adafruit_GFX.h>

#include "Plasma.cpp" //Plasma class file
#include "Lines.cpp" //Lines class file

#define DATA_PIN 6 //Pin used on arduino
#define WIDTH 10 //Width of matrix
#define HEIGHT 10 //Height of matrix
#define NUM_LEDS WIDTH * HEIGHT //Total size of matrix
#define BRIGHTNESS 50 //Brightness of the Matrix. Maximum is 255
#define FRAMES_PER_SECOND  120 //This is for the doMultipleAnimations method. A lower number is sloer animations

CRGB leds[NUM_LEDS];

FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(leds, 10, HEIGHT, WIDTH/10, 1, 
  NEO_MATRIX_BOTTOM     + NEO_MATRIX_LEFT +
    NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE + 
    NEO_TILE_BOTTOM + NEO_TILE_LEFT +  NEO_TILE_PROGRESSIVE);

const uint16_t colors[] = {//These are the colors of the text animation. Each is a different colour hue seperated by a comma.
  matrix->Color(253, 151, 36), matrix->Color(68, 197, 255), matrix->Color(218, 79, 251), matrix->Color(134, 251, 79) }; //Colour order: Orange, Turquoise, Purple, Light Green

int amountColours = 4; //change this int to the amount of colours you have added for the text
  
void setup() {
    //Sets up FastLed and matrix
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS); //Sets up FastLED strip. Change LED Strip as needed.
    matrix->begin(); //Sets up matrix
    matrix->setTextWrap(false);
    matrix->setBrightness(BRIGHTNESS);
    matrix->setTextColor(colors[0]);
}

void loop() { 
    // Loops through all animations. doMultipleAnimations() includes 7 animations. In total, there are 11 animations.
    //Difference between each block is the phrase spelled at the end
    doPlasma();
    doLines();
    doPlasma2();
    doMultipleAnimations();
    doSpellBadDays();
    
    doPlasma();
    doLines();
    doPlasma2();
    doMultipleAnimations();
    doSpellOfficeQuote();

    doPlasma();
    doLines();
    doPlasma2();
    doMultipleAnimations();
    doSpellSupraReference();

    doPlasma();
    doLines();
    doPlasma2();
    doMultipleAnimations();
    doSpellJonnyLonely();
}

void doPlasma() {
    Plasma plasma(leds, WIDTH, HEIGHT);
    plasma.start();
}

void doLines() {
    Lines lines(leds, WIDTH, HEIGHT);
    lines.start();
}

//doSpell is modified from the FastLED NeoMatrix example library "tiletest"

int x    = WIDTH;
int pass = 0;

void doSpellBadDays(){
  bool finishedSpelling = false;
  matrix->fillScreen(0);
  while (finishedSpelling == false){
     matrix->fillScreen(0);
     matrix->setCursor(x, 1);//change int to amount of tiles lowered from roof of matrix
     matrix->print(F("100 Bad Days Make 100 Good Stories")); //Phrase printed
     if(--x < -208) { 
        //     ^ Number of tiles theat need to be displayed across. Each letter is 5 tiles plus the space in between. 
        // If your phrase includes 10 letters then (10x6)= 60 and dont forget to change it to negative.
        // This gives an estimate so modify as needed. 
        x = matrix->width();
        if(++pass >= amountColours) pass = 0;
        matrix->setTextColor(colors[pass]);
        finishedSpelling = true;
     }
     matrix->show();
     delay(60); //Speed of text across screen
  }
}

void doSpellOfficeQuote(){
  bool finishedSpelling = false;
  matrix->fillScreen(0);
  while (finishedSpelling == false){
     matrix->fillScreen(0);
     matrix->setCursor(x, 1);//change int to amount of tiles lowered from roof of matrix
     matrix->print(F("Don't Ever, For Any Reason, Do Anything, To Anyone, For Any Reason, Ever, No Matter What, No Matter Where, Or Who, Or Who You Are With, Or Where You Are Going, Or Where You've Been, Ever, For Any Reason Whatsoever.")); //Phrase printed
     if(--x < -1284) { 
        //     ^ Number of tiles theat need to be displayed across. Each letter is 5 tiles plus the space in between. 
        // If your phrase includes 10 letters then (10x6)= 60 and dont forget to change it to negative.
        // This gives an estimate so modify as needed. 
        x = matrix->width();
        if(++pass >= amountColours) pass = 0;
        matrix->setTextColor(colors[pass]);
        finishedSpelling = true;
     }
     matrix->show();
     delay(60); //Speed of text across screen
  }
}

void doSpellSupraReference(){
  bool finishedSpelling = false;
  matrix->fillScreen(0);
  while (finishedSpelling == false){
     matrix->fillScreen(0);
     matrix->setCursor(x, 1);//change int to amount of tiles lowered from roof of matrix
     matrix->print(F("9  9  9  9  9  Amazing Game, So Much Better Than Its Predecessor")); //Phrase printed
     if(--x < -388) { 
        //     ^ Number of tiles theat need to be displayed across. Each letter is 5 tiles plus the space in between. 
        // If your phrase includes 10 letters then (10x6)= 60 and dont forget to change it to negative.
        // This gives an estimate so modify as needed. 
        x = matrix->width();
        if(++pass >= amountColours) pass = 0;
        matrix->setTextColor(colors[pass]);
        finishedSpelling = true;
     }
     matrix->show();
     delay(60); //Speed of text across screen
  }
}

void doSpellJonnyLonely(){
  bool finishedSpelling = false;
  matrix->fillScreen(0);
  while (finishedSpelling == false){
     matrix->fillScreen(0);
     matrix->setCursor(x, 1);//change int to amount of tiles lowered from roof of matrix
     matrix->print(F("Day 6,795 Of Jonny Without A Girlfriend :(")); //Phrase printed
     if(--x < -255) { 
        //     ^ Number of tiles theat need to be displayed across. Each letter is 5 tiles plus the space in between. 
        // If your phrase includes 10 letters then (10x6)= 60 and dont forget to change it to negative.
        // This gives an estimate so modify as needed. 
        x = matrix->width();
        if(++pass >= amountColours) pass = 0;
        matrix->setTextColor(colors[pass]);
        finishedSpelling = true;
     }
     matrix->show();
     delay(60); //Speed of text across screen
  }
}

//doPlasma2 is modified from LDIRKO's Pastbin code found at this link: https://pastebin.com/6xT72A46

void doPlasma2(){
  int plasmaBrightness = 240; //The brightness is lower for doPlasma2. Change the added amount to BRIGHTNESS to your desire.
  int plasmaSpeed = 7; //Speed that the plasma changes colours, larger is slower  
  for (uint16_t time = 0, cycles = 0; cycles < 6521; time += 128, cycles++) { //Cycle is amount of time the animations runs. This runs for ~60 seconds
    uint16_t ms = millis();
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
        uint8_t index = inoise8(i * 41, j * 41, ms / plasmaSpeed);  // x and y not change, only change z value with time increment for nice plasma looking noise original 4
        leds[XYNumberFind (i, j)] = CHSV((index + ms / 200) % 255, 255, plasmaBrightness); // within palette
      }
    }
    FastLED.delay(1);
  }
  FastLED.clear(); //clears matrix for next animation
}

uint8_t XYNumberFind(uint8_t x, uint8_t y) { return (y * WIDTH + x);}    //Function to find LED coordinates in LED matrix, 

//Next Part is for the multiple animations that are meshed together
//It is a modified version of the FASTLED example library, "DemoReal100"

typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = {rainbow, rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm };

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void doMultipleAnimations(){
  gCurrentPatternNumber = 0; // resets the parttern number to 0 every time doMultipleAnimations is called
  bool animationsFinished = false;
  int amountAnimations = 0;
  while(animationsFinished == false){
    gPatterns[gCurrentPatternNumber]();
    // send the 'leds' array out to the actual LED strip
    FastLED.show();  
    // insert a delay to keep the framerate modest
    FastLED.delay(1000/FRAMES_PER_SECOND); 
    // do some periodic updates
    EVERY_N_MILLISECONDS( 20 ) { gHue++; } // cycles the base color through the rainbow
    EVERY_N_SECONDS( 25 ){ // changes animation every n seconds
      nextPattern(); 
      amountAnimations++;
    } 
    if(amountAnimations == 7){
      animationsFinished = true;
    }
  }
  FastLED.clear(); //clears matrix for next animation
}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}

void rainbow() 
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}

void rainbowWithGlitter() 
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void addGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void confetti() 
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16( i+7, 0, NUM_LEDS-1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}
