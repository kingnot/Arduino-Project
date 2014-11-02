/*
    Copyright Giuseppe Di Cillo (www.coagula.org)
    Contact: dicillo@coagula.org
    
    Modified by R. Bigelow to work with a Joystick.
    Plug joystick Y Axis into A0, and X-Axis into A1
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

IMPORTANT: to use the menubackend library 
by Alexander Brevig download it at http://www.arduino.cc/playground/uploads/Profiles/MenuBackend_1-4.zip 
*/
#include <MenuBackend.h>    //MenuBackend library - copyright by Alexander Brevig
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
//this library is included in the Arduino IDE

int lastButtonPushed = 0;
int lastButtonEnterState = LOW;   // the previous reading from the Enter input pin
int lastButtonEscState = LOW;   // the previous reading from the Esc input pin
int lastButtonLeftState = LOW;   // the previous reading from the Left input pin
int lastButtonRightState = LOW;   // the previous reading from the Right input pin

long lastEnterDebounceTime = 0;  // the last time the output pin was toggled
long lastEscDebounceTime = 0;  // the last time the output pin was toggled
long lastLeftDebounceTime = 0;  // the last time the output pin was toggled
long lastRightDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 300;    // the debounce time

int joystickX = A0; 
int joystickY = A1; 
int buttonInX;
int buttonInY;



#define I2C_ADDR    0x27  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

LiquidCrystal_I2C	lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);


//Menu variables
MenuBackend menu = MenuBackend(menuUsed,menuChanged);
//initialize menuitems
    MenuItem menu1Item1 = MenuItem("Item1");
      MenuItem menuItem1SubItem1 = MenuItem("Item1SubItem1");
      MenuItem menuItem1SubItem2 = MenuItem("Item1SubItem2");
    MenuItem menu1Item2 = MenuItem("Item2");
      MenuItem menuItem2SubItem1 = MenuItem("Item2SubItem1");
      MenuItem menuItem2SubItem2 = MenuItem("Item2SubItem2");
      MenuItem menuItem3SubItem3 = MenuItem("Item2SubItem3");
    MenuItem menu1Item3 = MenuItem("Item3");

void setup()
{
  lcd.begin(16, 2);

  menu.getRoot().add(menu1Item1);
  menu1Item1.addRight(menu1Item2).addRight(menu1Item3);
  menu1Item1.add(menuItem1SubItem1).addRight(menuItem1SubItem2);
  menu1Item2.add(menuItem2SubItem1).addRight(menuItem2SubItem2).addRight(menuItem3SubItem3);
 
  menu.toRoot();
  lcd.setCursor(0,0); 
   lcd.print("Super Menu!"); 
}  

void loop()
{
  readButtons();  //I splitted button reading and navigation in two procedures because 
  navigateMenus();  //in some situations I want to use the button for other purpose (eg. to change some settings)                 
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
} 

void menuChanged(MenuChangeEvent changed){
  
  MenuItem newMenuItem=changed.to; //get the destination menu  
  lcd.setCursor(0,1); //set the start position for lcd printing to the second row
  
  if(newMenuItem.getName()==menu.getRoot()){
      lcd.print("Main Menu       ");
  }else if(newMenuItem.getName()=="Item1"){
      lcd.print("Volume           ");
  }else if(newMenuItem.getName()=="Item1SubItem1"){
      lcd.print("Vol Up    ");
      //Do something here
  }else if(newMenuItem.getName()=="Item1SubItem2"){
      lcd.print("Vol Down   ");
  }else if(newMenuItem.getName()=="Item2"){
      lcd.print("Item2           ");
  }else if(newMenuItem.getName()=="Item2SubItem1"){
      lcd.print("Item2SubItem1   ");
  }else if(newMenuItem.getName()=="Item2SubItem2"){
      lcd.print("Item2SubItem2   ");
  }else if(newMenuItem.getName()=="Item2SubItem3"){
      lcd.print("Item2SubItem3   ");
  }else if(newMenuItem.getName()=="Item3"){
      lcd.print("Item3           ");
  }
}

void menuUsed(MenuUseEvent used){
  lcd.setCursor(0,0);  
  lcd.print("You used        ");
  lcd.setCursor(0,1); 
  lcd.print(used.item.getName());
  delay(3000);  //delay to allow message reading
  menu.toRoot();  //back to Main
  lcd.setCursor(0,0); 
  lcd.print("Super Menu!"); 
}

void  readButtons(){  //read buttons status
 //Allow for time to debounce
  if ((millis() - lastEnterDebounceTime) > debounceDelay) {
                  lastEnterDebounceTime=millis();
  buttonInX = analogRead(joystickX);     // read ADC value
  buttonInY = analogRead(joystickY);     // read ADC value
  
if(buttonInX < 20){
 //   You are pushing Left
 lastButtonPushed = 3;
 }else if(buttonInX >1000){
 // You are pushing right
 lastButtonPushed = 0;
 } else if (buttonInY < 20){
  // You are pressing Down
 lastButtonPushed = 2;
 }else if(buttonInY > 1000){
 // You are pressing up
 lastButtonPushed = 1;
 }else{
   //No button was pushed.
 lastButtonPushed =-1;
 }
}
}

void navigateMenus() {
  MenuItem currentMenu=menu.getCurrent();
  
  switch (lastButtonPushed){
    case 0:
      if(!(currentMenu.moveDown())){  //if the current menu has a child and has been pressed enter then menu navigate to item below
        menu.use();
      }else{  //otherwise, if menu has no child and has been pressed enter the current menu is used
        menu.moveDown();
       } 
      break;
    case 1:
      menu.moveLeft();
      break; 
    case 2:
      menu.moveRight();
      break;      
    case 3:
      menu.moveUp();
      break;
    case 4:
      menu.toRoot();  //back to main
      break; 
  }
  
  lastButtonPushed=-1; //reset the lastButtonPushed variable
}







