//Name:Leecia Ang Rui En, Ting Man En
//Admin No : 2517254,2516576
//CLASS: DCEP/FT/1A/09
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
#define NUM_LEDS 4
#define NUM_BUTTONS 2
#define BUTTONK1 8
#define BUTTONK2 9
#define CLK 10//CLK of the TM1637 IC connect to D10 of OPEN-SMART UNO R3
#define DIO 11//DIO of the TM1637 IC connect to D11 of OPEN-SMART UNO R3
TM1637 disp(CLK,DIO);
#define LDR A2

int i = 25, j=0, k=0, l=0, LDRValue, p=0;
int LEDS[5] = {4, 5, 6, 7}; //array for leds
int BUTTONS[3] = {8, 9}; //array for buttons

//Prototype
void blink(int led, int ms_delay);
void ONOFF (int led,int timewait);
void waiting (void);
void stickman(void);
void walking(void);
void humansensor(void);

void setup() 
{
  for(l = 0; l < NUM_LEDS; l++)
  pinMode (LEDS[l],OUTPUT);

  for(k = 0; k < NUM_BUTTONS; k++)
 pinMode(BUTTONS[k], INPUT_PULLUP);

  disp.init();//The initialization of the display
  Serial.begin(9400);
  stickman();
  walking();
  humansensor();
}

void loop() {
  digitalWrite(LEDS[0], HIGH); 
  stickman();
 if (digitalRead(BUTTONS[0]) == 0) // check if button K1 is pressed (logic 0 when pressed)
 {
  delay(300); // add a small delay to debounce the button

 //Blue Button (Normal) 
  int ms_time;
  waiting();
 
  digitalWrite(LEDS[1], HIGH);
  delay(100);
    for(i = 25; i > 5; i --)
  {
   disp.display(i);//Display integer
   delay (1000);

   if(i==25)
   {
    Serial.println("3...2....1...");
    Serial.println("READY GOOOO!!!!!");
   }
   walking();
   digitalWrite(LEDS[1], HIGH);  // turn the LED on (HIGH is the voltage level)
  }
  
for(i = 5; i > 0; i --)
{
   disp.display(i);//Display integer
 for (j=1;j <= 5;j++)
 {
  blink (LEDS[1],30);
  delay(100);
  buz.playTone (698,100);
  delay(50);
  }
}
  disp.display(0);
  for(p=0;p<100;p++)
  {
  humansensor();
  }
  stickman();
  digitalWrite(LEDS[0], HIGH);
  while (digitalRead(BUTTONS[0]) == 0);/*Ensure the button is released (i.e. back to logic 1) before executing the next statement */
 } 

 

 //Yellow Button (Handi)
 if (digitalRead(BUTTONS[1]) == 0) // check if button K1 is pressed (logic 0 when pressed)
 {
  delay(300); // add a small delay to debounce the button
  
  int ms_time;
  waiting();
  digitalWrite(LEDS[1], HIGH);
  delay(100);

    for(i = 40; i > 5; i --)
  {
   disp.display(i);//Display integer
   delay (1000);
  if(i==40)
  {
  Serial.println("3...2....1...");
  Serial.println("READY GOOOO!!!!!");
  }
   walking();
   digitalWrite(LEDS[1], HIGH);  // turn the LED on (HIGH is the voltage level)
  } 
  
  for(i = 5; i > 0; i --)
  {
  disp.display(i);//Display integer

  for (j=0;j<=5;j++)
  {
   blink (LEDS[1],30);
   delay(100);
   buz.playTone (698,100);
   delay(100);
  }
  }
  disp.display(0);
  stickman();
  for(p=0;p<200;p++)
  {
  humansensor();
  }
  stickman();
  digitalWrite(LEDS[0], HIGH);
  digitalWrite(LEDS[1], LOW);
  while (digitalRead(BUTTONS[1]) == 0);/*Ensure the button is released (i.e. back to logic 1) before executing the next statement */
 } 
 }


//Implementation
void blink(int led, int ms_delay)
{
  digitalWrite(led, HIGH); // turn a LED on (HIGH is the voltage level)
  delay(ms_delay); // wait for ? millisecond
  digitalWrite(led, LOW); // turn a LED off by making the voltage LOW
  delay(ms_delay); // wait for ? millisecond

  // you may add more program statements to turn ON/OFF other LEDs
  return;
}

void ONOFF (int led,int timewait)
{
digitalWrite(led,HIGH);
delay(timewait);
digitalWrite(led,LOW);
return;
}
void waiting (void)
{
  digitalWrite(LEDS[3], HIGH);
  ONOFF(LEDS[0], 1200); 
  ONOFF(LEDS[2], 350);
  digitalWrite(LEDS[3], LOW);
  return;
}

void stickman(void)
{
   Serial.println("RED LIGHT!!!!!!! PLS STOP!!!!");
   Serial.println("          o  ");
   Serial.println("         /|\\ ");
   Serial.println("         | | ");
   return;
}

void walking(void)
 {
   Serial.println("          o  ");
   Serial.println("         /|\\ ");
   Serial.println("         / \\ ");
   Serial.println("                  o  ");
   Serial.println("                 /|\\ ");
   Serial.println("                  |\\ ");
   Serial.println("          o  ");
   Serial.println("         /|\\ ");
   Serial.println("         / \\ ");
   Serial.println("  o  ");
   Serial.println(" /|\\ ");
   Serial.println(" /|  ");
   return;
  } 

void humansensor(void)
 {
  LDRValue=analogRead(LDR);
  Serial.print("LDR value :");
  Serial.println(LDRValue);

   if (LDRValue < 1023 && LDRValue >= 0)  // Threshold value - adjust as needed
  {
    
    digitalWrite(LEDS[1], HIGH);  // Green LED ON
    
  }
  else
  {
    digitalWrite(LEDS[1], LOW);
    digitalWrite(LEDS[0], HIGH); 
  }
    return;
 }
