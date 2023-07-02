#include <Arduino_LSM9DS1.h>

void setup() {
  // Se inicializa el puerto serial
  Serial.begin(9600);
  while (!Serial);
  
  if (!IMU.begin()) {
    Serial.println("Fallo al iniciar el giroscopio!");
    while (1);
  }
  
}
int prueba = 0;
void loop() {
  float x, y, z;

  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(x, y, z);
    if (prueba < 2000) {
      Serial.print(prueba);
      Serial.print('\t');
      Serial.print(x);
      Serial.print('\t');
      Serial.print(y);
      Serial.print('\t');
      Serial.println(z);
      prueba = prueba + 1;
    }
  }
}

