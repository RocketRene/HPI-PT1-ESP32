#include <Adafruit_NeoPixel.h>

#define NUM 30 // number of leds on the strip
#define PIN 15 // data pin connected to led strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM, PIN, NEO_GRB + NEO_KHZ800);
float t;

void setup() {
    strip.begin();
    strip.show();
    t = 0;
}

void loop() {
    float rainbowColorR = 0.0;
    float rainbowColorG = PI * 0.67;
    float rainbowColorB = PI * 1.33;

    float r = 0.5 + 0.5 * sin(rainbowColorR + t);
    r *= 255;
    float g = 0.5 + 0.5 * sin(rainbowColorG + t);
    g *= 255;
    float b = 0.5 + 0.5 * sin(rainbowColorB + t);
    b *= 255;

    for (int i = 0; i < NUM; i++) {
        strip.setPixelColor(i, r,g,b);
        strip.show();
        delay(10);
        strip.setPixelColor(i, 0, 0, 0);
    }
    for (int i = 0; i < NUM; i++) {
        strip.setPixelColor(NUM - i -1, r,g,b);
        strip.show();
        delay(10);
        strip.setPixelColor(NUM - i- 1, 0, 0, 0);
    }
    t += 0.1;
}