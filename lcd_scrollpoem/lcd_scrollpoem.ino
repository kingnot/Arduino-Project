/*
** Example Arduino sketch for SainSmart I2C LCD Screen 16x2
** based on https://bitbucket.org/celem/sainsmart-i2c-lcd/src/3adf8e0d2443/sainlcdtest.ino
** by
** Edward Comer
** LICENSE: GNU General Public License, version 3 (GPL-3.0)

** This example uses F Malpartida's NewLiquidCrystal library. Obtain from:
** https://bitbucket.org/fmalpartida/new-liquidcrystal 

** Modified – Ian Brennan ianbren at hotmail.com 23-10-2012 to support Tutorial posted to Arduino.cc

** Written for and tested with Arduino 1.0
**
** NOTE: Tested on Arduino Uno whose I2C pins are A4==SDA, A5==SCL

*/
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27 // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int screenWidth = 16;
int screenHeight = 2;

LiquidCrystal_I2C	lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

String line1 = "Love is not a thing to understand.    Love is not a thing to feel.    Love is not a thing to give and receive.    Love is a thing only to become    And eternally be.";
// the two lines
// line1 = scrolling

// line2 = static
String line2 = "LOVE by Chinmoy";

// just some reference flags
int stringStart, stringStop = 0;
int scrollCursor = screenWidth;

// most of the part is pretty basic
void setup() {
  lcd.begin(screenWidth,screenHeight);
  
  // Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();
}

void loop() {
  for (int i=0; i<5; i++) {
    lcd.setCursor(scrollCursor, 0);
    lcd.print(line1.substring(stringStart,stringStop));
    lcd.setCursor(0, 1);
    lcd.print(line2);
    delay(300);
    lcd.clear();
    if(stringStart == 0 && scrollCursor > 0){
      scrollCursor--;
      stringStop++;
    } else if (stringStart == stringStop) { //the last letter of the string
      stringStart = stringStop = 0;  //set substring back from the first
      scrollCursor = screenWidth;  //set cursor to (0, 16)
    } else if (stringStop >= line1.length() && scrollCursor == 0) {
      stringStart++;
    } else {
      stringStart++;
      stringStop++;
    }
  }
}
