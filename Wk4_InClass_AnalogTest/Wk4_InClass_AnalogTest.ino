//Barbara Compagnoni & Nadine Razzouk
//P-Comp 
//Fall 2014
//In Class Assignment : Analog in for motors

void setup() {
  Serial.begin(9600);       // initialize serial communications
}
 
void loop()
{
  int analogValue = analogRead(A0); // read the analog input
  Serial.println(analogValue);      // print it
}
