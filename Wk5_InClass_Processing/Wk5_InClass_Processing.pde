import processing.serial.*;

Serial myPort;

float xPos = 0;             // horizontal position of the graph



void setup(){
  //window size
  size(800, 600);
//  // List all the available serial ports
//  println(Serial.list());
  
//  // change the number below to match your port:
//  String portName = Serial.list()[6];
//  //or
  String portName = "/dev/tty.usbmodem1411";
  myPort = new Serial(this, portName, 9600);
  
   background(#081640);
}


void draw () {

  // nothing happens in draw.  It all happens in SerialEvent()
}

void serialEvent (Serial myPort) {
  // get the byte:
  float inByte = myPort.read();
  //map it to height
  float m = map (inByte, 0, 255, 0, 600);
  // print it:
  println(inByte);
  
  float yPos = height - m;
  // draw the line in a pretty color:
  stroke(#A8D9A7);
  line(xPos, height, xPos, height - m);
  
  // at the edge of the screen, go back to the beginning:
  if (xPos >= width) {
    xPos = 0;
    // clear the screen by resetting the background:
    background(#081640);
    }
  else {
    // increment the horizontal position for the next reading:
    xPos+= 0.5;
  }
}

