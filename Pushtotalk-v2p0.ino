// This is Dafydd's push to talk code.


// #include <Keyboard.h>
#include "HID-Project.h"

void setup() {
  // make pin 2 an input and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  
  //const int pinLed = LED_BUILTIN;
  const int pinLed = 9;
  pinMode(2, INPUT_PULLUP); //PTT
  pinMode(pinLed, OUTPUT);
  pinMode(6, INPUT_PULLUP); //Volume Down Button
  pinMode(3, INPUT_PULLUP); //Volume Down Button
  
  
  digitalWrite(pinLed, LOW); // sets the PTTLED OFF
  // initialize control over the keyboard:
  Keyboard.begin();
  Consumer.begin();
}



void loop() {
  const int pinLed = 9;
  while ( (digitalRead(2) == HIGH) && (digitalRead(5) == HIGH) ) {
    // do nothing until pin 2 or pin 5 goes low
  }
  
  if (digitalRead(2) == LOW) {
  // send and hold CTRL, SHIFT, L
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('l');
  digitalWrite(pinLed, HIGH); // sets the digital pin 13 on
  }
  
  if (digitalRead(3) == LOW) {
  Consumer.write(MEDIA_VOLUME_UP);
  digitalWrite(pinLed, HIGH); // sets the digital pin 13 on
  }

  if (digitalRead(6) == LOW) {
  Consumer.write(MEDIA_VOLUME_DOWN);
  digitalWrite(pinLed, HIGH); // sets the digital pin 13 on
  }

  
  // Finally released
  delay (150);
  Keyboard.releaseAll();  
  digitalWrite(9, LOW); // sets the PTTLED OFF
}
