
//Name:Leccia, Man En
//Admin No : 2517254,2516576
//CLASS: DCEP/FT/A1/09
//

#include <Wire.h>
#include "RichShieldPassiveBuzzer.h"
#define PassiveBuzzerPin 3
PassiveBuzzer buz(PassiveBuzzerPin);

#define NOTE_M4  698
#define LED_RED 4
#define LED_GREEN 5
#define LED_BLUE 6
#define LED_YELLOW 7
#define BUTTONK1 8
#define BUTTONK2 9


void setup() {
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_BLUE,OUTPUT);
  pinMode(LED_GREEN,OUTPUT);
  pinMode(LED_YELLOW,OUTPUT);
  pinMode(BUTTONK1,INPUT_PULLUP);
  pinMode(BUTTONK2, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

}
