/*
Barbara Compagnoni
P-Comp Fall 2014
Circuit 2: POTENTIOMETER

  Measure the position of a potentiometer and use it to
  control the blink rate of an LED. Turn the knob to make
  it blink faster or slower!

*/


int sensorPin = 0;    // The potentiometer is connected to
                      // analog pin 0                     
int ledPin = 13;      // The LED is connected to digital pin 13



void setup() // this function runs once 
{
  // Setup LED as an OUTPUT
  pinMode(ledPin, OUTPUT);
}


void loop() // this function runs repeatedly after setup() finishes
{

  int sensorValue; //stores the value of the potentiometer:

  sensorValue = analogRead(sensorPin);//set it to the value of the analog pin 0 

  // Now we'll blink the LED like in the first example, but we'll
  // use the sensorValue variable to change the blink speed

  digitalWrite(ledPin, HIGH);     // Turn the LED on

  delay(sensorValue);             // Pause for sensorValue
                                  // milliseconds
  
  digitalWrite(ledPin, LOW);      // Turn the LED off

  delay(sensorValue);             // Pause for sensorValue
                                  // milliseconds
}

