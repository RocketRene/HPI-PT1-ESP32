/* Task: Blinking onboard LED fib(n) times with 2 seconds pause*/
 
#include <Arduino.h>            // useful functions defined here
#include <stdio.h>
#define ONBOARD_LED_PIN 2       // use this to control onboard led
 
int fib(int n)
{
    int a = 1, b = a;
    for (; n > 2; n--)
    {
        b = a + b;
        a = b - a;
    }
    return b;
}

 
void setup(){
    pinMode(ONBOARD_LED_PIN, OUTPUT);
}
 
void loop(){
    for (int i = 0; i < 10; i++) {
        printf("%d", fib(i));
        for (int j = 0; j < fib(i); j++) {
            digitalWrite(ONBOARD_LED_PIN, HIGH);
            delay(200);
            digitalWrite(ONBOARD_LED_PIN, LOW);
            delay(200);
        }
        delay(2000);
    }
}