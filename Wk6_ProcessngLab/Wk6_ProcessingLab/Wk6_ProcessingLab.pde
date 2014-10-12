import processing.serial.*; // import the Processing serial library
Serial myPort;              // The serial port

float fgcolor = 0;               // Fill color defaults to black
float xpos, ypos;            // Starting position of the ball
 

void setup() {
  
  //window size
  size(800, 600);
  
  // List all the available serial ports
  println(Serial.list());
 
  // I know that the first port in the serial list on my computer
  // is always my  Arduino module, so I open Serial.list()[0].
  // Change the 0 to the appropriate number of the serial port
  // that your microcontroller is attached to.
  String portName = "/dev/tty.usbmodem1411";
  myPort = new Serial(this, portName, 9600);
  
    // read incoming bytes to a buffer
  // until you get a linefeed (ASCII 10):
  myPort.bufferUntil('\n');
  
  background(#081640);
}

void draw() {
  background(#243780); // blue background
 fill(fgcolor);
 // Draw the shape
 ellipse(xpos, ypos, 20, 20);
}


void serialEvent(Serial myPort) {
  // read the serial buffer:
  String myString = myPort.readStringUntil('\n');
  if (myString != null) {
    println(myString);
  }
  
  myString = trim(myString);
 
// split the string at the commas
// and convert the sections into integers:
int sensors[] = int(split(myString, ','));

for (int sensorNum = 0; sensorNum < sensors.length; sensorNum++) {
  print("Sensor " + sensorNum + ": " + sensors[sensorNum] + "\t");
}
// add a linefeed at the end:
println();

// make sure you've got all three values:
 if (sensors.length > 1) {
      xpos = sensors[0];
      ypos = sensors[1];
      // the pushbutton will send 0 or 1.
      // This converts them to 0 or 255:
      fgcolor = sensors[2] * 255;
    }
    xpos = map(sensors[0], 0,60,0,width);
ypos = map(sensors[1], 0,60,0,height);
}
