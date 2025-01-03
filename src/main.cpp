#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <algorithm>

#define NUM 28 // number of leds on the strip
#define PIN 15 // data pin connected to led strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM, PIN, NEO_GRB + NEO_KHZ800);

int colors[NUM];
int n = NUM;

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void updateStrip() {
  for(int i = 0; i < NUM; i++) {
    strip.setPixelColor(i, Wheel(colors[i]));
  }
  strip.show();
}


void setup() {
  for(int i = 0; i < NUM; i++) {
    colors[i] = 256 * (i) / strip.numPixels();
  }

  std::random_shuffle(colors, colors + NUM - 1);

  strip.begin();
  updateStrip();
}

void loop() {
  if(n < 2) {
    delay(10000);
    std::random_shuffle(colors, colors + NUM - 1);
    n = NUM;
    return;
  };
  
	for(int *a = colors, *b = colors + 1; b < colors + n; a++, b++) {
    updateStrip();
    delay(200);
    
		if(*a > *b) {
      int temp = *a;
      *a = *b;
      *b = temp;
      updateStrip();
    }
    delay(200);
	}
  delay(1000);
  n--;
}
