#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 150

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];
int r[NUM_LEDS];
int g[NUM_LEDS];
int b[NUM_LEDS];
int num;
int c;

void setup() { 
  num = 200;
  c=0;
  for(int i = 0; i < NUM_LEDS; i++) {
    r[i]=10;
    g[i]=10;
    b[i]=10; 
  }
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() { 
	// First slide the led in one direction
	for(int i = 0; i < NUM_LEDS; i++) {
		// Set the i'th led to red 
		//leds[i] = CRGB::Black;
                /*if(random8(2)<1)
                   r[i]=r[i]++;
                else
                   r[i]=r[i]--;
                if(random8(2)<1)
                   g[i]=g[i]++;
                else
                   g[i]=g[i]--;
                if(random8(2)<1)
                   b[i]=b[i]++;
                else
                   b[i]=b[i]--;   
                if(i < NUM_LEDS)
                  leds[i].r = r[i];
		  leds[i].g = g[i];
		  leds[i].b = b[i];
                */
		// Show the leds
		
		// now that we've shown the leds, reset the i'th led to black
		//j=NUM_LEDS-1-i;

                if(i < NUM_LEDS)
                  leds[i].r = random8();
		  leds[i].g = random8();
		  leds[i].b = random8();
                
		// Wait a little bit before we loop around and do it again
		//delay(num);
             
                //num = num % 150;
	}
        FastLED.show();
        delay(num);
        if(num>0)
           num--;
        else
           c++;
        if(c>2000){
           c=0;
           num=200; 
        }  
/*
	// Now go in the other direction.  
	for(int i = NUM_LEDS-1; i >= 0; i--) {
		// Set the i'th led to red 
		leds[i] = CRGB::Orange;
                if(i + num < NUM_LEDS)
                  leds[i + num] = CRGB::Pink;

                //if(i - 10 >= NUM_LEDS)
                //  leds[i - 10] = CRGB::Red;
		// Show the leds
		FastLED.show();
		// now that we've shown the leds, reset the i'th led to black
		leds[i] = CRGB::White;
                if(i + num < NUM_LEDS)
                  leds[i + num] = CRGB::White;
		// Wait a little bit before we loop around and do it again
		delay(15);
                num--;
                num = (num + 150) % 150;
	}*/
}
