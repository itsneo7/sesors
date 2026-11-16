#include <Wire.h>
#define AS5600_ADDR 0x36  
#define ANGLE_REG  0x0E   // starting register for processed angle
uint16_t prev_angle;
void setup() 
{
  Serial.begin(9600);
  Wire.begin(); 
}
uint16_t readAngle() 
{
  // Read ANGLE high byte (0x0E)
  Wire.beginTransmission(AS5600_ADDR);
  Wire.write(0x0E);
  Wire.endTransmission();
  Wire.requestFrom(AS5600_ADDR, 1);
  byte highByte = Wire.read();

  // Read ANGLE low byte (0x0F)
  Wire.beginTransmission(AS5600_ADDR);
  Wire.write(0x0F);
  Wire.endTransmission();
  Wire.requestFrom(AS5600_ADDR, 1);
  byte lowByte = Wire.read();

  // Combine into 12-bit angle
  uint16_t angle = ((highByte << 8) | lowByte) & 0x0FFF;
  return angle;
}

void loop() 
{
  uint16_t rawAngle = readAngle();
  float degrees = (rawAngle * 360.0) / 4096.0; // convert to degrees
  Serial.print(prev_angle);
  Serial.print("  ");
  Serial.print(rawAngle);
  Serial.print("  ");
  Serial.println(degrees);
  delay(200);
}
