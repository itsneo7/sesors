#include <TFMPlus.h>

// Initialize the TFMPlus object
TFMPlus tfmP;

void setup() {
  // Serial Monitor for debugging
  Serial.begin(115200);        

  // Initialize Hardware Serial 1 (Pins 19 RX, 18 TX) for the sensor
  Serial1.begin(115200);         

  // Pass the Hardware Serial 1 port to the TFmini Plus library
  tfmP.begin(&Serial1);

  Serial.println("TFmini Plus Arduino Mega setup complete...");
}

void loop() {
  int16_t dist = 0;
  int16_t flux = 0;
  int16_t temp = 0;

  // Check if data is available from the sensor
  if (tfmP.getData(dist, flux, temp)) {
    Serial.print("Distance: ");
    Serial.print(dist);
    Serial.print(" cm | Strength: ");
    Serial.print(flux);
    Serial.print(" | Temp: ");
    Serial.print(temp / 100.0);
    Serial.println(" °C");
  }
  
  delay(100);
}
