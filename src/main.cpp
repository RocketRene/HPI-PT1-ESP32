#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

#define NUM 30 // number of leds on the strip
#define PIN 15 // data pin connected to led strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {

}
