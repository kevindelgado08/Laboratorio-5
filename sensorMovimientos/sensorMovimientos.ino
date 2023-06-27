#include <Arduino_LSM9DS1.h>

void setup() {
  // Se inicializa el puerto serial
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Inicio de Conexión");

  if (!IMU.begin()) {
    Serial.println("Fallo al iniciar el giroscopio!");
    while (1);
  }
  Serial.print("Rango de Pruebas del Giroscopio = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Giroscopio en grados/segundos");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;

  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
  }
}

