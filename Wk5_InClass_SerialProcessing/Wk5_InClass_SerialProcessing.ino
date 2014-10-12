// Barbara Compagnoni
// P-Comp Fall 2014
// Week 5 In Class
//

void setup() {
  Serial.begin(9600);
}
 
void loop() {
 int analogValue = analogRead(A0)/4; // read the sensor value
 Serial.write(analogValue);          // send the value serially
                                     // as a binary value
     
}
