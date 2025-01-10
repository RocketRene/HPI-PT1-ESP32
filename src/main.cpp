#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <algorithm>

#define NUM 28 // number of leds on the strip
#define PIN 15 // data pin connected to led strip
#define LOUDSPEAKER_PIN 4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM, PIN, NEO_GRB + NEO_KHZ800);

byte colors[NUM];
int n = NUM;

int min_freq = 330;
int max_freq = 880;

uint32_t c1 = 0xff << 16;
uint32_t c2 = 0x00328f; //0xff << 8;
uint32_t c3 = 0x26bb00; //0xff;

uint32_t interpolate(uint32_t c1, uint32_t c2, float ratio) {
  byte r1 = (c1 >> 16) & 0xFF;
  byte g1 = (c1 >> 8) & 0xFF;
  byte b1 = c1 & 0xFF;

  byte r2 = (c2 >> 16) & 0xFF;
  byte g2 = (c2 >> 8) & 0xFF;
  byte b2 = c2 & 0xFF;

  byte r = r1 + ((r2 - r1) * ratio);
  byte g = g1 + ((g2 - g1) * ratio);
  byte b = b1 + ((b2 - b1) * ratio);

  return (r << 16) | (g << 8) | b;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  float ratio = (WheelPos % 85 * 3) / 255.0;
  //WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    //return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    return interpolate(c1, c2, ratio);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    //return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    return interpolate(c2, c3, ratio);
  }
  WheelPos -= 170;
  //return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  return interpolate(c3, c1, ratio);
}

void updateStrip() {
  for(int i = 0; i < NUM; i++) {
    strip.setPixelColor(i, Wheel(colors[i]));
  }
  strip.show();
}

void playFrequency(byte WheelPos) {
  int note = min_freq + (WheelPos * (max_freq - min_freq)) / 255;
  long duration = 60;
  if(note == 0) {
      delay(duration); // For rests, just wait for the duration
      return;
  }
  
  long waitTime = 1000000 / (2 * note);
  for(int i = 0; i < duration * note / 1000; i++) {
    digitalWrite(LOUDSPEAKER_PIN, HIGH);
    delayMicroseconds(waitTime);
    digitalWrite(LOUDSPEAKER_PIN, LOW);
    delayMicroseconds(waitTime);
  }
}


void setup() {
  pinMode(LOUDSPEAKER_PIN, OUTPUT);
  strip.setBrightness(100);
  for(int i = 0; i < NUM; i++) {
    colors[i] = 256 * (i) / strip.numPixels();
  }

  std::random_shuffle(colors, colors + NUM - 1);

  strip.begin();
  updateStrip();
}

void loop() {
  if(n < 2) {
    for(int i = 0; i < NUM; i++) {
      playFrequency(colors[i]);
      delay(10);
    }
    delay(10000);
    std::random_shuffle(colors, colors + NUM - 1);
    n = NUM;
    updateStrip();
    return;
  };
  
	for(byte *a = colors, *b = colors + 1; b < colors + n; a++, b++) {
		if(*a > *b) {
      int temp = *a;
      *a = *b;
      *b = temp;
      updateStrip();
    }
    int color_to_play = *a;
    playFrequency(color_to_play);
    delay(20);
	}
  delay(200);
  n--;
}
