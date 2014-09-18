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
  pinMode(NSgreenLed,OUTPUT);//Set North/South ledPin as output 
  pinMode(NSyellowLed,OUTPUT);//Set North/South ledPin as output 
  pinMode(NSredLed,OUTPUT);//Set North/South ledPin as output  
  pinMode(WEgreenLed, OUTPUT);//Set West/East ledPin as output
  pinMode(WEyellowLed, OUTPUT);
  pinMode(WEredLed, OUTPUT);
}  //end of setup

void loop() 
{
   digitalWrite(NSredLed,HIGH); //Set N/S red LED to high
   digitalWrite(WEredLed,HIGH);  
   delay(2000); //Delay 8 second 
   digitalWrite(WEredLed,LOW); //Set N/S red LED to low 
   
   digitalWrite(WEgreenLed,HIGH); //Set W/E red LED to high  
   delay(10000); //Wait 1 second 
   digitalWrite(WEgreenLed,LOW); //Set W/E red LED to low 
   
   digitalWrite(buzzer,HIGH); //Start making a sound
   delay(10); //Wait 1ms 
   digitalWrite(buzzer,LOW); //Stop making a sound
   delay(400);
   digitalWrite(buzzer,HIGH); //Start making a sound
   delay(10); //Wait 1ms 
   digitalWrite(buzzer,LOW); //Stop making a sound
   
   digitalWrite(WEyellowLed,HIGH); //Set W/Egreen LED to high  
   delay(2000); //Delay 5 second 
   digitalWrite(WEyellowLed,LOW); //Set W/E green LED to low 
      
   digitalWrite(WEredLed,HIGH); //Set W/Eyellow LED to high  
   delay(2000); //Delay 1 second 
   digitalWrite(NSredLed,LOW); //Set W/Eyellow LED to low   
   
   digitalWrite(NSgreenLed,HIGH); //Set W/E red LED to high  
   delay(10000); //Delay 7 second 
   digitalWrite(NSgreenLed,LOW); //Set W/E red LED to low 
   
   digitalWrite(buzzer,HIGH); //Start making a sound
   delay(10); //Wait 1ms 
   digitalWrite(buzzer,LOW); //Stop making a sound
   delay(400);
   digitalWrite(buzzer,HIGH); //Start making a sound
   delay(10); //Wait 1ms 
   digitalWrite(buzzer,LOW); //Stop making a sound
   
   digitalWrite(NSyellowLed,HIGH); //Set N/Sgreen LED to high  
   delay(2000); //Delay 5 second 
   digitalWrite(NSyellowLed,LOW); //Set N/S green LED to low 
   
}//end of loop

