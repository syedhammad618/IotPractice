 int led = 13;
 int sensorInput=8;
 int val;
void setup() {
pinMode(led,OUTPUT);
pinMode(sensorInput,INPUT);
Serial.begin(9600);
 
}

void loop() {
 val=digitalRead(sensorInput);
 Serial.println(val);
 if(val==HIGH){
  digitalWrite(led,HIGH);
  Serial.println("motion detected");
   
  
  }
  if(val==LOW){
    digitalWrite(led,LOW);
  
  }
 delay(10);
 

}
