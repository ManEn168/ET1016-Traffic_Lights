//Name:Leecia, Man En
//Admin No : 2517254,2516576
//CLASS: DCEP/FT/A1/09
//

#include <Wire.h>
#include "RichShieldTM1637.h"
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
#define CLK 10//CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
#define DIO 11//DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK,DIO);
#define KNOB_PIN A2

int LEDS[5] = {4, 5, 6, 7}; //array for leds

void setup() 
{
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
