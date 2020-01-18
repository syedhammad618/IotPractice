#include<Wire.h>
const int MPU6050_addr=0x68;
int16_t AccX,AccY,AccZ,Temp,GyroX,GyroY,GyroZ;
float roll,pitch,rollF,pitchF=0;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);
  // AccX=Wire.read()<<8|Wire.read();
  // AccY=Wire.read()<<8|Wire.read();
  // AccZ=Wire.read()<<8|Wire.read();
  // Temp=Wire.read()<<8|Wire.read();
  GyroX=Wire.read()<<8|Wire.read();
  GyroY=Wire.read()<<8|Wire.read();
  GyroZ=Wire.read()<<8|Wire.read();
  // Serial.print("AccX = "); Serial.print(AccX);
  // Serial.print(" || AccY = "); Serial.print(AccY);
  // Serial.print(" || AccZ = "); Serial.println(AccZ);
  // Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
  Serial.print(" || GyroX = "); Serial.print(GyroX/1023);
  Serial.print(" || GyroY = "); Serial.print(GyroY/1023);
  Serial.print(" || GyroZ = "); Serial.println(GyroZ/1023);
  // delay(600);
  // Calculate Roll and Pitch (rotation around X-axis, rotation around Y-axis)
  // roll = atan(GyroY / sqrt(pow(GyroX, 2) + pow(GyroZ, 2))) * 180 / PI;
  // pitch = atan(-1 * GyroX / sqrt(pow(GyroY, 2) + pow(GyroZ, 2))) * 180 / PI;
  // // Low-pass filter
  // rollF = 0.94 * rollF + 0.06 * roll;
  // pitchF = 0.94 * pitchF + 0.06 * pitch;
  // Serial.print(rollF);
  // Serial.print("/");
  // Serial.println(pitchF);
}
