#include <LiquidCrystal.h> 
LiquidCrystal LCD(10, 9, 5, 4, 3, 2);   
int myCounter=0;  
int trigPin=13;
int echoPin=12;
float Time;
float speedOfSound=776.5;
float Distance;

void setup() {
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 Serial.begin(9600);
LCD.begin(16,2); 
//LCD.setCursor(0,0);  
//LCD.print("Target Distance:"); 
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  Time=pulseIn(echoPin,HIGH);
  
  Time=Time/1000000.;
  Time=Time/3600.;
  
  Distance=speedOfSound*Time;
  Distance=Distance/2;
  Distance=Distance*63360*2.54;
  
  Serial.println(Distance);
  if(Distance>22 && Distance<44)
  { 
    LCD.setCursor(0,0);  
    LCD.print("Target Distance:"); 
    LCD.setCursor(0,1);
    LCD.print( Distance); 
    LCD.print(" CM");  
    delay(250);
    }
  else{
    LCD.setCursor(0,0);
    LCD.print("OUT OF RANGE       ");
    LCD.setCursor(0,1);
    LCD.print("                ");
    } 

  }
  
