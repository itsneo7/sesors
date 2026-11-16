// #include <SoftwareSerial.h>
#include <TFMPlus.h>
// SoftwareSerial mySerial(10, 11);


TFMPlus tfmP;

void setup() {
  Serial.begin(115200);        // TFmini Plus default baud

  Serial2.begin(115200);         // TFmini Plus default baud

  // Initialize TFmini Plus
  tfmP.begin(&Serial2);

  Serial2.println("TFmini Plus started...");
}

void loop() {
  // Distance (cm), Strength, and Temperature (°C x100)
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
  else 
  {
    Serial.println("TFmini Plus: no data");
  }

  delay(100);
}
