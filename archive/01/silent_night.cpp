#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

#include "silent_night.h"
//#include "tetris.h"

/* The melody and rhythm are defined in the header above. */
int const melody[] = MELODY; //contains the notes frequencies

/* rhythm[] contains the notes durations in multiples of the shortest duration
 * so a 2 should be played two times longer than a 1 an a 3 three times as long
 * e.g. if the smalles note value in the song is a quarter note each 1 is a quarter note and each 2 is a half note (<- important if you want to code your own music)
 */
int const rhythm[] = RHYTHM;

/********************************************************/
#define LOUDSPEAKER_PIN 4
/********************************************************/

void play(int note, long duration) { // a long is an int but can contain larger numbers
  if (note == 0) {
    delay(duration); // For rests, just wait for the duration
    return;
  }
  
  /********************************************************/
  /* The variable note gives you a frequency in Hz.
     The variable duration is given in milliseconds.
    
     TODO:
     3.) Generate a rectangular wave with the given
     frequency and duration.
     To do so, change the value at the loudspeaker pin
     to HIGH and to LOW for a sufficient number of
     times and wait an appropriate time after you set
     each value.

     Hint: Think about the resolutions you need!
     You may want to use more percise functions.
  */
  long waitTime = 1000000 / (2 * note);
  for (int i = 0; i < duration * note / 1000; i++) {
    digitalWrite(LOUDSPEAKER_PIN, HIGH);
    delayMicroseconds(waitTime);
    digitalWrite(LOUDSPEAKER_PIN, LOW);
    delayMicroseconds(waitTime);
  }

  delay(10);

  /********************************************************/
}

/* the setup routine runs once when you press reset: */
void setup() {
  pinMode(LOUDSPEAKER_PIN, OUTPUT);
}

/* the loop routine runs over and over again forever: */
void loop() {
  /********************************************************/
  /* TODO:
     2.) Look at the included melody.
     How can you determine how long it is?

     Call play(int, long) with each note in the melody.
     Play the shortest note for 200ms. 

     BONUS:
     calculate duration of shortest note, given: 
      - beats per minute 
      - ratio of
        - length of one beat (e.g. quarter, eighth, sixteenth)
        - the shortest note of the song
        when beat is a quarter note long and shortest note is an eighth, this should be 1/2
    )
  */
  int len = 0;
  while(melody[len] != -1) {
    len++;
  }

  for (int i = 0; i < len; i++) {
    play(melody[i], rhythm[i] * 200);
  }


  /********************************************************/
}


