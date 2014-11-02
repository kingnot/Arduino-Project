/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
boolean ledStatus=false;
int led =13;
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if (results.value == 0xB2EEDF3D){
      if(ledStatus == false) {
        digitalWrite(led, HIGH);
        ledStatus=true;
      }
      else {
        digitalWrite(led, LOW);
        ledStatus=false;
      }
    }
    irrecv.resume(); // Receive the next value
  }
  delay(150);
}
