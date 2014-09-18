 int buzzer=8;//Connect the buzzer Pin to Digital Pin 8  
 int NSgreenLed=9; //Connect North/South green LED to Digital Pin 9
 int NSyellowLed=10; //Connect North/South yellow LED to Digital Pin 10
 int NSredLed=11; //Connect North/South red LED to Digital Pin 11 
 int WEgreenLed=1;//Connect West/East green LED to Digital Pin 1
 int WEyellowLed=2; //Connect West/East yellow LED to Digital Pin 2 
 int WEredLed=3; //Connect West/East red LED to Digital Pin 1
 
void setup() 
{  //start of setup
  pinMode(buzzer,OUTPUT);//Set Pin Mode as output
  pinMode(NSgreenLed,OUTPUT);//Set North/South green ledPin as output 
  pinMode(NSyellowLed,OUTPUT);//Set North/South yellowledPin as output 
  pinMode(NSredLed,OUTPUT);//Set North/South ledPin red as output  
  pinMode(WEgreenLed, OUTPUT);//Set West/East green ledPin as output
  pinMode(WEyellowLed, OUTPUT); //Set WE yellow ledPin as output
  pinMode(WEredLed, OUTPUT); //Set WE red ledPin as Outpu
}  //end of setup

void loop() 
{
   digitalWrite(NSredLed,HIGH); //Set N/S red LED to high
   digitalWrite(WEredLed,HIGH);  //Set W/E red LED to high
   delay(2000); //Delay 2 second 
   digitalWrite(WEredLed,LOW); //Set W/E red LED to low 
   
   /*West-East directions start to go from this point*/
   digitalWrite(WEgreenLed,HIGH); //Set W/E green LED to high  
   delay(10000); //Wait 10 second 
   digitalWrite(WEgreenLed,LOW); //Set W/E green LED to low 
   
   digitalWrite(buzzer,HIGH); //Start making a sound to warn the light swich
   delay(10); //Wait 10ms 
   digitalWrite(buzzer,LOW); //Stop making a sound
   delay(400); //Wait 400ms
   digitalWrite(buzzer,HIGH); //Start making a sound
   delay(10); //Wait 10ms 
   digitalWrite(buzzer,LOW); //Stop making a sound
   
   digitalWrite(WEyellowLed,HIGH); //Set W/E yellow LED to high  
   delay(2000); //Delay 2 second 
   digitalWrite(WEyellowLed,LOW); //Set W/E yellow LED to low 
      
   digitalWrite(WEredLed,HIGH); //Set W/E red LED to high  
   delay(2000); //Delay 2 second 
   digitalWrite(NSredLed,LOW); //Set N/S red LED to low   
   
   /*North-South directions start to go from this point*/
   digitalWrite(NSgreenLed,HIGH); //Set N/S green LED to high  
   delay(10000); //Delay 10 second 
   digitalWrite(NSgreenLed,LOW); //Set N/S green LED to low 
   
   digitalWrite(buzzer,HIGH); //Start making a sound to warn the light switch
   delay(10); //Wait 10ms 
   digitalWrite(buzzer,LOW); //Stop making a sound
   delay(400); //Wait 400ms
   digitalWrite(buzzer,HIGH); //Start making a sound
   delay(10); //Wait 10ms 
   digitalWrite(buzzer,LOW); //Stop making a sound
   
   digitalWrite(NSyellowLed,HIGH); //Set N/S yellow LED to high  
   delay(2000); //Delay 2 second 
   digitalWrite(NSyellowLed,LOW); //Set N/S yellow LED to low 
   
}//end of loop

