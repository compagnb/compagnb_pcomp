//Barbara Compagnoni
//P-Comp
//Fall 2014
//Homework Week 3: Combination Lock Light

const int ledPin = 7; //led pin
int flexValue = 0; //flex pin
int buttonPin = 8; //button pin
float voltage;

void setup() {
    // initialize serial communications at 9600 bps:
    Serial.begin(9600);
    // declare the led pin as an output:
    pinMode(ledPin, OUTPUT);
    //declare the button pin as an input:
    pinMode(buttonPin, INPUT);
}

void loop() {
    flexValue = analogRead(A5);    // read the flex value
    
    voltage = map(flexValue, 0, 1023, 0, 5); //map it to voltage
    
    // read the switch input:
   if ((digitalRead(buttonPin) == HIGH) && (voltage > 0) ) {
     // if the switch is closed:
     digitalWrite(ledPin, HIGH);    // turn on 
   }
   else {
     // if the switch is open:
     digitalWrite(ledPin, LOW);     // turn off 
   }
   
   Serial.println(voltage); 
     
}
