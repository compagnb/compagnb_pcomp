/*
  Barbara Compagnoni
  P-Comp Fall 2014
  Circuit 1: Blink
  
  Turns on an LED on for one second, then off for one second, repeatedly.
  This example code is in the public domain.
 */
 
// Connects the LED var to pin 13.
int led = 13;

// the setup runs once 
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level - 5V)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW - 0V
  delay(1000);               // wait for a second
}
