#include <TFMPlus.h>

#define RXD2 16
#define TXD2 17

TFMPlus tfmP;

void setup() {
  Serial.begin(115200);        
  
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);

  tfmP.begin(&Serial2);

  Serial.println("TFmini Plus ESP32 setup complete...");
}

void loop() {
  int16_t dist = 0;
  int16_t flux = 0;
  int16_t temp = 0;

  // Check if data is available
  if (tfmP.getData(dist, flux, temp)) {
    Serial.print("Distance: ");
    Serial.print(dist);
    Serial.print(" cm | Strength: ");
    Serial.print(flux);
    Serial.print(" | Temp: ");
    Serial.print(temp / 100.0);
    Serial.println(" °C");
  }
  else {
  }

  delay(100);
}
