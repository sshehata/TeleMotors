/*
  Reading a serial ASCII-encoded string.

 This sketch demonstrates the Serial parseInt() function.
 It looks for an ASCII string of comma-separated values.
 It parses them into ints, and uses those to fade an RGB LED.

 Circuit: Common-anode RGB LED wired like so:
 * Red cathode: digital pin 3
 * Green cathode: digital pin 5
 * blue cathode: digital pin 6
 * anode: +5V

 created 13 Apr 2012
 by Tom Igoe

 This example code is in the public domain.
 */

// pins for the LEDs:
int led = 13;
int save = 100;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  // make the pins outputs:

}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    save = Serial.parseInt() * 10;
  }
  
  digitalWrite(led, HIGH);
  delay(save);
  digitalWrite(led, LOW);
  delay(save);
}








