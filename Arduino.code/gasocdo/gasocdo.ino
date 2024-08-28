#include <Wire.h>

#define I2C_Address 0x53

#define POWER_CTL 0x2D
#define DATA_FORMAT 0x31
#define X_axis 0x32
#define Y_axis 0x34
#define Z_axis 0x36

#define Range_2g 0
#define Range_4g 1
#define Range_8g 2
#define Range_16g 3

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Init_ADXL345(Range_2g);
}

void loop() {
  Serial.print("X: ");
  Serial.print(Read_Axis(X_axis));
  Serial.print("  Y: ");
  Serial.print(Read_Axis(Y_axis));
  Serial.print("  Z: ");
  Serial.print(Read_Axis(Z_axis));
  Serial.println();

  delay(1000);
}

int Read_Axis(byte a){
  int data;

  Wire.beginTransmission(I2C_Address);
  Wire.write(a);
  Wire.endTransmission();

  Wire.beginTransmission(I2C_Address);
  Wire.requestFrom(I2C_Address, 2);

  if(Wire.available()){
    data = (int)Wire.read();
    data = data | (Wire.read() << 8);
  }
  else {
    data = 0;
  }

  Wire.endTransmission();
  return data;
}

void Init_ADXL345(byte r){
  Wire.beginTransmission(I2C_Address);

  Wire.write(DATA_FORMAT);
  Wire.write(r);
  Wire.endTransmission();

  Wire.beginTransmission(I2C_Address);
  Wire.write(POWER_CTL);
  Wire.write(0x08);
  Wire.endTransmission();
}