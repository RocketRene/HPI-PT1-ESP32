#include <Arduino.h>
#define ONBOARD_LED_PIN 2

int fib(int n)
{
    if (n <= 1) return n;  // Handle edge cases 0 and 1
    
    int a = 1, b = a;
    for (; n > 2; n--)
    {
        b = a + b;
        a = b - a;
    }
    return b;
}

void setup() {
    pinMode(ONBOARD_LED_PIN, OUTPUT);
    Serial.begin(9600);  // Initialize Serial communication at 9600 baud
}

void loop() {
    for (int i = 0; i < 10; i++) {
        int fibNumber = fib(i);
        Serial.print("Fibonacci(");
        Serial.print(i);
        Serial.print(") = ");
        Serial.println(fibNumber);  // Print the fibonacci number with newline
        
        for (int j = 0; j < fibNumber; j++) {
            digitalWrite(ONBOARD_LED_PIN, HIGH);
            delay(200);
            digitalWrite(ONBOARD_LED_PIN, LOW);
            delay(200);
        }
        delay(2000);
    }
}
