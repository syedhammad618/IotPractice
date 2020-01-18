int timing;
int ledpin=10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()){
     timing=Serial.parseInt();
     for(int i=0;i<=255;i+=5){
      analogWrite(ledpin,i);
      delay(timing);
      }
     for(int i=255;i>=0;i-=5){
      analogWrite(ledpin,i);
      delay(timing);
      } 
    }
}
