This code was created for my 10x10 LED Matrix Project and includes 11 cool animations.
I worked off many other projects and modified their code to fit my criteria for the project.
Links to other's original code can be found within the Arduino files.

I used an Arduino Nano and a WS2812B led strip, cut and soldered into different cubes behind an acrylic panel, used as a diffuser.
The map of the lights are below, 0 being the beggining and 99 being the end:

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

The code can be probably used with larger or smaller matrixes, but I have not tested this myself.
If you follow the comments of the code, you can probably get it working with different sizes.

This project uses the FastLED library and therefore supports numerous other light strips as well.
If you have any questions, send me an email at mpkaye3@gmail.com and I'll be happy to explain any problems you have.

Here is a link to my YouTube showing all the animations: https://www.youtube.com/watch?v=P4drH6RNNtU

Enjoy!

Created by Matthew Kaye
May 10, 2021
