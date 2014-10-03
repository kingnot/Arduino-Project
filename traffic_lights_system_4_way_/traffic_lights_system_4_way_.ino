 int buzzer=8;//Connect the buzzer Pin to Digital Pin 8  
 int NSgreenLed=9; //Connect North/South green LED to Digital Pin 9
 int NSyellowLed=10; //Connect North/South yellow LED to Digital Pin 10
 int NSredLed=11; //Connect North/South red LED to Digital Pin 11 
 int NSleftLed=12; //Connect North/South left LED to Digital Pin 12
 int WEgreenLed=1;//Connect West/East green LED to Digital Pin 1
 int WEyellowLed=2; //Connect West/East yellow LED to Digital Pin 2 
 int WEredLed=3; //Connect West/East red LED to Digital Pin 3
 int WEleftLed=4; //Connect West/East left LED to Digital pin 4
 
 int greenWait=8000; //green light delay time
 int leftWait=4000; //left light dealy time
 int yellowWait=2000; //yellow light dealy time
 int redWait=2000; //red light on time for 4 directions(buffering time)
 
void setup() 
{  //start of setup
  pinMode(buzzer,OUTPUT);//Set buzzer Pin Mode as output
  pinMode(NSgreenLed,OUTPUT);//Set North/South green ledPin as output 
  pinMode(NSyellowLed,OUTPUT);//Set North/South yellow ledPin as output 
  pinMode(NSredLed,OUTPUT);//Set North/South red ledPin as output  
  pinMode(NSleftLed,OUTPUT); //Set North/South left ledPin as output
  pinMode(WEgreenLed, OUTPUT);//Set West/East green ledPin as output
  pinMode(WEyellowLed, OUTPUT); //Set WE yellow ledPin as output
  pinMode(WEredLed, OUTPUT); //Set WE red ledPin as Output
  pinMode(WEleftLed, OUTPUT); //Set WE left ledPin as Output
}  //end of setup

void loop() 
{
   digitalWrite(NSredLed,HIGH); //Set N/S red LED to high
   digitalWrite(WEredLed,HIGH);  //Set W/E red LED to high
   delay(redWait); //red led delay 
   digitalWrite(WEredLed,LOW); //Set W/E red LED to low 
   
   /*West-East directions start to go from this point*/
   /*Start from the left turn traffic*/
   digitalWrite(WEleftLed,HIGH); //Set W/E left LED to high  
   delay(leftWait); //left led delay
   digitalWrite(buzzer,HIGH); //Start making a sound to warn the light switch
   delay(10); 
   digitalWrite(buzzer,LOW); //Stop making a sound
   digitalWrite(WEyellowLed,HIGH); //Set W/E yellow LED to high to warn the end of left turn priority 
   delay(yellowWait);
   digitalWrite(WEleftLed,LOW); //Set W/E left LED to low 
   digitalWrite(WEyellowLed,LOW); //Set W/E yellow LED to low
   
   digitalWrite(WEgreenLed,HIGH); //Set W/E green LED to high  
   delay(greenWait); //Green light on dealy 
   digitalWrite(WEgreenLed,LOW); //Set W/E green LED to low 
   
   digitalWrite(buzzer,HIGH); //Start making a sound to warn the light swich
   delay(10);  
   digitalWrite(buzzer,LOW); //Stop making a sound
   delay(400); 
   digitalWrite(buzzer,HIGH); //Start making a sound
   delay(10); 
   digitalWrite(buzzer,LOW); //Stop making a sound
   
   digitalWrite(WEyellowLed,HIGH); //Set W/E yellow LED to high  
   delay(yellowWait); 
   digitalWrite(WEyellowLed,LOW); //Set W/E yellow LED to low 
      
   digitalWrite(WEredLed,HIGH); //Set W/E red LED to high  
   delay(redWait); 
   digitalWrite(NSredLed,LOW); //Set N/S red LED to low   
   
   /*North-South directions start to go from this point*/
   /*Start from the left turn traffic*/   
   digitalWrite(NSleftLed,HIGH); //Set N/S left LED to high  
   delay(leftWait); 
   digitalWrite(buzzer,HIGH); //Start making a sound to warn the light switch
   delay(10); 
   digitalWrite(buzzer,LOW); //Stop making a sound
   digitalWrite(NSyellowLed,HIGH); //Set N/S yellow LED to high to warn the end of left turn priority
   delay(yellowWait);
   digitalWrite(NSleftLed,LOW); //Set N/S left LED to low
   digitalWrite(NSyellowLed,LOW); //Set N/S left LED to low
   
   digitalWrite(NSgreenLed,HIGH); //Set N/S green LED to high  
   delay(greenWait); //Green light on delay
   digitalWrite(NSgreenLed,LOW); //Set N/S green LED to low 
   
   digitalWrite(buzzer,HIGH); //Start making a sound to warn the light switch
   delay(10); 
   digitalWrite(buzzer,LOW); //Stop making a sound
   delay(400); 
   digitalWrite(buzzer,HIGH); //Start making a sound
   delay(10); 
   digitalWrite(buzzer,LOW); //Stop making a sound
   
   digitalWrite(NSyellowLed,HIGH); //Set N/S yellow LED to high  
   delay(yellowWait); //yellow led dealy 
   digitalWrite(NSyellowLed,LOW); //Set N/S yellow LED to low 
   
}//end of loop

